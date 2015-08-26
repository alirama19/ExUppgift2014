/*
* SerialComTask.c
*
* Created: 2015-08-26 12:46:17
*  Author: Datorlabbstudent
*/

#include "asf.h"
#include "SerialComTask.h"
#include "global_variables.h"

void SerialComTask (void *pvParameters)
{

	portTickType xLastWakeTime = xTaskGetTickCount();
	const portTickType xFrequency = 300; // Run every few ms
	
	for(;;){
		vTaskDelayUntil(&xLastWakeTime,xFrequency);
		printf("%c", 'V');
		printf("%u" "\n", output_value);
		
		printf("%c", 'D');
		printf("%u" "\n", distance);
	}
}