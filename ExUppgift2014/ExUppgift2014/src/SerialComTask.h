/*
 * SerialComTask.h
 *
 * Created: 2015-11-04 18:14:42
 *  Author: Stefan and Prince
 */ 


#ifndef SERIALCOMTASK_H_
#define SERIALCOMTASK_H_

#define TASK_SerialComTask_STACK_SIZE (2048/sizeof(portSTACK_TYPE))
#define TASK_SerialComTask_STACK_PRIORITY (4)

void SerialComTask (void *pvParameters);
#endif /* SERIALCOMTASK_H_ */