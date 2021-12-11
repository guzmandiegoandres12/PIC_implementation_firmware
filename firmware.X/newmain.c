/*
 * File:   newmain.c
 * Author: nova
 *
 * Created on 11 de diciembre de 2021, 01:15 AM
 */

// CONFIG1H
#include "config.h"
#include "stdbool.h"

int out = 0;

void __interrupt () isr( void ) 
{ 
   
    if (INTCONbits.TMR0IE && INTCONbits.T0IF) {
        out ^= 1;
        PORTBbits.RB1 = (char)out; 
    }
    INTCONbits.T0IF = 0;
    TMR0H = 0x0;
    TMR0L = 0x0;
    return;
}

void config(){
    INTCONbits.GIE = 1;
    INTCONbits.TMR0IE = 1;
   
    T0CON = 0b0000010;
    T0CONbits.TMR0ON = 1;      
    
    TRISB = 0x00;
    TRISD = 0x00;
     
}

void main(void) {
    config();
   PORTDbits.RD3 = 1; 
    
    while(1){
       
    };
    
  
}

