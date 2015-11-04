/*
 * testFunctions.c
 *
 * Created: 2015-10-10 16:06:54
 *  Author: Stefan and Prince
 */ 


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