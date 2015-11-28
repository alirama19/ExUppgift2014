/*
 * UARTFunctions.c
 *
 * Created: 2015-11-14 01:49:37
 *  Author: Stefan
 */ 

#include <asf.h>
#include "uart.h"

int receiveByte()
{
	static uint8_t readByte;
	
	uart_settings_t uart_settings = {
		.baud_rate = 115200,
		.parity = UART_PARITY_NO,
		.ch_mode = UART_CHMODE_LOCAL_LOOPBACK
	};
	
	// initialize UART
	uart_init(&uart_settings);
		
	
	while (!(uart_rx_ready()));
	readByte = uart_read_char();
	
	return readByte;
}

void byteToArray()
{
	int i;
	int byteArray[5];
	for( i=0; i<5; i++ ){
		byteArray[i] = receiveByte();
	}
}