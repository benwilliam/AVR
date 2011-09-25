/*
 * SPI.c
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *  Created on: 07.09.2011
 *      Author: Roland Domke
 *   Copyright: 2011 Roland Domke
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
    TCNT0 = (0xff - (COUNTER) + 2);
}

void initTimer()
{
    //set prescaler 256
    TCCR0 = (1<<CS02) | (0<<CS01) | (0<<CS00);

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
	resetTimer();
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

}

