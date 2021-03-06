/*******************************************************************************
  DMA System Service Interface Declarations for Static Single Instance System Service

  Company:
    Microchip Technology Inc.

  File Name:
    drv_dma_static.h

  Summary:
    DMA driver interface declarations for the static single instance System Service.

  Description:
    The DMA System Service provides a simple interface to manage the DMA
    modules on Microchip microcontrollers. This file defines the interface
    Declarations for the DMA.
    
  Remarks:
    Static interfaces incorporate the System Service instance number within the names
    of the routines, eliminating the need for an object ID or object handle.
    
    Static single-open interfaces also eliminate the need for the open handle.
*******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2013 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED AS IS WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
*******************************************************************************/
//DOM-IGNORE-END


#ifndef _DRV_DMA_STATIC_H
#define _DRV_DMA_STATIC_H

#include "system/dma/sys_dma.h"
#include "peripheral/int/plib_int.h"



// *****************************************************************************
// *****************************************************************************
// Section: Interface Headers for Instance for the static System Service
// *****************************************************************************
// *****************************************************************************

void SYS_DMA_Channel0TransferAdd(void);

void SYS_DMA_Channel0Enable(void);

void SYS_DMA_Channel0Setup(SYS_DMA_CHANNEL_OP_MODE modeEnable);

void SYS_DMA_Channel0ForceStart(void);

bool SYS_DMA_Channel0IsBusy(void);
void SYS_DMA_Channel0ForceAbort(void);
void SYS_DMA_Channel0ForceStart(void);
void SYS_DMA_Channel0Disable(void);
void SYS_DMA_Suspend(void);
void SYS_DMA_Resume(void);
bool SYS_DMA_IsBusy(void);
uint32_t SYS_DMA_Channel0GetCRC(void);
void SYS_DMA_Channel0SetCRC(SYS_DMA_CHANNEL_OPERATION_MODE_CRC crc);
void SYS_DMA_Channel0SetupMatchAbortMode( uint16_t pattern,
                                         DMA_PATTERN_LENGTH length,
                                         SYS_DMA_CHANNEL_IGNORE_MATCH ignore,
                                         uint8_t ignorePattern );
__attribute__((weak)) void SYS_DMA_Tasks0(void);
uint8_t ekran_kontrolu_var(void);
void pixel_yaz(uint16_t x, uint16_t y, uint16_t renk);
uint16_t pixel_oku(uint16_t x, uint16_t y);
void pixel_yaz_dogrula(uint16_t x, uint16_t y, uint16_t renk);
void pixel_sil(uint16_t x, uint16_t y);
void SYS_DMA_Channel1TransferAdd(void);

void SYS_DMA_Channel1Enable(void);

void SYS_DMA_Channel1Setup(SYS_DMA_CHANNEL_OP_MODE modeEnable);

void SYS_DMA_Channel1ForceStart(void);


bool SYS_DMA_Channel1IsBusy(void);
void SYS_DMA_Channel1ForceAbort(void);
void SYS_DMA_Channel1ForceStart(void);
void SYS_DMA_Channel1Disable(void);
void SYS_DMA_Suspend(void);
void SYS_DMA_Resume(void);
bool SYS_DMA_IsBusy(void);
uint32_t SYS_DMA_Channel1GetCRC(void);
void SYS_DMA_Channel1SetCRC(SYS_DMA_CHANNEL_OPERATION_MODE_CRC crc);
void SYS_DMA_Channel1SetupMatchAbortMode( uint16_t pattern,
                                         DMA_PATTERN_LENGTH length,
                                         SYS_DMA_CHANNEL_IGNORE_MATCH ignore,
                                         uint8_t ignorePattern );
__attribute__((weak)) void SYS_DMA_Tasks1(void);
void SYS_DMA_Channel2TransferAdd(void);

void SYS_DMA_Channel2Enable(void);

void SYS_DMA_Channel2Setup(SYS_DMA_CHANNEL_OP_MODE modeEnable);

void SYS_DMA_Channel2ForceStart(void);


bool SYS_DMA_Channel2IsBusy(void);
void SYS_DMA_Channel2ForceAbort(void);
void SYS_DMA_Channel2ForceStart(void);
void SYS_DMA_Channel2Disable(void);
void SYS_DMA_Suspend(void);
void SYS_DMA_Resume(void);
bool SYS_DMA_IsBusy(void);
uint32_t SYS_DMA_Channel2GetCRC(void);
void SYS_DMA_Channel2SetCRC(SYS_DMA_CHANNEL_OPERATION_MODE_CRC crc);
void SYS_DMA_Channel2SetupMatchAbortMode( uint16_t pattern,
                                         DMA_PATTERN_LENGTH length,
                                         SYS_DMA_CHANNEL_IGNORE_MATCH ignore,
                                         uint8_t ignorePattern );
__attribute__((weak)) void SYS_DMA_Tasks2(void);
void SYS_DMA_Channel3TransferAdd(void);

void SYS_DMA_Channel3Enable(void);

void SYS_DMA_Channel3Setup(SYS_DMA_CHANNEL_OP_MODE modeEnable);

void SYS_DMA_Channel3ForceStart(void);


bool SYS_DMA_Channel3IsBusy(void);
void SYS_DMA_Channel3ForceAbort(void);
void SYS_DMA_Channel3ForceStart(void);
void SYS_DMA_Channel3Disable(void);
void SYS_DMA_Suspend(void);
void SYS_DMA_Resume(void);
bool SYS_DMA_IsBusy(void);
uint32_t SYS_DMA_Channel3GetCRC(void);
void SYS_DMA_Channel3SetCRC(SYS_DMA_CHANNEL_OPERATION_MODE_CRC crc);
void SYS_DMA_Channel3SetupMatchAbortMode( uint16_t pattern,
                                         DMA_PATTERN_LENGTH length,
                                         SYS_DMA_CHANNEL_IGNORE_MATCH ignore,
                                         uint8_t ignorePattern );
__attribute__((weak)) void SYS_DMA_Tasks3(void);

#endif // #ifndef _DRV_DMA_STATIC_H

/*******************************************************************************
 End of File
*/
