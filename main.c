/**
 * \file
 *
 * \brief Empty user application template
 *
 */

/**
 * \mainpage User Application template doxygen documentation
 *
 * \par Empty user application template
 *
 * Bare minimum empty user application template
 *
 * \par Content
 *
 * -# Include the ASF header files (through asf.h)
 * -# "Insert system clock initialization code here" comment
 * -# Minimal main function that starts with a call to board_init()
 * -# "Insert application code here" comment
 *
 */

/*
 * Include header files for all drivers that have been imported from
 * Atmel Software Framework (ASF).
 */
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */
#include <asf.h>
#include "ADCCustom.h"
#include "PIDRegulation.h"
#include "PWMCustom.h"
#include "SerialComTask.h"
#include "testFunctions.h"
#include "UARTFunctions.h"
#include "uart.h"


int main (void){
	/* Initialize the Arduino Due system */
	sysclk_init();
	board_init();
	ioport_init();
		
	ADCSetup();

	ioport_set_pin_dir(LED13, IOPORT_DIR_OUTPUT);
	ioport_set_pin_level(LED13, LOW);
	// int32_t value;
	
/*	setupUART();*/
//	setupSTDIO();
	
	int testByte = 10;

while (1)
{	

}
				
// 		value = ADCReadSensor();
// 		printf("%i\n", value);
		 		

	}
