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

// PID
int DISTANCE_SET = 0;

int32_t P_CONSTANT = 0;
int32_t I_CONSTANT = 0;
int32_t D_CONSTANT = 0;

int32_t error = 0;
int32_t errSum = 0;
int32_t dErr = 0;
int32_t lastErr = 0;

int32_t dTime = 0;

//ADC
int distance = 0;
int32_t output_value = 0;

void PIDRegulationTask (void *pvParameters)
{
	portTickType xLastWakeTime = xTaskGetTickCount();
	const portTickType xFrequency = 1; // Run every few ms
	
	for(;;){
		
		//testFans(); // Gets stuck in this function which just test fans
		
		vTaskDelayUntil(&xLastWakeTime,xFrequency);	// Samplingstime
		
		PIDRegulate(); // Run PID
	}
}

// P-regulator used for Ziegler-Nichols method
void PRegulate(void){
	
	// Read raw sensor distance from ADC
	distance = ADCReadSensor();
	
	// Calculate error
	error = DISTANCE_SET - distance;
	
	// Calculate P, convert to procentage for the PWM
	output_value = (((int32_t)P_CONSTANT * error) / 4095) / 100;
	
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
	error = DISTANCE_SET - distance;
	errSum += (error + dTime);
	dErr = (error - lastErr) / dTime;
	
	output_value = P_CONSTANT * error + I_CONSTANT * errSum + D_CONSTANT * dErr;

	// Make sure the values do not exceed the PWM Duty Cycle range (0-100%)
	if (output_value <= 0)
	{
		output_value = 0;
	}
	else if (output_value >= 100)
	{
		output_value = 100;
	}

	// Convert output value to procentage for the PWM
	output_value = (output_value * 100) / 4095;
	
	// Send the output_value to fan
	PWMDutyCycle(output_value);
}