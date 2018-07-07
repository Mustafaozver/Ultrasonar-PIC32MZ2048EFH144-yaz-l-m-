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

/*******************************************************************************
  This source file has NOT been generated by the MHC
 *******************************************************************************/

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// *****************************************************************************
// *****************************************************************************
// Section: Included Files 
// *****************************************************************************
// *****************************************************************************
#include "f_regs.h"


// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************


/*
 * register �rne?i MCu da tutuldu?undan FPGA taraf?ndan bir kez kullan?lan ve silinen de?erler 
 * �rne?in �rneklemeye ba?la biti MCU da da silinmelidir.
 * 
 * alternatif olarak �nce register de?eri okunup daha sonra de?er yazma i?lemi de uygulanabilir. 
 */
f_contr_reg control_reg={};
f_contr2_reg control2_reg={};
f_Pulser_cntrl1 Pulser_cntrl1={};
f_Pulser_cntrl2 Pulser_cntrl2={};
f_ornekleme_cntrl ornekleme_cntrl={};
 

// *****************************************************************************
// *****************************************************************************
// Section: User Functions
// *****************************************************************************
// *****************************************************************************
/* 16 bit adres register numaras? x2 dir
 * reg0= adres 0000
 * reg1= adres 0002
 * reg2= adres 0004

*/



void freg_wr(F_reg_addrs reg_num, uint16_t val1)
{
    uint16_t *F_reg;
    F_reg = (uint16_t *)(SRAM_ADDR_CS0 + reg_num*2 );
    
    PLIB_EBI_MemoryTimingConfigSet(EBI_ID_0, 0, 0, 0, 5, 0, 1, 5); // ebi yaz say?sal de?erleri de?i?tir :)
      
    *F_reg = (uint16_t) val1;
 
}

uint16_t freg_rd(F_reg_addrs reg_num)
{
    uint16_t *F_reg;
    
    PLIB_EBI_MemoryTimingConfigSet(EBI_ID_0, 0, 0, 0, 4, 0, 1, 4); 
    F_reg = (uint16_t *)(SRAM_ADDR_CS0 + reg_num * 2 );
    
    return *F_reg;
}
/////////////////////////////////////////////
uint16_t freg_rd_ro(F_reg_addrs reg_num)
{
    uint16_t *F_reg;
    
    PLIB_EBI_MemoryTimingConfigSet(EBI_ID_0, 0, 0, 0, 4, 0, 1, 4); 
    F_reg = (uint16_t *)(SRAM_ADDR_CS0 + reg_num*2);
    
    return *F_reg;
}


/* ornek_sayisi her biri 16 bit olan datalardan olu?ur. bu nedenle ornek say?s?n?n
 * 2 kat? kadar 8 bitlik data olu?acakt?r. 
 
 */
void F_regs_fifo_rd(uint8_t* dest,uint16_t ornek_sayisi)
{
    uint16_t *F_reg;
    uint16_t count, val;
    
    
    F_reg = (uint16_t *)(FPGA_FIFO);
    
    PLIB_EBI_MemoryTimingConfigSet(EBI_ID_0, 0, 0, 0, 4, 0, 0, 1); 
  
    
    for(count=0;count<=ornek_sayisi;count=count+2)
    {
        val=*F_reg;
        *dest  = val/256;
        dest++;
        *dest = val%256;   
        dest++;
    }
   
    //return *F_reg;
      
}

// FPGA icerisindeki clk de?erini set eder
void F_regs_Adc_clk_set(uint16_t val)
{
    switch(val)
    {
        case 0:control2_reg.bits.clkset=clk100mhz;
        break;
                
        case 1:control2_reg.bits.clkset=clk50mhz;
        break;
                
        case 2:control2_reg.bits.clkset=clk25mhz;
        break;
                
        case 3:control2_reg.bits.clkset=clk12mhz;
        break;      
        
        case 4:control2_reg.bits.clkset=clk6mhz;
        break;
              
        case 5:control2_reg.bits.clkset=clk3mhz;
        break;
        
        case 6:control2_reg.bits.clkset=clk1mhz;
        break;
        
        case 7:control2_reg.bits.clkset=adcdurdur;
        break;
        
        default:break;
        
        
    }
    freg_wr(addr_cntr2_reg, control2_reg.cntrl_val);
}

void F_regs_Read_channel_sel(uint16_t val)
{
        control2_reg.bits.Read_channel_sel = val;
        freg_wr(addr_cntr2_reg, control2_reg.cntrl_val);
}

void F_regs_Channel_bit_gain(uint16_t val)
{
        control2_reg.bits.channel_bit_gain = val;
        freg_wr(addr_cntr2_reg, control2_reg.cntrl_val);
}


inline void F_regs_fifo_aclr()
{
        control_reg.bits.aclr=1;
        freg_wr(addr_cntr_reg, control_reg.cntrl_val);
        control_reg.bits.aclr=0;
}

inline void F_regs_ADC_Buffer_size_set(uint16_t val)
{
    control_reg.bits.buffer_size = val;
    freg_wr(addr_cntr_reg, control_reg.cntrl_val);
    
}

inline void F_regs_Begin_acquisition()
{
    control_reg.bits.acq_begin=1;
    freg_wr(addr_cntr_reg, control_reg.cntrl_val);
    control_reg.bits.acq_begin=0;
    
}

typedef enum
{
   
    internal,
    external,
} vca_in_type;

inline void F_regs_LNP_gain_set(Lnp_Gain gain)
{
    
    
    VCAPDVOn();
    VCAPDLOn();
    VCAINSELOff();
    VCAHLOff();
    
    /*
    SYS_PORTS_PinSet( PORTS_ID_0, PORT_CHANNEL_H, PORTS_BIT_POS_12 ); //VCA POWERDOWN
    SYS_PORTS_PinSet( PORTS_ID_0, PORT_CHANNEL_H, PORTS_BIT_POS_13 ); //LNA POWERDOWN
    
    SYS_PORTS_PinClear( PORTS_ID_0, PORT_CHANNEL_D, PORTS_BIT_POS_0 ); //VCA ?NSELL
    
    SYS_PORTS_PinClear( PORTS_ID_0, PORT_CHANNEL_D, PORTS_BIT_POS_11 ); //VCA HL LOW
    
    //control2_reg.bits.VCA_PDL=1;
    //control2_reg.bits.VCA_PDV=1;
    //control2_reg.bits.VCA_insel=internal;
    //control2_reg.bits.VGA_HL=0;*/
                
    switch(gain)
    {
        case lnpgain_3db:
            
            VCAG1Off();
            VCAG2Off();
                   /* 
            SYS_PORTS_PinClear( PORTS_ID_0, PORT_CHANNEL_H, PORTS_BIT_POS_15 ); //G1 LOW
            SYS_PORTS_PinClear( PORTS_ID_0, PORT_CHANNEL_H, PORTS_BIT_POS_14 ); //G2 LOW*/
            
                //control2_reg.bits.VGA_G1=0;
                //control2_reg.bits.VGA_G2=0;
            break;
        case lnpgain_12db:
            
            VCAG1Off();
            VCAG2On();
            /*
            SYS_PORTS_PinClear( PORTS_ID_0, PORT_CHANNEL_H, PORTS_BIT_POS_15 ); //G1 LOW
            SYS_PORTS_PinSet( PORTS_ID_0, PORT_CHANNEL_H, PORTS_BIT_POS_14 ); //G2 high
            */
                //control2_reg.bits.VGA_G1=0;
                //control2_reg.bits.VGA_G2=1;
            break;
            
        case lnpgain_18db:
            
            VCAG1On();
            VCAG2Off();
            
            //SYS_PORTS_PinSet( PORTS_ID_0, PORT_CHANNEL_H, PORTS_BIT_POS_15 ); //G1 high
            //SYS_PORTS_PinClear( PORTS_ID_0, PORT_CHANNEL_H, PORTS_BIT_POS_14 ); //G2 low
            
                //control2_reg.bits.VGA_G1=1;
                //control2_reg.bits.VGA_G2=0;
            break;
        case lnpgain_22db:
            
            VCAG1On();
            VCAG2On();
            
            //SYS_PORTS_PinSet( PORTS_ID_0, PORT_CHANNEL_H, PORTS_BIT_POS_15 ); //G1 high
            //SYS_PORTS_PinSet( PORTS_ID_0, PORT_CHANNEL_H, PORTS_BIT_POS_14 ); //G2 high
                //control2_reg.bits.VGA_G1=1;
                //control2_reg.bits.VGA_G2=1;
            break;
            
        case lnp_pwrdwn:
            
            VCAPDVOn();
            VCAPDLOff();
            VCAINSELOn();
            VCAHLOff();
            
            VCAG1Off();
            VCAG2Off();           
            /*
            SYS_PORTS_PinSet( PORTS_ID_0, PORT_CHANNEL_H, PORTS_BIT_POS_12 ); //VCA POWERDOWN
            SYS_PORTS_PinClear( PORTS_ID_0, PORT_CHANNEL_H, PORTS_BIT_POS_13 ); //LNA POWERDOWN
            SYS_PORTS_PinSet( PORTS_ID_0, PORT_CHANNEL_D, PORTS_BIT_POS_0 ); //VCA ?NSELL
            SYS_PORTS_PinClear( PORTS_ID_0, PORT_CHANNEL_D, PORTS_BIT_POS_11 ); //VCA HL LOW
            
            SYS_PORTS_PinClear( PORTS_ID_0, PORT_CHANNEL_H, PORTS_BIT_POS_15 ); //G1 LOW
            SYS_PORTS_PinClear( PORTS_ID_0, PORT_CHANNEL_H, PORTS_BIT_POS_14 ); //G2 LOW*/
            
                //control2_reg.bits.VCA_PDL=0;
                //control2_reg.bits.VCA_PDV=1;
                //control2_reg.bits.VCA_insel=external;
                
                //control2_reg.bits.VGA_G1=0;
                //control2_reg.bits.VGA_G2=0;
            break;
         
        case pwr_dwn_all:
            
            VCAPDVOff();
            VCAPDLOff();

            
            VCAG1Off();
            VCAG2Off();
            
            /*
            SYS_PORTS_PinSet( PORTS_ID_0, PORT_CHANNEL_H, PORTS_BIT_POS_12 ); //VCA POWERDOWN
            SYS_PORTS_PinSet( PORTS_ID_0, PORT_CHANNEL_H, PORTS_BIT_POS_13 ); //LNA POWERDOWN
            
            SYS_PORTS_PinClear( PORTS_ID_0, PORT_CHANNEL_H, PORTS_BIT_POS_15 ); //G1 LOW
            SYS_PORTS_PinClear( PORTS_ID_0, PORT_CHANNEL_H, PORTS_BIT_POS_14 ); //G2 LOW
            */
                //control2_reg.bits.VCA_PDL=0;
                //control2_reg.bits.VCA_PDV=0;
                // control2_reg.bits.VGA_G1=0;
                //control2_reg.bits.VGA_G2=0;
                //control2_reg.bits.VGA_HL=1;

            break;
        default: 
        {
            break;
        }
    }
    
    //freg_wr(addr_cntr2_reg, control2_reg.cntrl_val);
}

inline void F_regs_Pulse_cntrl1_set(uint8_t p_freq, uint8_t p_count1)
{
    switch(p_freq)
    {
        case 0:
            Pulser_cntrl1.bits.darbe_frekansi =5; //10mhz
            break;
        case 1:
            Pulser_cntrl1.bits.darbe_frekansi =10;//5mhz
            break;
        case 2:
            Pulser_cntrl1.bits.darbe_frekansi =25;//2mhz
            break;
        case 3:
            Pulser_cntrl1.bits.darbe_frekansi =50;//1mhz
            break;
        case 4:
            Pulser_cntrl1.bits.darbe_frekansi =100;//0.5 Mhz
            break;
        default:
            break;
            
    }

    Pulser_cntrl1.bits.darbe_sayisi   = p_count1;
    freg_wr(addr_pulse_cntrl1, Pulser_cntrl1.cntrl_val);
}

inline void F_regs_Pulse_cntrl2_set(uint8_t outsel)
{


    Pulser_cntrl2.bits.out_sel   = outsel;
    freg_wr(addr_pulse_cntrl2, Pulser_cntrl2.cntrl_val);
}


inline void F_regs_Pulsed_sample_get()
{
     ornekleme_cntrl.bits.single_pulsed_sample_get=1;
     freg_wr(add_ornekleme_cntrol, ornekleme_cntrl.cntrl_val);
     ornekleme_cntrl.bits.single_pulsed_sample_get=0;
     
}

inline void F_regs_Pulsed_enable(bool val)
{
    ornekleme_cntrl.bits.pulser_enable_pe=val;
    freg_wr(add_ornekleme_cntrol, ornekleme_cntrl.cntrl_val);
    
}



// Comment a function definition and leverage automatic documentation 
/**
  <p><b>Function:</b></p>

  <p><b>Summary:</b></p>

  <p><b>Description:</b></p>

  <p><b>Remarks:</b></p>
 */
// TODO Insert function definitions (right here) to leverage live documentation
