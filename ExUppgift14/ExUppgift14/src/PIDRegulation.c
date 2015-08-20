/*
* PIDRegulation.c
*
* Created: 2015-08-20 19:16:01
*  Author: Stefan
*/
#include "asf.h"
#include "PIDRegulation.h"
#include "adc_custom.h"
#include "pwm_custom.h"
#include "inttypes.h"
#include "global_variables.h"

void PIDRegulationTask (void *pvParameters)
{
	portTickType xLastWakeTime;
	xLastWakeTime = xTaskGetTickCount();
	const portTickType xFrequency = 100; // Run every 100ms
	//const portTickType xFrequency = 2000; // Run every 2 seconds
	
	for(;;){
		vTaskDelayUntil(&xLastWakeTime,xFrequency);
		adc_start(ADC);
		while((adc_get_status(ADC) & 0x1<<24)==0);  // Wait until DRDY(Data Ready) is HIGH
		unsigned int result = (adc_get_channel_value(ADC, ADC_CHANNEL_10));
		printf("%u" "\n", result);
		
		// 		vTaskDelayUntil(&xLastWakeTime,xFrequency);
		// 		pwm_channel_update_duty(PWM, &pwm_channel_instance, 100);
		
		// 		vTaskDelayUntil(&xLastWakeTime,xFrequency);
		// 		pwm_channel_update_duty(PWM, &pwm_channel_instance, 0);
		
		//		vTaskDelayUntil(&xLastWakeTime,xFrequency);
		//		pwm_channel_update_duty(PWM, &pwm_channel_instance, 50);
	}
}