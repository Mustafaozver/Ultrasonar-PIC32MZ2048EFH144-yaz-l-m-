#include "app.h"


APP_DATA appData;

/* Receive data buffer */
uint8_t  transmitDataBuffer[512] APP_MAKE_BUFFER_DMA_READY;

uint8_t  receiveDataBuffer[512] APP_MAKE_BUFFER_DMA_READY;

/* The endpoint size is 64 for FS and 512 for HS */
uint16_t endpointSize;

bool usb_write=false;

uint16_t usb_data_count;
bool single_packet=true;

uint8_t* packet_data;
uint8_t* adc_data_adrr=(uint8_t*)buffer_addr0;

uint8_t temp_packet_count=0;
uint8_t packet_count=0;

void APP_USBDeviceEventHandler(USB_DEVICE_EVENT event, void * eventData, uintptr_t context) {
 uint8_t * configurationValue;
 USB_SETUP_PACKET * setupPacket;
 switch(event) {
  case USB_DEVICE_EVENT_RESET:
  case USB_DEVICE_EVENT_DECONFIGURED:
   MLed2On();
   MLed1On();
   appData.deviceIsConfigured = false;
   break;
  case USB_DEVICE_EVENT_CONFIGURED:
   configurationValue = (uint8_t *)eventData;
   if(*configurationValue == 1) {
    MLed1Off();
    MLed2Off();
    appData.deviceIsConfigured = true;
   }
   break;
  case USB_DEVICE_EVENT_SUSPENDED:
   MLed1Off();
   MLed2On();
   break;
  case USB_DEVICE_EVENT_POWER_DETECTED:
   USB_DEVICE_Attach(appData.usbDevHandle);
   break;
  case USB_DEVICE_EVENT_POWER_REMOVED:
   USB_DEVICE_Detach (appData.usbDevHandle);
   break;
  case USB_DEVICE_EVENT_CONTROL_TRANSFER_SETUP_REQUEST:
   setupPacket = (USB_SETUP_PACKET *)eventData;
   if(setupPacket->bRequest == USB_REQUEST_SET_INTERFACE) {
    USB_DEVICE_ControlStatus(appData.usbDevHandle,USB_DEVICE_CONTROL_STATUS_OK);
   } else if(setupPacket->bRequest == USB_REQUEST_GET_INTERFACE) {
    USB_DEVICE_ControlSend(appData.usbDevHandle, &appData.altSetting, 1);
   } else {
    USB_DEVICE_ControlStatus(appData.usbDevHandle, USB_DEVICE_CONTROL_STATUS_ERROR);
   }
   break;
  case USB_DEVICE_EVENT_ENDPOINT_READ_COMPLETE:
   appData.epDataReadPending = false;
   break;
  case USB_DEVICE_EVENT_ENDPOINT_WRITE_COMPLETE:
   appData.epDataWritePending = false;
   break;
  case USB_DEVICE_EVENT_RESUMED:
  case USB_DEVICE_EVENT_ERROR:
  default:break;
 }
}

void APP_Initialize (void) {
 /* Place the App state machine in its initial state. */
 appData.state = APP_STATE_INIT;
 appData.usbDevHandle = USB_DEVICE_HANDLE_INVALID;
 appData.deviceIsConfigured = false;
 appData.endpointRx = 0x01;
 appData.endpointTx = 0x81;
 appData.epDataReadPending = false;
 appData.epDataWritePending = false;
 appData.altSetting = 0;
}


void usb_packet_send(uint16_t adet, uint8_t* packet_data1) {
 usb_write=true;
 usb_data_count=adet;
 if(adet<450) {
  single_packet=true;
  packet_data=packet_data1;
  transmitDataBuffer[0]=0xff;
  transmitDataBuffer[1]=usb_data_count/256;
  transmitDataBuffer[2]=usb_data_count%256;
  memcpy(transmitDataBuffer+3, packet_data, 503);
 } else {
  single_packet=false;
  temp_packet_count=0;
  packet_count=adet/500;
  transmitDataBuffer[0]=0xff;
  transmitDataBuffer[1]=usb_data_count/256;
  transmitDataBuffer[2]=usb_data_count%256;
  transmitDataBuffer[3]=0x20;
  transmitDataBuffer[4]=packet_count;
 }
}

void APP_Tasks (void) {
 switch(appData.state) {
  case APP_STATE_INIT:
   appData.usbDevHandle = USB_DEVICE_Open( USB_DEVICE_INDEX_0,
   DRV_IO_INTENT_READWRITE );
   if(appData.usbDevHandle != USB_DEVICE_HANDLE_INVALID) {
    USB_DEVICE_EventHandlerSet(appData.usbDevHandle,  APP_USBDeviceEventHandler, 0);
    appData.state = APP_STATE_WAIT_FOR_CONFIGURATION;
   } else { /* The Device Layer is not ready to be opened. We should try again later. */
   }
   break;
  case APP_STATE_WAIT_FOR_CONFIGURATION:
   if(appData.deviceIsConfigured == true) {
    if (USB_DEVICE_ActiveSpeedGet(appData.usbDevHandle) == USB_SPEED_FULL) {
     endpointSize = 64;
    } else if (USB_DEVICE_ActiveSpeedGet(appData.usbDevHandle) == USB_SPEED_HIGH) {
     endpointSize = 512;
    }
    if (USB_DEVICE_EndpointIsEnabled(appData.usbDevHandle, appData.endpointRx) == false ) {
     USB_DEVICE_EndpointEnable(appData.usbDevHandle, 0, appData.endpointRx,USB_TRANSFER_TYPE_BULK, endpointSize);
    }
    if (USB_DEVICE_EndpointIsEnabled(appData.usbDevHandle, appData.endpointTx) == false) {
     USB_DEVICE_EndpointEnable(appData.usbDevHandle, 0, appData.endpointTx,USB_TRANSFER_TYPE_BULK, endpointSize);
    }
    appData.epDataReadPending = true;
    USB_DEVICE_EndpointRead(appData.usbDevHandle, &appData.readTranferHandle,appData.endpointRx, &receiveDataBuffer[0],512 );
    appData.state = APP_STATE_MAIN_TASK;
   }
   break;
  case APP_STATE_MAIN_TASK:
   if(!appData.deviceIsConfigured) {
    appData.state = APP_STATE_WAIT_FOR_CONFIGURATION;
    USB_DEVICE_EndpointDisable(appData.usbDevHandle, appData.endpointRx);
    USB_DEVICE_EndpointDisable(appData.usbDevHandle, appData.endpointTx);
    appData.epDataReadPending = false;
    appData.epDataWritePending = false;
   } else {
    if ((appData.epDataWritePending == false)&&(usb_write==true)) {
     appData.epDataWritePending = true;
     USB_DEVICE_EndpointWrite ( appData.usbDevHandle, &appData.writeTranferHandle,appData.endpointTx, &transmitDataBuffer[0],512,USB_DEVICE_TRANSFER_FLAGS_MORE_DATA_PENDING);
     if(single_packet==true) {
      usb_write=false;
     } else {
      if(temp_packet_count==0) {
       transmitDataBuffer[0]=0xff;
       transmitDataBuffer[1]=usb_data_count/256;
       transmitDataBuffer[2]=usb_data_count%256;
       memcpy(transmitDataBuffer+3, packet_data, 32);
       memcpy(transmitDataBuffer+50, adc_data_adrr, 450);
      } else {
       memcpy(transmitDataBuffer, adc_data_adrr+temp_packet_count*500-50, 500);
      }
      if(temp_packet_count==packet_count+1) {
       usb_write=false;
      }
      temp_packet_count++;
     }
    }
    if (appData.epDataReadPending == false) {
     app1Data.state = USB_RECEIVE;
     appData.epDataReadPending = true ;
     USB_DEVICE_EndpointRead ( appData.usbDevHandle, &appData.readTranferHandle,appData.endpointRx, &receiveDataBuffer[0], 512 );
    }
   }
   break;
  case APP_STATE_ERROR:
  default:break;
 }
}