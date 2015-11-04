/*
 * PIDRegulation.h
 *
 * Created: 2015-10-10 16:05:39
 *  Author: Stefan and Prince
 */ 


#ifndef PIDREGULATION_H_
#define PIDREGULATION_H_

//Defines for creation of PIDRegulationTask
#define TASK_PIDRegulation_STACK_SIZE (2048/sizeof(portSTACK_TYPE))
#define TASK_PIDRegulation_STACK_PRIORITY (4)

void PIDRegulationTask (void *pvParameters);

void PRegulate(void);
void PIDRegulate(void);

#endif /* PIDREGULATION_H_ */