/*
 * PIDRegulation.c
 *
 * Created: 2015-10-10 16:05:52
 *  Author: Stefan and Prince
 */ 


#include <asf.h>
#include "PIDRegulation.h"
#include "inttypes.h"
#include "PWMCustom.h"
#include "ADCCustom.h"
#include "global_variables.h"
#include "UARTFunctions.h"



void PIDRegulationTask (void *pvParameters)
{
	portTickType xLastWakeTime = xTaskGetTickCount();
	const portTickType xFrequency = 100; // Run every few ms
	
	for(;;){
		
		//testFans(); // Gets stuck in this function which just test fans
		
		vTaskDelayUntil(&xLastWakeTime,xFrequency);	// Samplingstime
		getPIDValues();
		setPIDValues();
		PIDRegulate(); // Run PID
	}
}

// P-regulator used for Ziegler-Nichols method
void PRegulate(void){
	
	// Read raw sensor distance from ADC
	distance = ADCReadSensor();
	
	// Calculate error
	error = distanceSet - distance;
	
	// Calculate P, convert to procentage for the PWM
	output_value = (((double)P_CONSTANT * error) / 4095) / 100;
	
	// Make sure the values do not exceed the PWM Duty Cycle range (0-100%)
	if (output_value <= 0)
	{
		output_value = 0;
	}
	else if (output_value >= 100)
	{
		output_value = 100;
	}

// 	// Convert output value to procentage for the PWM
	output_value = (output_value * 100) / 4095;
	
	// Write output_value to PWM
	PWMDutyCycle(output_value);
}

// PID function
void PIDRegulate(void){
	
	// Read raw sensor distance from ADC
	distance = ADCReadSensor();

	// error values
	error = distanceSet - distance;
	
	P_SET = (double) error;
	I_SET += (double) old_error * dTime;
	D_SET = (double) (error - old_error) * dTime;

	old_error = error;
		
	output_value = (double) ((P_CONSTANT * P_SET) + (I_CONSTANT*I_SET) + (D_CONSTANT*D_SET));

	// Convert output value to percentage for the PWM
	output_value = (uint8_t) ((output_value * 100) / 4095);
	
	// Make sure the values do not exceed the PWM Duty Cycle range (0-100%)
	if (output_value <= 0)
	{
		output_value = 0;
	}
	else if (output_value >= 100)
	{
		output_value = 100;
	}
		
	// Send the output_value to fan
	PWMDutyCycle(output_value);
}