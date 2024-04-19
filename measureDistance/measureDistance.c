 /******************************************************************************
 *
 * Module: measureDistance
 *
 * File Name: measureDistance.c
 *
 * Description: Source file for the application
 *
 * Author: Zyad Montaser
 *
 *******************************************************************************/

#include <avr/io.h> /* To use the SREG register */
#include "ultrasonic.h"
#include "lcd.h"
#include <util/delay.h> /* for delay function*/

int main()
{
	uint16 measured_distance=0;

	/* Enable Global Interrupt I-Bit */
	SREG |= (1<<7);

	/* Initialize both the LCD and Ultrasonic*/
	LCD_init();
	Ultrasonic_init();

	LCD_displayString("Distance= ");

	while(1)
	{
		/*read the distance from the sensor*/
		measured_distance=Ultrasonic_readDistance();

		LCD_moveCursor(0,10);
		LCD_intgerToString(measured_distance);/*display the measured distance on the lcd*/
		LCD_displayString("cm  ");/*display double space to avoid overflow*/

		_delay_ms(100);
	}
}

