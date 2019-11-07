#include<drivers.h>
#include<functions.h>

#ifndef F_CPU 1000000UL
#define F_CPU 1000000UL //internal clock used
#endif /*F_CPU 1000000UL*/

void ADC_init(){
    //PRR &= ~(1<<PRADC); // clears the Power Reduction ADC register
    DIDR0 |=((1<<ADC0D)|(1<<ADC1D)|(1<<ADC2D)|(1<<ADC3D));  //0X00; //sets the Digital Input Disable Register0
    ADCSRA |= ((1<<ADEN)|(1<<ADPS2)|(1<<ADPS1));// 0b10001110 enables ADC & division factor64-125khz 
    ADMUX &= ~((1<<REFS1)|(1<<REFS0)); //AREF, internal Vref turned off 
    ADCSRA |=(1<<ADSC);
};