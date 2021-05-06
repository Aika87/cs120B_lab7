/*	Author: lab
 *  Partner(s) Name: atmega1284p
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 *	 
 *	Vedio: https://youtube.com/shorts/XNgxUPKbZuU?feature=share
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif
 

void ADC_init(){
	ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE); 
}

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRB = 0xff; PORTB = 0x00;
    DDRD = 0xff; PORTD = 0x00;  
    //DDRA = 0x00; PORTA = 0xff;  
    ADC_init();
    unsigned short x = ADC;
    unsigned short val; 
    /* Insert your solution below */
    while (1) {
	x = ADC;
	//unsigned char var = (char)x; 
	//unsigned char var2 = (char)(x >> 4);
	if(x >= 248){
	    val = 0xff; 
	}
	else if((x >= 217) && (x < 248)){
	    val = 0x7f; 
	}
	else if((x >= 186) && (x < 217)){
            val = 0x3f;
        }
	else if((x >= 155) && (x < 186)){
            val = 0x1f;
        }
	else if((x >= 124) && (x < 155)){
            val = 0x0f;
        }
	else if((x >= 93) && (x < 124)){
            val = 0x07;
        }
	else if((x >= 62) && (x < 93)){
            val = 0x03;
        }
	else if((x >= 31) && (x < 62)){
            val = 0x01;
        }
	else 
	    val = 0x00; 

	PORTB = val; 
	    
	//PORTD = var2; 	
    }
    return 1;
}
