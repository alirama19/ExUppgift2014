/*
* global_variables.h
*
* Created: 2015-08-20 21:41:35
*  Author: Stefan
*/


#ifndef GLOBAL_VARIABLES_H_
#define GLOBAL_VARIABLES_H_

#include "asf.h"

//Defines which is used for the PID-regulation
#define P_VALUE_SET 8

//Defines which is used for the PID-regulation
#define DISTANCE_SET 1300

// PWM
extern pwm_channel_t pwm_channel_instance;

//ADC
extern int32_t distance;

// PID
extern int32_t output_value;

//LOGVARIABLE


#endif /* GLOBAL_VARIABLES_H_ */