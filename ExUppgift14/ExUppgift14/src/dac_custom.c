/*
*
* Created: 2013-11-25 16:16:35
* Author: Tommy
*
* Modified by Stefan Angelov
*
*/

#include "asf.h"
#include "dac_custom.h"

void dac_setup(void)
{
	pmc_enable_periph_clk(ID_DACC);
	dacc_reset(DACC);
	dacc_set_transfer_mode(DACC, 0);
	dacc_set_timing(DACC,1,1,0);			// param: DACC, refresh period, max speed, startup time
	
	dacc_set_channel_selection(DACC,0);		// Set DAC channel to DAC0
	dacc_enable_channel(DACC, 0);			// Enable DAC0
}