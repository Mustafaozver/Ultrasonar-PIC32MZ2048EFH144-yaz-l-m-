#include <xc.h>
#include <sys/attribs.h>
#include "app.h"
#include "app1.h"
#include "system_definitions.h"
#include "ortaksistemler_1.h"

void __ISR(_EXTERNAL_3_VECTOR, IPL1AUTO) _IntHandlerExternalInterruptInstance0(void) {
 PLIB_INT_SourceDisable(INT_ID_0, INT_SOURCE_EXTERNAL_3);
 PLIB_INT_SourceFlagClear(INT_ID_0, INT_SOURCE_EXTERNAL_3);
 PLIB_EBI_MemoryTimingConfigSet(EBI_ID_0, 0, 0, 0, 4, 0, 0, 2);
 PLIB_DMA_StartTransferSet(DMA_ID_0, DMA_CHANNEL_0);
}
void __ISR(_EXTERNAL_2_VECTOR, IPL1AUTO) _IntHandlerExternalInterruptInstance2(void) {
 SYS_DMA_Channel3ForceAbort();
 SYS_DMA_Channel1Enable();
 PLIB_INT_SourceFlagClear(INT_ID_0, INT_SOURCE_EXTERNAL_2);
}

void __ISR(_EXTERNAL_4_VECTOR, IPL1AUTO) _IntHandlerExternalInterruptInstance3(void) {
 int i = 0;
 lcd_clear();
 lcd_goto(0,0);
 lcd_puts("Shuting Down");
 while(1) {
  if(PLIB_PORTS_PinGet(PORTS_ID_0, PORT_CHANNEL_F, PORTS_BIT_POS_5)==0) {delay_ms1(250); break;}
  delay_ms1(50);
  i++;
  if(i==50) {
   MLed1Toggle();
   MLed2Toggle();
   lcd_clear(); 
   lcd_goto(0,0);
   lcd_puts("Bye Bye") ;
   delay_ms1(1500);
   PWSWENOff();
   break;
  }
 }
 lcd_clear(); 
 PLIB_INT_SourceFlagClear(INT_ID_0, INT_SOURCE_EXTERNAL_4);
}

   
void __ISR(_TIMER_1_VECTOR, ipl1AUTO) IntHandlerDrvTmrInstance0(void) {
 DRV_TMR_Tasks(sysObj.drvTmr0);
}

void __ISR(_DMA0_VECTOR, ipl1AUTO) _IntHandlerSysDmaCh0(void) {
 SYS_DMA_Tasks0();
}

void __ISR(_DMA1_VECTOR, ipl1AUTO) _IntHandlerSysDmaCh1(void) {
 SYS_DMA_Tasks1();
}

void __ISR(_DMA2_VECTOR, ipl1AUTO) _IntHandlerSysDmaCh2(void) {
 SYS_DMA_Tasks2(); // ekran
}

void __ISR(_DMA3_VECTOR, ipl1AUTO) _IntHandlerSysDmaCh3(void) {
 SYS_DMA_Tasks3();
}

void __ISR(_USB_VECTOR, ipl4AUTO) _IntHandlerUSBInstance0(void) {
 DRV_USBHS_Tasks_ISR(sysObj.drvUSBObject);
}

void __ISR ( _USB_DMA_VECTOR,ipl4AUTO) _IntHandlerUSBInstance0_USBDMA ( void ) {
 DRV_USBHS_Tasks_ISR_USBDMA(sysObj.drvUSBObject);
}