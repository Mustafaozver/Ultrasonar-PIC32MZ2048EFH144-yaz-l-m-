//#include <mega8.h>
//#include <delay.h>
//#include <stdlib.h>

#include "LCD_216.h"

#define LCD_RS(x)    LCD_RSStateSet(x)    // Register select

#define LCD_EN(x)    LCD_EStateSet(x)    // Enable
#define LCD_D4(x)    LCD_D4StateSet(x)// Data bits
#define LCD_D5(x)    LCD_D5StateSet(x)// Data bits
#define LCD_D6(x)    LCD_D6StateSet(x)  // Data bits
#define LCD_D7(x)    LCD_D7StateSet(x)   // Data bits
#define    LCD_STROBE    ((LCD_EStateSet(1)),delay_us(100),(LCD_EStateSet(0)))





extern void delay_ms1(uint16_t);
extern void delay_us(uint16_t);


/*
 *    LCD interface example
 *    Uses routines from delay.c
 *    This code will interface to a standard LCD controller
 *    like the Hitachi HD44780. It uses LCD display in 4 bit mode, with
 *    the hardware connected as follows (the standard 14 pin 
 *    LCD connector is used):
 *    lcd_rs=1;
 *    PORTB bits 0-3 are connected to the LCD data bits 4-7 (high nibble)
 *    PORTA bit 2 is connected to the LCD RS input (register select)
 *    PORTA bit 3 is connected to the LCD EN bit (enable)
 *    
 *    To use these routines, set up the port I/O (TRISA, TRISB) then
 *    call lcd_init(), then other routines as required.
 *
 * Copywrite Craig Lee 1998
 *    
 */
/* write a byte to the LCD in 4 bit mode */
void lcd_write(unsigned char c)
{/*
    if(c & 0x80) LCD_D7(1); else LCD_D7(0);
    if(c & 0x40) LCD_D6(1); else LCD_D6(0);
    if(c & 0x20) LCD_D5(1); else LCD_D5(0);
    if(c & 0x10) LCD_D4(1); else LCD_D4(0);
    LCD_STROBE;
    if(c & 0x08) LCD_D7(1); else LCD_D7(0);
    if(c & 0x04) LCD_D6(1); else LCD_D6(0);
    if(c & 0x02) LCD_D5(1); else LCD_D5(0);
    if(c & 0x01) LCD_D4(1); else LCD_D4(0);
    LCD_STROBE;    
    delay_us(400);*/
}
/*
 *     Clear and home the LCD
 */
void lcd_clear(void)
{/*
    LCD_RS(0);
    lcd_write(0x1);
    delay_ms1(20);*/
}
/* write a string of chars to the LCD */
void lcd_puts(const char * s)
{/*
    LCD_RS(1);    // write characters
    while(*s) lcd_write(*s++);  */
}
/* write one character to the LCD */
void lcd_putch(unsigned char c)
{/*
    LCD_RS(1);    // write characters
    lcd_write(c);*/
}
/*
 * Go to the specified position
 */
void lcd_goto(unsigned char pos,unsigned char line)
{/*
    LCD_RS(0);
    if (line==0) lcd_write(0x80 + pos);
    else lcd_write(0x80 + pos+ 0x40);*/
}
     
/* initialise the LCD - put into 4 bit mode */
void lcd_init(void)
{/*
    LCDBLCNTROn(); // Geçici
    LCD_RS(0);    // write control bytes
    delay_ms1(150);// power on delay
    LCD_D4(1);    // init!    
    LCD_D5(1); //
    LCD_STROBE;    
    delay_ms1(50);
    LCD_STROBE;    // init!    
    delay_us(1000);
    LCD_STROBE;    // init!    
    delay_ms1(50);
    LCD_D4(1);    // set 4 bit mode
    LCD_STROBE;    
    delay_us(400);
     
    lcd_write(0x28);// 4 bit mode, 1/16 duty, 5x8 font, 2lines
    lcd_write(0x0C);// display on
    lcd_write(0x06);// entry mode advance cursor
    lcd_write(0x01);// clear display and reset cursor*/
}
// Standard Input/Output functions
// Declare your global variables here