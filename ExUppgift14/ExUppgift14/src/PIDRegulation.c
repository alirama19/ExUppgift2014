/*
* PIDRegulation.c
*
* Created: 2015-08-20 19:16:01
*  Author: Stefan
*/
#include <asf.h>
#include "PIDRegulation.h"
#include "adc_custom.h"
#include "dac_custom.h"
#include "inttypes.h"

void PIDRegulationTask (void *pvParameters)
{
	portTickType xLastWakeTime;
	xLastWakeTime = xTaskGetTickCount();
	//const portTickType xFrequency = 50; // Run every 50ms
	const portTickType xFrequency = 2000; // Run every 2 seconds
	
	for(;;){
		//vTaskDelayUntil(&xLastWakeTime,xFrequency);
		// 		adc_start(ADC);
		// 		while((adc_get_status(ADC) & 0x1<<24)==0);  // Wait until DRDY(Data Ready) is HIGH
		// 		uint32_t result = (adc_get_channel_value(ADC, ADC_CHANNEL_7));
		// 		printf("%" PRIu32 "\n", result);

 		dacc_write_conversion_data(DACC, 3300);
  		vTaskDelayUntil(&xLastWakeTime,xFrequency);
	}
}