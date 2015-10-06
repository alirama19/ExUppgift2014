/*
 * ADCCustom.c
 *
 * Created: 10/6/2015 1:27:14 AM
 *  Author: Stefan Angelov
 */ 

#include "asf.h"
#include "ADCCustom.h"

void ADCSetup()
{
	pmc_enable_periph_clk(ID_ADC);
	adc_init(ADC, sysclk_get_main_hz(), 2000000, 0);		// Configure for maximum frequency @ 84 MHz
	adc_configure_timing(ADC, 0, 0, 0);
	adc_set_resolution(ADC, ADC_MR_LOWRES_BITS_12);			// 0-4095
	adc_configure_trigger(ADC, ADC_TRIG_SW, 0);				// trig just by software
	adc_enable_channel(ADC, ADC_CHANNEL_10);				// PB17 - AD8 for Arduino Due
}

// Read value from sensor
void ADCReadSensor(){
	adc_start(ADC);
	while((adc_get_status(ADC) & 0x1<<24)==0);  // Wait until DRDY(Data Ready) is HIGH
	return (adc_get_channel_value(ADC, ADC_CHANNEL_10));

}