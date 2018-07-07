#include "MAX19516.h" 

#define testbit(var, bit)       ((var) & (1 << (bit)))
int global_data;

void ic_adc_full_pwr_dwn(){spi_3wire_write(0,0);}
void ic_adc_cha_b_pwr_dwn(){spi_3wire_write(0,1);}
void ic_adc_cha_a_pwr_dwn(){spi_3wire_write(0,2);}
void ic_adc_full_aktif(){spi_3wire_write(0,3);}

void ic_adc_full_stndby(){spi_3wire_write(0,4);}
void ic_adc_cha_b_stndby(){spi_3wire_write(0,5);}
void ic_adc_cha_a_stndby(){spi_3wire_write(0,6);}

void MAX19516_mux_out(bool enable){spi_3wire_write(1,enable*2);}
//void MAX19516_mux_chan(bool chan){spi_3wire_write(1,enable);}

void MAX19516_dis_DOR(){spi_3wire_write(2,3);}//dor ve dclk iptal
void MAX19516_dis_DCLK(){spi_3wire_write(2,1);}

void MAX19516_out_term( uint8_t data){data=data+data*8; spi_3wire_write(4,data);} //kanal 1 ve iki ayn? anda terminasyon
void MAX19516_dclk_term( uint8_t data){data=data+data*8; spi_3wire_write(5,data);} //kanal 1 ve iki ayn? anda terminasyon
void MAX19516_soft_reset(){spi_3wire_write(0x0a,0x5a);}


void MAX19516_test_patern(bool test_patern,bool test_patern_out_en, uint8_t format,bool in_clk_term,bool sync_mode,uint8_t clk_div) {
 int reg_val=0;
 reg_val=test_patern*128+test_patern_out_en*64+format*16+in_clk_term*8+sync_mode*4+clk_div;
 spi_3wire_write(6,reg_val);
}

void MAX19516_init() {
 spi_csStateSet(1);
 spi_clkStateSet(1);
 spi_enStateSet(0);
 ic_adc_full_aktif();
 delay_us(5);
 MAX19516_test_patern(0,0,1,0,0,0);
 delay_us(5);
 MAX19516_dis_DOR();
 delay_us(5);
 MAX19516_mux_out(1);
 delay_us(5);
 ic_adc_cha_b_pwr_dwn();
}

void spi_3wire_write(uint8_t adres, uint8_t data ) {
 uint8_t i,j,z; 
 uint8_t  dat[2]={0};
    
 z=1;
 dat[0] = adres&~0x80;
 dat[1] = data;
    
 spi_enStateSet(0);
 spi_csStateSet(0);
 spi_clkStateSet(0);
 for(j=0;j<2;j++) {
  for(i=0;i<8;i++) {
   if(testbit(dat[j], 7-i))spi_outOn(); //Data
   else spi_outOff();//Data
   spi_clkToggle();
   if(z!=0){if(z!=0){z++;}}if(z!=0){if(z!=0){z++;}}if(z!=0){if(z!=0){z++;}}if(z!=0){if(z!=0){z++;}}if(z!=0){if(z!=0){z++;}}
   spi_clkToggle();
   if(z!=0){if(z!=0){z++;}}

  }             
 }
 spi_csStateSet(1);
 spi_clkStateSet(1);
}
