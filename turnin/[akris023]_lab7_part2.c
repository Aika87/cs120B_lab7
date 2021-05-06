/*	Author: lab
 *  Partner(s) Name: atmega1284p
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 *	MAX value is 0xFF 
 *	Vedio: https://youtube.com/shorts/jGJoerxn29Y?feature=share
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
    /* Insert your solution below */
    while (1) {
	x = ADC;
	unsigned char var = (char)x; 
	unsigned char var2 = (char)(x >> 4); 
	PORTB = var; 
	PORTD = var2; 	
    }
    return 1;
}
