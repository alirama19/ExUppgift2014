#include <asf.h>
#include "adc_custom.h"
#include "dac_custom.h"
#include "delay.h"
#include "PIDRegulation.h"

static void configure_console(void)
{
	const usart_serial_options_t uart_serial_options = { .baudrate =
	CONF_UART_BAUDRATE, .paritytype = CONF_UART_PARITY };
	/* Konfigurera konsol UART. */
	sysclk_enable_peripheral_clock(CONSOLE_UART_ID);
	stdio_serial_init(CONF_UART, &uart_serial_options);
	
	/* configure RX0 pin as pull-up - this is tailored towards use with Matlab*/
	ioport_set_pin_mode(PIO_PA8_IDX, IOPORT_MODE_PULLUP);
}

int main (void)
{
	sysclk_init(); // Initialize system clock
	board_init(); // Initialize Arduino Due board
	
	delay_init(); // Initialize the timer
	
	ioport_init(); // Initialize the IO-port
	
	adc_distanceSensor_setup(); // Setup ADC for reading distance sensor
	
	dac_setup(); // Setup DAC for controlling fan motor
	
	configure_console(); // Initialize UART
	
	printf("Booted Due\n");
	
	/* Creating the sensor-reading task */
	if (xTaskCreate(PIDRegulationTask, (const signed char * const) "PIDRegulation",
	TASK_PIDRegulation_STACK_SIZE, NULL, TASK_PIDRegulation_STACK_PRIORITY, NULL) != pdPASS)
	{
		printf("Failed to create PIDRegulationTask\r\n");
	}
	
	/* Start the FreeRTOS scheduler running all tasks indefinitely*/
	vTaskStartScheduler();
	
	while(1);
	return 0;
}