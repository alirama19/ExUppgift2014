/*
 * testFunctions.h
 *
 * Created: 2015-10-10 16:07:07
 *  Author: Stefan and Prince
 */ 


#ifndef TESTFUNCTIONS_H_
#define TESTFUNCTIONS_H_

#define LED13 PIO_PB27_IDX
#define LEDUART PIO_PB21_IDX

void testFans(void);
void testUARTr(void);
void blinkTest(void);
void testReceive(void);
void testSend(void);

#endif /* TESTFUNCTIONS_H_ */
