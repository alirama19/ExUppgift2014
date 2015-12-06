/*
 * UARTFunctions.c
 *
 * Created: 2015-11-14 01:49:37
 *  Author: Stefan
 */ 

#include <asf.h>
#include "UARTFunctions.h"
#include "uart.h"
#include "conf_uart_serial.h"

int receiveByte()
{
uint8_t value;
printf("%c", '2');
while (!uart_is_rx_ready (CONF_UART)){};
	printf("%c", '3');
uart_read(CONF_UART, &value);
printf("%c", '4');
return value;
}

void configure_console(void){
	const usart_serial_options_t uart_serial_options = {
		.baudrate = CONF_UART_BAUDRATE,
	.paritytype = CONF_UART_PARITY};
	// Configure console UART.
	sysclk_enable_peripheral_clock(CONSOLE_UART_ID);
	stdio_serial_init(CONF_UART, &uart_serial_options);
	// configure RX0 pin as pull-up otherwise it won't receive anything (only receive 0)
	ioport_set_pin_mode(PIO_PA8_IDX, IOPORT_MODE_PULLUP);
}

void getPIDValues()
{
	
}



