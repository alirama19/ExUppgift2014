/*
 * global_variables.c
 *
 * Created: 2015-08-26 12:43:20
 *  Author: Datorlabbstudent
 */ 

#include "Global_variables.h"

// PWM
pwm_channel_t pwm_channel_instance;

// ADC
int32_t distance = 0;

// PID
int32_t error = 0;
int32_t errSum = 0;
int32_t dErr = 0;
int32_t lastErr = 0;

int32_t dTime = 0;

int32_t output_value = 100;