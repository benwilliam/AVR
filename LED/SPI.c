/*
 * SPI.c
 *
 *  Created on: 07.09.2011
 *      Author: rdo
 */
#include "LEDMatrix.h"
#include <avr/io.h>
#include <avr/interrupt.h>

#define DDR_SPI DDRB
#define DD_MOSI PB3
#define DD_SCK  PB5
#define DD_SS   PB2

static unsigned char curentLine = 0;

void resetTimer()
{
    //set countingvalue
    TCNT0 = 200;//(0xff - (COUNTER));
}

void initTimer()
{
    //set prescaler 64
    TCCR0 = (0<<CS02) | (1<<CS01) | (1<<CS00);

    resetTimer();

    //enable Timer0 interrupt
    TIMSK = 0x01;

}
void initPortLines()
{
    DDRC = (1<<PIN2) | (1<<PIN1) | (1<<PIN0);
}

void writeSPI(unsigned char data)
{
    /* Start transmission */
	SPDR = data;
	/* Wait for transmission complete */
	while(!(SPSR & (1<<SPIF)));
}

void initSPI()
{
    /* Set MOSI and SCK output, all others input */

	DDR_SPI = (1<<DD_MOSI)|(1<<DD_SCK)|(1<<DD_SS);
	/* Enable SPI, Master, set clock rate fck/2 */
	SPCR = (1<<SPE)|(1<<MSTR)| (0<<SPR1) | (0<<SPR0);
    SPSR = (1<<SPI2X);

	//send dummy byte
	writeSPI(0);
}

void init()
{
    initPortLines();
    initSPI();
    initTimer();
    sei();
}



void toggleOutput()
{
    PORTB = (1<<DD_SS);
    PORTB = (0<<DD_SS);
}

ISR(TIMER0_OVF_vect)
{
    unsigned char i;
    for(i=0; i<(BUFFER_WIDTH); i++)
    {
        writeSPI(outPutBuffer[i][curentLine]);
    }
    toggleOutput();
    PORTC = curentLine;

    curentLine++;
    if(curentLine>= HEIGHT)
    {
        curentLine = 0;
    }
    resetTimer();
}

