/*
 * File:   main.c
 * Author: acer
 *
 * Created on November 10, 2021, 7:39 PM
 */


#include <xc.h>
#include "config.h"
#define _XTAL_FREQ 4000000

void main(void) {
    
    unsigned char seg_arr[10] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
    
    TRISB = 0;
    PORTB = 0;
    TRISC = 0;
    PORTC = 0;
    TRISD = 0;
    PORTD = 0;
    
    while(1) {
        for(int i = 0; i < 10; i++) {
            PORTC = seg_arr[i];
            
            RD0 = 1;
            if(i == 5) RD1 = 1;
//            RD0 = i == 5 ? 0 : 1;
//            RD1 = i == 5 ? 1 : 0;
//            RD2 = i == 9 ? 1 : 0;
            
            for(int j = 0; j < 10; j++) {
            PORTB = seg_arr[j];
            __delay_ms(1000);
            
            if(i == 9 && j == 9){
                RD0 = 0;
                RD1 = 0;
                RD2 = 1;
            }
            }
        }
        __delay_ms(10000);
        RD2 = 0;
    }
    return;
}
