/*
 * PWMCustom.c
 *
 * Created: 2015-10-03 11:40:04
 *  Author: Stefan
 */ 

#include "asf.h"
#include "PWMCustom.h"

pwm_channel_t pwm_pin6_instance;

void PWMSetup(void){
	pmc_enable_periph_clk(ID_PWM);

	pwm_clock_t clock_setting = {
		.ul_clka = 1000 * 1000,
		.ul_clkb = 0,
		.ul_mck = sysclk_get_cpu_hz()
	};
	pwm_init(PWM, &clock_setting);
}

void PWMEnableCustomPin(void){
	//PWM on Arduino pin 8
	pwm_channel_disable(PWM, PWM_CHANNEL_6);
	pwm_pin6_instance.ul_prescaler = PWM_CMR_CPRE_CLKA;
	pwm_pin6_instance.ul_period = 100;
	pwm_pin6_instance.ul_duty = 0;
	pwm_pin6_instance.channel = PWM_CHANNEL_6;
	pwm_channel_init(PWM, &pwm_pin6_instance);
	pio_set_peripheral(PIOC, PIO_PERIPH_B, PIO_PC24B_PWML7);
	pwm_channel_enable(PWM, PWM_CHANNEL_6);
}

void motorShield_init(void){
	pmc_enable_periph_clk(ID_PIOD);
	pmc_enable_periph_clk(ID_PIOC);
	pio_set_output(PIOD, PIO_PD8, HIGH, DISABLE, ENABLE); // Set direction according to "+" and "-" pins on the shield(pin 12 on Due)
	pio_set_output(PIOC, PIO_PC21, LOW, DISABLE, ENABLE); // Disable break-function on the shield(pin 9 on Due)
	
	pmc_enable_periph_clk(ID_PWM);
	pwm_channel_disable(PWM, PWM_CHANNEL_6);
}