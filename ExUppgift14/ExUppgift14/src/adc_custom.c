/*
*
* Created: 2013-11-25 16:16:35
* Author: Tommy
*
* Modified by Stefan Angelov
*
*/

#include "asf.h"
#include "adc_custom.h"

void adc_distanceSensor_setup()
{
	pmc_enable_periph_clk(ID_ADC);
	adc_init(ADC, sysclk_get_main_hz(), 1000000, 0);		// Configure for maximum frequency @ 84 MHz
	adc_configure_timing(ADC, 0, 0, 0);
	adc_set_resolution(ADC, ADC_MR_LOWRES_BITS_12);			// Sets resolution to 12 bit ie. 0-4095
	adc_enable_channel(ADC, ADC_CHANNEL_4);				// Pin A3 on Arduino Due
	adc_configure_trigger(ADC, ADC_TRIG_SW, 0);				//trig just by software
}