/*
 * global_variables.h
 *
 * Created: 2015-12-07 00:18:34
 *  Author: Stefan
 */ 


#ifndef GLOBAL_VARIABLES_H_
#define GLOBAL_VARIABLES_H_

/* PID */
// Values that will be received from Matlab
extern uint8_t p_temp;
extern uint8_t i_temp;
extern uint8_t d_temp;

// Processed values for the PID regulator, p_temp / divider ..
extern double P_CONSTANT;
extern double I_CONSTANT;
extern double D_CONSTANT;

extern double P_SET;
extern double I_SET;
extern double D_SET;

extern double PID;

extern uint8_t error;
extern uint8_t old_error;

// Divider value, will be 10, is used in junction with the received values above to process into doubles for the PID
extern uint8_t divider;

extern uint8_t distanceSet;
extern uint8_t distanceSet_temp;

extern uint8_t dTime;

/* ADC */
extern uint8_t distance;

/* PWM */
extern uint8_t output_value;

/* Test variables */
extern int a;
extern uint8_t testByte;
extern int aRead;

#endif /* GLOBAL_VARIABLES_H_ */