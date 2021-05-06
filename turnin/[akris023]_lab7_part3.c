/*	Author: lab
 *  Partner(s) Name: atmega1284p
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 *	 
 *	Vedio: https://youtube.com/shorts/-OtQiEFwcVI?feature=share
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
    unsigned char result;  
    unsigned short max = 0xff; 
    /* Insert your solution below */
    while (1) {
	x = ADC;
	//unsigned char var = (char)x; 
	//unsigned char var2 = (char)(x >> 4);
	if(x >= (max / 2)){
	    PORTB = 0x01; 
	}
	else{
	    PORTB = 0x00; 
	    PORTD = 0x00; 
	}
	    
	//PORTD = var2; 	
    }
    return 1;
}
