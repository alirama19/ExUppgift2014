/*
 * global_variables.c
 *
 * Created: 2015-10-10 16:04:06
 *  Author: Stefan and Prince
 */ 

#include "Global_variables.h"

// ADC
int32_t distance = 0;

// PID
int32_t error = 0;
int32_t errSum = 0;
int32_t dErr = 0;
int32_t lastErr = 0;

int32_t dTime = 0;

int32_t output_value = 100;