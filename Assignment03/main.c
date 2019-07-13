/*
 * Assignment03.c
 *
 * Created: 18-Mar-19 13:38:28
 * Author : radug
 */ 


#include "util/delay.h"
#include "driver_7segment.h"
#include <avr/interrupt.h>

int main(void)
{
	//initialize peripherals
	init_7_segment();
	
	
	display_7_segment(40.05, 2);
	//printint_7_segment(1);
	//set Global Interrupt in SREG
	sei();

	while (1)
	{	

	}
}