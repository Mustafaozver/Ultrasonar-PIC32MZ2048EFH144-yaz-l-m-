/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef PC_PAKETLERI_H
#define	PC_PAKETLERI_H

#include <xc.h> // include processor files - each processor file is guarded.  

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include "system_config.h"
#include "system_definitions.h"
// TODO Insert appropriate #include <>

// TODO Insert C++ class definitions if appropriate

// TODO Insert declarations

typedef enum
{

    Tekrargonder=0,
    LedIslemi,
    IslemButton,
    dummy2,
    AdcDataIslemi,
    SinyalYakalamaAyarlari, //5
    BootIslemi,
    BootBasla,
    AdcOrnekGonder,
    FrekansSec,
    AdcTestZaman, //10
    AdcGainSet,
    DataVar,
    channel_sec,
    channel_bit_gain,
    Fpga_read_test, //15
    ultrasonar_deneme_, // Geçici
    enkoder_kurulum,
    denetim_mesaji
} Pc_Pack_alinan_konu;



typedef  struct
{
    union
    {
        struct
        {
        uint8_t konu;
        uint8_t konu2;
        uint16_t BufferSize;
        uint16_t OrnekBaslangic;
        uint16_t OrnekBitis;
        uint8_t row_data_set;
        uint8_t rectifier_set;
        uint8_t trigger_set;
        uint8_t clock_set;
        uint8_t chan_set;
        uint8_t zarf_Katsayi;
        uint8_t prf;
        uint8_t firstt;
        uint8_t triglevel;
        uint8_t lnp_gain;
        uint8_t vga_gain;
        uint8_t darbe_frekansi;
        uint8_t darbe_sayisi;
        uint8_t pulse_output_channel;
        uint8_t HV_val;
        uint8_t Read_channel_sellect;
        uint8_t channel_bit_gain;
        uint8_t Ultrasonik_teknik;
        };
        uint8_t full1[32];
    };
			
}ADC_Settings;
        
typedef struct 
{
	union
	{
        struct
		{
      		uint8_t konu;
			uint8_t val;

		}led1;
        
		struct
		{
			uint8_t konu;
            uint8_t konu2;
			uint16_t BufferSize;
			uint16_t OrnekBaslangic;
			uint16_t OrnekBitis;
			uint8_t row_data_set;
			uint8_t rectifier_set;
            uint8_t trigger_set;
            uint8_t clock_set;
            uint8_t chan_set;
            uint8_t zarf_Katsayi;
            uint8_t prf;
            uint8_t firstt;
            uint8_t triglevel;
            uint8_t lnp_gain;
            uint8_t vga_gain;
            uint8_t darbe_frekansi;
            uint8_t darbe_sayisi;
            uint8_t pulse_output_channel;
            uint8_t HV_val;
            uint8_t Read_channel_sel;
    
			
		}ADC_config;
        

        struct
		{
			uint8_t konu;
			uint8_t val;

		}frekans_sec;
        
        struct
		{
			uint8_t konu;
			uint8_t vca_gain;
            uint8_t lnp_gain;
            
		}Adc_gain_set;
        
         struct
		{
			uint8_t konu;
			uint8_t gain;
		}
         channel_bit_gainn;
        
        struct
		{
			uint8_t konu;
			uint8_t val;
            uint8_t val1;
            uint8_t val2;

		}Genel;

		uint8_t Butun_paket[64];
	};
}PC_RX_Paketi;


typedef struct 
{
	union
	{
   
		struct
		{
			uint8_t konu;
            uint8_t konu2;
			uint16_t BufferSize;
			uint16_t OrnekBaslangic;
			uint16_t OrnekBitis;
			uint8_t row_data_set;
			uint8_t rectifier_set;
            uint8_t trigger_set;
            uint8_t clock_set;
            uint8_t chan_set;
            uint8_t zarf_Katsayi;
            uint8_t prf;
            uint8_t firstt;
            uint8_t triglevel;
            uint8_t lnp_gain;
            uint8_t vga_gain;
            uint8_t dummyy;
            
            uint8_t dummy1[26];
            uint8_t ADC_data[500];
			
		}ADC_config;
        
        struct
		{
			uint8_t konu;
			uint8_t val0;
            uint8_t val1;
            uint8_t val2;
            uint8_t val3;
		}Genel;
        

        
		uint8_t Butun_paket[5000];
	};
}PC_TX_Paketi;


extern PC_TX_Paketi PC_TX_paketi;
extern PC_RX_Paketi PC_paketi;
extern ADC_Settings ADC_settings;

// Comment a function and leverage automatic documentation with slash star star
/**
    <p><b>Function prototype:</b></p>
  
    <p><b>Summary:</b></p>

    <p><b>Description:</b></p>

    <p><b>Precondition:</b></p>

    <p><b>Parameters:</b></p>

    <p><b>Returns:</b></p>

    <p><b>Example:</b></p>
    <code>
 
    </code>

    <p><b>Remarks:</b></p>
 */
inline uint8_t PC_Pack_paket_konusu();


// TODO Insert declarations or function prototypes (right here) to leverage 
// live documentation

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */

