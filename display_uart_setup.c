#ifndef F_CPU
	#define F_CPU 16000000UL
#endif

#ifdef BAUD
#undef BAUD  // avoid compiler warning
#endif
#define BAUD 57600

#define DISPLAY_BAUD_TOL 2

#include <avr/io.h>
#include <stdio.h>
#include <util/setbaud.h>

void Display_Uart_Init(void)
{	
	UBRR1H = UBRRH_VALUE; //check datasheet
	UBRR1L = UBRRL_VALUE; //

	#if USE_2X
	UCSR1A |= (1 << U2X1); //check datasheet
	#endif

	UCSR1B = (1 << RXEN1) | (1 << TXEN1);

	// 8-bit, 1 stop bit, no parity, asynchronous UART
	UCSR1C = (1 << UCSZ11) | (1 << UCSZ10) | (0 << USBS1) |
	(0 << UPM11) | (0 << UPM10) | (0 << UMSEL01) |
	(0 << UMSEL10);
}

void Display_UartPutchar(char data)
{
	while(!(UCSR1A & (1 << UDRE1)));
	UDR1 = data;
}

int Display_UartGetchar(void)
{
	char data;
	
	while (!(UCSR1A & (1 << RXC1)));
	
	data = UDR1;
	
	if (data == '\n') {
		return -1;
	}
	Display_UartPutchar(data);

	return data;
}

void Display_SendData( unsigned char* buf, unsigned char len)
{
	unsigned char i, bcc;
	Display_UartPutchar( 0x11 );
	bcc = 0x11;

	Display_UartPutchar( len );
	bcc = bcc +len;

	for( i = 0; i < len; i++ ){
		Display_UartPutchar(buf[i]);
		bcc = bcc +buf[i];
	}

	Display_UartPutchar(bcc);
}