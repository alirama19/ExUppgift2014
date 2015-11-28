/*
 * PWMCustom.c
 *
 * Created: 2015-10-10 16:06:06
 *  Author: Stefan and Prince
 */ 
#include <asf.h>
#include "PWMCustom.h"

pwm_channel_t pwm_pin8_instance;

void PWMSetup(){
	pmc_enable_periph_clk(ID_PWM);

	pwm_clock_t clock_setting = {
		.ul_clka = 1000 * 1000,
		.ul_clkb = 0,
		.ul_mck = sysclk_get_cpu_hz()
	};
	pwm_init(PWM, &clock_setting);
}

void PWMEnableCustomPin(){
	// PWM on Arduino pin 8
	pwm_channel_disable(PWM, PWM_CHANNEL_7);
	pwm_pin8_instance.ul_prescaler = PWM_CMR_CPRE_CLKA;
	pwm_pin8_instance.ul_period = 100;
	pwm_pin8_instance.ul_duty = 0;
	pwm_pin8_instance.channel = PWM_CHANNEL_7;
	pwm_channel_init(PWM, &pwm_pin8_instance);
	pio_set_peripheral(PIOC, PIO_PERIPH_B, PIO_PC24B_PWML7);
	pwm_channel_enable(PWM, PWM_CHANNEL_7);
}

void PWMDutyCycle(uint8_t value){
	pwm_channel_update_duty(PWM, &pwm_pin8_instance, value);
}

void motorShield_init(void){
	pmc_enable_periph_clk(ID_PIOD);
	pmc_enable_periph_clk(ID_PIOC);
	pio_set_output(PIOD, PIO_PD8, HIGH, DISABLE, ENABLE); // Set direction according to "+" and "-" pins on the shield(pin 12 on Due)
	pio_set_output(PIOC, PIO_PC21, LOW, DISABLE, ENABLE); // Disable break-function on the shield(pin 9 on Due)
	
	pmc_enable_periph_clk(ID_PWM);
	pwm_channel_disable(PWM, PWM_CHANNEL_7);
}