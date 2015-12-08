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
#include "global_variables.h"

void SerialComTask (void *pvParameters)
{
	portTickType xLastWakeTime = xTaskGetTickCount();
	const portTickType xFrequency = 300; // Run every few ms
	
	for(;;){
		vTaskDelayUntil(&xLastWakeTime,xFrequency);
		getPIDValues();
		setPIDValues();
	}
}

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
		while (!uart_is_rx_ready (CONF_UART)){};
		uart_read(CONF_UART, &p_temp);
		while (!uart_is_rx_ready (CONF_UART)){};
		uart_read(CONF_UART, &i_temp);
		while (!uart_is_rx_ready (CONF_UART)){};
		uart_read(CONF_UART, &d_temp);
		while (!uart_is_rx_ready (CONF_UART)){};
		uart_read(CONF_UART, &dTime);
		while (!uart_is_rx_ready (CONF_UART)){};
		uart_read(CONF_UART, &distanceSet_temp);
}

void setPIDValues()
{
	double P_CONSTANT = (double) (p_temp / divider);
	double I_CONSTANT = (double) (i_temp / divider);
	double D_CONSTANT = (double) (d_temp / divider);
	
	switch(distanceSet_temp){
		case 10 :
		distanceSet = 100;
		break;
		
		case 20 :
		distanceSet = 200;
		break;
		
		case 30 :
		distanceSet = 300;
		break;
		
		case 40 :
		distanceSet = 400;
		break;
		
		case 50 :
		distanceSet = 500;
		break;
		
		case 60 :
		distanceSet = 600;
		break;
	}
}

void sendPIDValues(){
	
}



