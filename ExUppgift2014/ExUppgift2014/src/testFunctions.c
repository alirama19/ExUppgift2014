/*
 * testFunctions.c
 *
 * Created: 2015-10-10 16:06:54
 *  Author: Stefan and Prince
 */ 
#include "asf.h"
#include "testFunctions.h"
#include "PWMCustom.h"


// Cycles between 0,50 and 100% Duty Cycle on PWM
void testFans(void)
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

void testUARTr(void){
	ioport_set_pin_dir(LED13, IOPORT_DIR_OUTPUT);
	ioport_set_pin_level(LED13, HIGH);
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