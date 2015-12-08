/*
 * global_variables.c
 *
 * Created: 2015-12-07 00:18:21
 *  Author: Stefan
 */ 
#include <asf.h>

/* PID */
// Values that will be received from Matlab
uint8_t p_temp;
uint8_t i_temp;
uint8_t d_temp;

// Processed values for the PID regulator, p_temp / divider ..
double P_CONSTANT;
double I_CONSTANT;
double D_CONSTANT;

double P_SET;
double I_SET;
double D_SET;

// Divider value, will be 10, is used in junction with the received values above to process into doubles for the PID
uint8_t divider = 10;

double PID;

uint8_t error;
uint8_t old_error;

uint8_t distanceSet;
uint8_t distanceSet_temp;

uint8_t dTime;


/* ADC */
uint8_t distance;

/* PWM */
uint8_t output_value;

/* Test variables */
int a;
uint8_t testByte;
int aRead;
