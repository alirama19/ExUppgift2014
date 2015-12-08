/*
 * UARTFunctions.h
 *
 * Created: 2015-11-14 01:49:50
 *  Author: Stefan
 */ 


#ifndef UARTFUNCTIONS_H_
#define UARTFUNCTIONS_H_

int receiveByte(void);
void configure_console(void);
void getPIDValues(void);
void setPIDValues(void);
void setupSTDIO(void);

#define TASK_SerialComTask_STACK_SIZE (2048/sizeof(portSTACK_TYPE))
#define TASK_SerialComTask_STACK_PRIORITY (4)

void SerialComTask (void *pvParameters);

#endif /* UARTFUNCTIONS_H_ */