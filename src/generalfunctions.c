#include "generalfunctions.h"

void delay_ms1(uint16_t j) {
 uint32_t i = j*50000;
 for(;i>0;i--);
}

void delay_us(uint16_t j1) {
 uint32_t i1 = j1*90;
 for(;i1>0;i1--);
}