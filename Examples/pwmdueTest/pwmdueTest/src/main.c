#include <asf.h>
#include "delay.h"
#include "config/conf_board.h"
#include "config/conf_clock.h "
pwm_channel_t pwm_channel;

static void configure_console(void)
{
	const usart_serial_options_t uart_serial_options = { .baudrate =
	CONF_UART_BAUDRATE, .paritytype = CONF_UART_PARITY };
	/* Konfigurera konsol UART. */
	sysclk_enable_peripheral_clock(CONSOLE_UART_ID);
	stdio_serial_init(CONF_UART, &uart_serial_options);
	
	/* configure RX0 pin as pull-up - this is tailored towards use with Matlab*/
	ioport_set_pin_mode(PIO_PA8_IDX, IOPORT_MODE_PULLUP);
}

int main (void)
{
	// Insert system clock initialization code here (sysclk_init()).
	sysclk_init();
	board_init();

	delay_init();
	configure_console(); // Initialize UART
	// Insert application code here, after the board has been initialized.
	
	pmc_enable_periph_clk(ID_PWM);
	pwm_channel_disable(PWM, PWM_CHANNEL_6);
	pwm_clock_t pwm_clock ={
		.ul_clka = 1000*100,
		.ul_clkb = 0,
		.ul_mck = 84000000
	};
	pwm_init(PWM, &pwm_clock);
	
	pwm_channel.alignment = PWM_ALIGN_LEFT;
	pwm_channel.polarity = PWM_LOW;
	pwm_channel.ul_prescaler = PWM_CMR_CPRE_CLKA;
	pwm_channel.ul_duty = 0;
	pwm_channel.ul_period = 100;
	pwm_channel.channel = PWM_CHANNEL_6;
	pwm_channel_init(PWM, &pwm_channel);
	pwm_channel_enable(PWM, PWM_CHANNEL_6);
	
	while(1)
	{

		delay_ms(1000);
		pwm_channel_update_duty(PWM, &pwm_channel, 0);
		printf("0\n");
		
		delay_ms(1000);
		pwm_channel_update_duty(PWM, &pwm_channel, 50);
		printf("50\n");
		
		delay_ms(1000);
		pwm_channel_update_duty(PWM, &pwm_channel, 100);
		printf("100\n");
	}
}