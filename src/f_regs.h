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
#ifndef _F_REGS_H
#define _F_REGS_H


#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include "system_config.h"
#include "system_definitions.h"
// TODO Insert appropriate #include <>

// TODO Insert C++ class definitions if appropriate

// TODO Insert declarations


#define SRAM_ADDR_CS0  0xE0000000
#define FPGA_FIFO      0xE0000018

typedef enum
{
    /* USART Enable State */ // Sisteme giden verilerin s?ras?
    addr_cntr_reg, // 0000 // fifo
    addr_cntr2_reg, // 0001
    addr_pulse_cntrl1, // 0010
    addr_pulse_cntrl2,
    add_ornekleme_cntrol,
    counter_x, // 5
    counter_y,
    counter_z,
    fpga_islem
} F_reg_addrs;

typedef enum
{
    /* USART Enable State */ // Clk de?erleri numaraland?r?c?s?
    clk100mhz,
    clk50mhz,
    clk25mhz,
    clk12mhz,
    clk6mhz,
    clk3mhz,
    clk1mhz,
    adcdurdur,
} ADC_clk;

typedef enum
{
    lnpgain_3db,
    lnpgain_12db,
    lnpgain_18db,
    lnpgain_22db,
    lnp_pwrdwn,
    pwr_dwn_all,
            
}Lnp_Gain;

typedef struct 
{
	union
	{
		struct
		{
			uint16_t aclr:1;
			uint16_t acq_begin:1;
			uint16_t buffer_size:14;
			uint16_t acq_finish:1; // hatal?
			uint16_t wfull:1;
			uint16_t empty1:1;
			
		}bits;

		uint16_t cntrl_val;
	};
}f_contr_reg;

typedef struct 
{
	union
	{
		struct
		{
			uint16_t clkset:3;
            uint16_t Read_channel_sel:1;  //0--->channel a  1----> channel b
            uint16_t channel_bit_gain:2;
            uint16_t VGA_HL:1;
            uint16_t VCA_PDL:1;
            uint16_t VCA_insel:1;
            uint16_t VCA_PDV:1;
            
     
			uint16_t wrcount:8;
		}bits;

		uint16_t cntrl_val;
	};
}f_contr2_reg;

typedef struct 
{
	union
	{
		struct
		{
			uint8_t darbe_frekansi;
            uint8_t darbe_sayisi;

		}bits;

		uint16_t cntrl_val;
	};
}f_Pulser_cntrl1;

typedef struct 
{
	union
	{
		struct
		{
			uint16_t prf_dvider:8;
            uint16_t out_sel:1;


			//uint16_t wrcount:8;
		}bits;

		uint16_t cntrl_val;
	};
}f_Pulser_cntrl2;


typedef struct 
{
	union
	{
		struct
		{
			uint16_t single_pulsed_sample_get:1;
            uint16_t pulser_enable_pe:1;


			//uint16_t wrcount:8;
		}bits;

		uint16_t cntrl_val;
	};
}f_ornekleme_cntrl;



extern f_contr_reg control_reg;
extern f_contr2_reg control2_reg;
extern f_Pulser_cntrl1 Pulser_cntrl1;
extern f_ornekleme_cntrl ornekleme_cntrl;




void freg_wr(F_reg_addrs,uint16_t);

uint16_t freg_rd(F_reg_addrs);
uint16_t freg_rd_ro(F_reg_addrs);

void F_regs_fifo_rd(uint8_t* ,uint16_t);

void F_regs_Adc_clk_set(uint16_t);

void F_regs_Read_channel_sel(uint16_t);

void F_regs_Channel_bit_gain(uint16_t);

inline void F_regs_fifo_aclr();

inline void F_regs_ADC_Buffer_size_set(uint16_t);

inline void F_regs_Begin_acquisition();

inline void F_regs_LNP_gain_set(Lnp_Gain);

inline void F_regs_Pulse_cntrl1_set(uint8_t p_freq, uint8_t p_count1);

inline void F_regs_Pulse_cntrl2_set(uint8_t );

inline void F_regs_Pulsed_sample_get();

inline void F_regs_Pulsed_enable(bool);

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
#endif


