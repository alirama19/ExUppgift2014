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

// void receiveByte()
// {
// uint8_t value;
// while (!uart_is_rx_ready (CONF_UART)){};
// uart_read(CONF_UART, &value);
// return value;
// }

// void configure_console(void){
// 	const usart_serial_options_t uart_serial_options = {
// 		.baudrate = CONF_UART_BAUDRATE,
// 	.paritytype = CONF_UART_PARITY};
// 	// Configure console UART.
// 	sysclk_enable_peripheral_clock(CONSOLE_UART_ID);
// 	stdio_serial_init(CONF_UART, &uart_serial_options);
// 	// configure RX0 pin as pull-up otherwise it won't receive anything (only receive 0)
// 	ioport_set_pin_mode(PIO_PA8_IDX, IOPORT_MODE_PULLUP);
// }

void getPIDValues()
{
	
}


// void setupSTDIO(void){
// 	const usart_serial_options_t uart_serial_options = { .baudrate = CONF_UART_BAUDRATE, .paritytype = CONF_UART_PARITY };
// 	stdio_serial_init(CONF_UART, &uart_serial_options);	
// 	/* Stdout shall not be buffered */
// 	#if defined(__GNUC__)
// 	setbuf(stdout, NULL);
// 	#else
// 	/* Redan i fallet IAR's Normal DLIB default
// 	konfiguration:
// 	* sänder en tecken åtgången
// 	*/
// 	#endif	
//
