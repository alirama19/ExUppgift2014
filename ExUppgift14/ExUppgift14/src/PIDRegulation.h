/*
* PIDRegulation.h
*
* Created: 2015-08-20 19:16:09
*  Author: Stefan
*/


#ifndef PIDREGULATION_H_
#define PIDREGULATION_H_

//Defines for creation of PIDRegulationTask
#define TASK_PIDRegulation_STACK_SIZE (2048/sizeof(portSTACK_TYPE))
#define TASK_PIDRegulation_STACK_PRIORITY (4)

//Defines which is used for the PID-regulation
#define SETPOINT_MIN			1000
#define SETPOINT_MAX			3000
#define SETPOINT_START			2000
#define P_MIN					2
#define P_MAX					300
#define P_START					8
#define I_MIN					10
#define I_MAX					300
#define I_START					30
#define D_MIN					1
#define D_MAX					20
#define D_START					1

#define MAX_OUTPUT_VALUE	3300
#define MAX_TANK1_VALUE		4000



void PIDRegulationTask (void *pvParameters);
unsigned int read_distance(void);
void testPrintADC();
void testFans();
#endif /* PIDREGULATION_H_ */