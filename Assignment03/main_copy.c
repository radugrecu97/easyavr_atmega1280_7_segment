///*
 //* Assignment03.c
 //*
 //* Created: 18-Mar-19 13:38:28
 //* Author : radug
 //*/ 
//
//#include <avr/io.h>
//#include <avr/interrupt.h>
//#include <stdbool.h>
//#include "util/delay.h"
//#include "interface.h"
//#include "avr/sfr_defs.h"
//
///**
 //* Function declaration
 //*/
//
//int digitToHex(int digit);
//int getNumberLength(int number);
//int getNthDigit(uint16_t number, int position);
//void init_timer();
//
	//
//uint8_t *valueHex,
//currentDigit,
//digitHex,
//currentSegment = 0;
//
//int main(void)
//{
	////initialize peripherals
	//init_7_segment();
	//init_timer();
//
	////set Global Interrupt in SREG
	//sei();
	//printint_7_segment(1239);
	//while (1)
	//{	
		//
		////display_7_segment(45.69, 2);
	//}
//}
//
//void printint_7_segment(uint16_t value)
//{
	//valueHex = splitNumber(value);
//}
//
//void display_7_segment(float value, uint8_t no_of_decimals)
//{
	//int digitToDisplay,
	//digitHexValue;
	//int valueInt;
//
	////convert float to int
	//for (int i = 0; i<no_of_decimals; i++)
	//{
		//value = value * 10;
	//}
//
	////0.5 is added to the value because the value may not be represented exactly in binary
	//valueInt = (int) (value + 0.5);
		//
	////for each of the number's digit, push to storage register
	//for (int i = 0; i<getNumberLength(valueInt); i++)
	//{
		//currentSegment = i;
		//digitToDisplay = getNthDigit(valueInt, i);
		//digitHexValue = digitToHex(digitToDisplay);
		//
		////if the decimal point position is reached, set dp section to 1
		//if (no_of_decimals == i && no_of_decimals > 0)
			//digitHexValue++;
//
		//for (int j = 0; j<8; j++)
		//{
			////load MSB firsts
			//if ((digitHexValue >> j) & 1)
				//PORTB |= _BV(PB2);
			//else
				//PORTB &= ~(_BV(PB2));
				//
			////push bit to shift register
			////set SHCP to high
			//PORTB |= _BV(PB1);
			//
			////set SHCP to low
			//PORTB &= ~(_BV(PB1));
		//}	
		//
		////set flag so the interrupt can enter the loop
		//flagReadyToShift = 0;
		//flagReadyToDisplay = 1;
		//while (flagReadyToShift == 0);
	//}
//}
//
//uint8_t* splitNumber(uint16_t number)
//{
	//uint8_t tempArr[5];
	////array size
	//tempArr[4] = 0;
	//
	//while (number > 0) {
		//tempArr++ = number % 10;
		//// do something with digit
		//number /= 10;
		//tempArr[4]++;
	//}
	//
	//return &tempArr[0];
//}
//
///**
 //* For each digit to be represented, specific segments need to be lit up.
 //*/
//
//int digitToHex(int digit)
//{
	//int hexValue;
	//switch (digit)
	//{
		//case 0: hexValue = 0xFC;
		//break;
		//case 1: hexValue = 0x60;
		//break;
		//case 2: hexValue = 0xDA;
		//break;
		//case 3: hexValue = 0xF2;
		//break;
		//case 4: hexValue = 0x66;
		//break;
		//case 5: hexValue = 0xB6;
		//break;
		//case 6: hexValue = 0xBE;
		//break;
		//case 7: hexValue = 0xE0;
		//break;
		//case 8: hexValue = 0xFE;
		//break;
		//case 9: hexValue = 0xF6;
		//break;
		////set to 0 if undefined
		//default: hexValue = 0xFC;
		//break;
	//}
	//return hexValue;	
//}
//
//int getNumberLength(int number)
//{
	//return floor (log10 (abs (number))) + 1;
//}
//
//int getNthDigit(uint16_t number, int position)
//{
	//static int powersof10[] = {1, 10, 100, 1000};
	//return ((number / powersof10[position]) % 10);
//}
//
//
//void init_7_segment()
//{
	////set SHCP, DS and MR as output
	//DDRB |= _BV(DDB1) | _BV(DDB2) | _BV(DDB3);
	////set STCP as output
	//DDRK |= _BV(DDK3);
	//
	////set MR to high as it is active low
	//PORTB |= _BV(PB3);
	//
	////enable pullups
	//DDRL = 0x0F;
//}
//
///**
 //* Compare register value was calculated using the forumla: 7372800 / 2 * 64 (1 + x)= refresh rate
 //*/
//
//void init_timer()
//{
//
	////Setup Timer 0 pre-scaler to clk/64
	//TCCR4B |=_BV(CS41)|_BV(CS40)|_BV(WGM42);
	//
	////initialize counter
	//TCNT4=0;
//
	//
	////initialize compare value
	////f=240 - 239
	////f=140hz - 410
	////f=100hz - 575 (no flickering)
	////f=80hz - 719 (noticeable flickering)
	////f=60hz - 959
	////f=50hz - 1151
	//OCR4A=575;
	//
	////
	////enable compare interrupt
	//TIMSK4 |= _BV(OCIE4A);
//}
//
//
//ISR(TIMER4_COMPA_vect) 
//{
//
	//currentDigit = getNthDigit(value, currentSegment);
	//digitHex = digitToHex(currentDigit);
	//
	//for (int j = 0; j<8; j++)
	//{
		////load MSB firsts
		//if ((digitHex >> j) & 1)
		//PORTB |= _BV(PB2);
		//else
		//PORTB &= ~(_BV(PB2));
		//
		////set SHCP to high
		//PORTB |= _BV(PB1);
		//
		////set SHCP to low
		//PORTB &= ~(_BV(PB1));
	//}
//
	//PORTL &= ~(_BV(PL0) | _BV(PL1) | _BV(PL2) | _BV(PL3));
	//PORTL |= _BV(currentSegment);
	////set latch high
	//PORTK |= _BV(PK3);
	////set latch low
	//PORTK &= ~(_BV(PK3));
	//
	//currentSegment++;
	//
	//if (currentSegment == 4)
		//currentSegment = 0;
	//
//}