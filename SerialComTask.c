/*
 * SerialComTask.c
 *
 * Created: 2015-10-10 16:06:32
 *  Author: Stefan and Prince
 */ 

#include <asf.h>
#include "SerialComTask.h"
#include "ADCCustom.h"
#include "PWMCustom.h"
#include "PIDRegulation.h"

// void SerialComTask (void *pvParameters)
// {
// 	portTickType xLastWakeTime = xTaskGetTickCount();
// 	const portTickType xFrequency = 300; // Run every few ms
// 	
// 	for(;;){
// 		vTaskDelayUntil(&xLastWakeTime,xFrequency);
// 		printf("%c", 'V');
// 		printf("%u" "\n", output_value);
// 		
// 		printf("%c", 'D');
// 		printf("%u" "\n", distance);
// 	}
// }