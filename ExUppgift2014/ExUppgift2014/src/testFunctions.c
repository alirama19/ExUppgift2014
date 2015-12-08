/*
 * testFunctions.c
 *
 * Created: 2015-10-10 16:06:54
 *  Author: Stefan and Prince
 */ 
#include "asf.h"
#include "testFunctions.h"
#include "PWMCustom.h"
#include "global_variables.h"
#include "ADCCustom.h"
#include "delay.h"


// Cycles between 0,50 and 100% Duty Cycle on PWM
void testFans()
{
	portTickType xLastWakeTime = xTaskGetTickCount();
	const portTickType xFrequency = 5000; // Run every few seconds
	vTaskDelayUntil(&xLastWakeTime,xFrequency);
	PWMDutyCycle(100);
	printf("100\n");
	
	vTaskDelayUntil(&xLastWakeTime,xFrequency);
	PWMDutyCycle(0);
	printf("0\n");
	
	vTaskDelayUntil(&xLastWakeTime,xFrequency);
	PWMDutyCycle(50);
	printf("50\n");
}

void blinkTest()
{
	ioport_set_pin_dir(LED13, IOPORT_DIR_OUTPUT);
	
	int delay = 1000000;
	
	for(int i=0; i < delay; i++){
		ioport_set_pin_level(LED13, HIGH);

	}
	for (int i=0; i < delay; i++){
		
		ioport_set_pin_level(LED13, LOW);
	}
}

// void calibrate()
// {
// 	PWMDutyCycle(100);
// 	maxValue = ADCReadSensor();
// 	
// 	PWMDutyCycle(0);
// 	minValue = ADCReadSensor();
// }

void testReceive()
{
	//if(testByte == 0){
	while (!uart_is_rx_ready (CONF_UART)){
		printf("%i\n", a);
	};
	uart_read(CONF_UART, &testByte);
	// }
	delay_ms(100);
	if(testByte > 0)
	{
		ioport_set_pin_level(LEDUART, HIGH);
	}

	printf("%i\n", testByte);
}
void testSend()
{
	aRead = ADCReadSensor();
	printf("%i\n", aRead);
	delay_ms(100);
	
}