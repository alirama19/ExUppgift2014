/*
* PIDRegulation.c
*
* Created: 2015-08-20 19:16:01
*  Author: Stefan
*/
#include <asf.h>
#include "PIDRegulation.h"
#include "adc_custom.h"
#include "pwm_custom.h"
#include "inttypes.h"
#include "global_variables.h"

int32_t uP = 0;
int32_t uI = 0;
int32_t uD = 0;

void PIDRegulationTask (void *pvParameters)
{
	portTickType xLastWakeTime = xTaskGetTickCount();
	const portTickType xFrequency = 50; // Run every few ms
	
	int32_t previousE = 0;
	
	for(;;){
		//testPrintADC();
		//testFans();
		//pwm_channel_update_duty(PWM, &pwm_channel_instance, 100);
		
		// Samplingstiden
		vTaskDelayUntil(&xLastWakeTime,xFrequency);
		
		// P-regulation
		int32_t error = 0;
		distance = read_distance();
		error = DISTANCE_SET - distance; //get the error value of distance sensor
		
		//output_value = (int32_t)(tempP*(uP+uI+uD));
		output_value = (int32_t)tempP*error;
		
		previousE = error;
		
		// Control the motor and make sure the values are not exceed the maximum value
		if (output_value < 0)
		{
			output_value = 0;
		}
		else if (output_value > 100)
		{
			output_value = 100;
		}
		
		//send the output_value to fan
		pwm_channel_update_duty(PWM, &pwm_channel_instance, output_value);
		
	}
}

unsigned int read_distance(void)
{
	adc_start(ADC);
	while((adc_get_status(ADC) & 0x1<<24)==0);  // Wait until DRDY(Data Ready) is HIGH
	return (adc_get_channel_value(ADC, ADC_CHANNEL_10));
}


void testPrintADC(void)
{
	portTickType xLastWakeTime = xTaskGetTickCount();
	const portTickType xFrequency = 300; // Run every 300s
	vTaskDelayUntil(&xLastWakeTime,xFrequency);
	unsigned int distance = read_distance();
	printf("%u" "\n", distance); // Print distance and new line
}

// Cycles between 0,50 and 100% Duty Cycle on PWM
void testFans(void)
{
	portTickType xLastWakeTime = xTaskGetTickCount();
	const portTickType xFrequency = 5000; // Run every few seconds
	vTaskDelayUntil(&xLastWakeTime,xFrequency);
	pwm_channel_update_duty(PWM, &pwm_channel_instance, 100);
	printf("100\n");
	
	vTaskDelayUntil(&xLastWakeTime,xFrequency);
	pwm_channel_update_duty(PWM, &pwm_channel_instance, 0);
	printf("0\n");
	
	vTaskDelayUntil(&xLastWakeTime,xFrequency);
	pwm_channel_update_duty(PWM, &pwm_channel_instance, 50);
	printf("50\n");
}