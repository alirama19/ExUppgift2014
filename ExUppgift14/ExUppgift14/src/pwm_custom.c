/*
* pwm_custom.c
*
* Created: 2015-08-20 21:06:01
*  Author: Stefan
*/
#include <asf.h>
#include "pwm_custom.h"
#include "global_variables.h"
#include "config/conf_board.h"
#include "config/conf_clock.h "

void fan_motor_control_init(void)
{
	pmc_enable_periph_clk(ID_PIOD);
	pmc_enable_periph_clk(ID_PIOC);
	pio_set_output(PIOD, PIO_PD8, HIGH, DISABLE, ENABLE); // Set direction according to "+" and "-" pins on the shield(pin 12 on Due)
	pio_set_output(PIOC, PIO_PC21, LOW, DISABLE, ENABLE); // Disable break-function on the shield(pin 9 on Due)
	
	pmc_enable_periph_clk(ID_PWM);
	pwm_channel_disable(PWM, PWM_CHANNEL_6);
	pwm_clock_t pwm_clock ={
		.ul_clka = 1000*100,
		.ul_clkb = 0,
		.ul_mck = 84000000
	};
	pwm_init(PWM, &pwm_clock);
	
	pwm_channel_instance.alignment = PWM_ALIGN_LEFT;
	pwm_channel_instance.polarity = PWM_LOW;
	pwm_channel_instance.ul_prescaler = PWM_CMR_CPRE_CLKA;
	pwm_channel_instance.ul_duty = 0;
	pwm_channel_instance.ul_period = 100;
	pwm_channel_instance.channel = PWM_CHANNEL_6;
	pwm_channel_init(PWM, &pwm_channel_instance);
	pwm_channel_enable(PWM, PWM_CHANNEL_6);
	
}