/*
* global_variables.h
*
* Created: 2015-08-20 21:41:35
*  Author: Stefan
*/


#ifndef GLOBAL_VARIABLES_H_
#define GLOBAL_VARIABLES_H_

#include "asf.h"

//Defines constants for PID
#define P_CONSTANT 8
#define I_CONSTANT 0
#define D_CONSTANT 0

//Defines the setpoint(s) for the PID
#define DISTANCE_SET 1300
// TODO - Measure the distances on the rig line and #define fixed distance points

// PWM
extern pwm_channel_t pwm_channel_instance;

//ADC
extern int32_t distance;

// PID
extern int32_t output_value;

//LOGVARIABLE


#endif /* GLOBAL_VARIABLES_H_ */