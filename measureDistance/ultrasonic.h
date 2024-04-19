 /******************************************************************************
 *
 * Module: ICU
 *
 * File Name: icu.h
 *
 * Description: Header file for the AVR ICU driver
 *
 * Author: Zyad Montaser
 *
 *******************************************************************************/
#include "std_types.h"

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/
#define ULTRASONIC_TIRGGER_PORT_ID   PORTB_ID
#define ULTRASONIC_TIRGGER_PIN_ID    PIN5_ID

#define ULTRASONIC_ECHO_HIGH_TIME_NOT_READY    -1

#define ULTRASONIC_ECHO_PORT_ID      PORTD_ID
#define ULTRASONIC_ECHO_PIN_ID		 PIN6_ID

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*function responsible for initialize the icu and set its callback function */
void Ultrasonic_init(void);

/*function responsible for send trigger pulse on the trigger pin*/
void Ultrasonic_Trigger(void);

/*function responsible for calculate the distance*/
uint16 Ultrasonic_readDistance(void);

/*call back function which is responsible for calculate the high time (pulse time) on echo pin*/
void Ultrasonic_edgeProcessing(void);



#endif /* ULTRASONIC_H_ */
