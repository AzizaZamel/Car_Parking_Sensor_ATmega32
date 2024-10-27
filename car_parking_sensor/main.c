/*
 ============================================================================
 Name        : main.c
 Author      : Aziza Zamel
 Description : Car Parking Sensor System
 Date        : 8/10/2024
 ============================================================================
 */
#include "lcd.h"
#include "led.h"
#include "buzzer.h"
#include "ultrasonic.h"
#include "ATmega32_Registers.h"
#include "std_types.h"
#include "util/delay.h"

int main(void){
	/* Variable to hold the distance */
	uint16 distance = 0;

	/* Enable global interrupt */
	SREG_REG.bits.I_bit=LOGIC_HIGH;

	/* LCD initializations */
	LCD_init();
	LCD_displayString((uint8*)"Distance=   cm");

	/* ultrasonic sensor, buzzer and LEDs initializations */
	Ultrasonic_init();
	Buzzer_init();
	LEDS_init();

	for(;;){
		/* get the distance and display it on the LCD */
		distance = Ultrasonic_readDistance();
		LCD_moveCursor(0,9);
		if(distance >= 100){
			LCD_intgerToString(distance);
		}
		else{
			LCD_intgerToString(distance);
			/* In case the digital value is two or one digits print space in the next digit place */
			LCD_displayCharacter(' ');
		}

		/* if Distance <= 5 cm ,  All LEDs are flashing (Red, Green, Blue), Buzzer sounds, LCD shows "Stop"  */
		if(distance <= 5){
			LCD_displayStringRowColumn(1,6,(uint8*)"STOP");
			Buzzer_on();
			LED_on(RED);
			LED_on(GREEN);
			LED_on(BLUE);
			_delay_ms(250);
			LED_off(RED);
			LED_off(GREEN);
			LED_off(BLUE);
			Buzzer_off();
			_delay_ms(250);
		}
		/* if 6 cm <= Distance <= 10 cm , All LEDs ON (Red, Green, Blue), No buzzer */
		else if(distance <= 10){
			LCD_displayStringRowColumn(1,6,(uint8*)"    ");
			LED_on(RED);
		    LED_on(GREEN);
			LED_on(BLUE);
		}
		/* if 11 cm <= Distance <= 15 cm , Red and Green LEDs ON, Blue LED OFF */
		else if(distance <= 15){
			LCD_displayStringRowColumn(1,6,(uint8*)"    ");
			LED_on(RED);
			LED_on(GREEN);
			LED_off(BLUE);

		}
		/* if 16 cm <= Distance <= 20 cm , Only Red LED ON, others OFF */
		else if(distance <= 20){
			LCD_displayStringRowColumn(1,6,(uint8*)"    ");
			LED_on(RED);
			LED_off(GREEN);
			LED_off(BLUE);
		}
		/* if Distance > 20 cm , All LEDs OFF, Buzzer OFF */
		else{
			LCD_displayStringRowColumn(1,6,(uint8*)"    ");
			LED_off(RED);
			LED_off(GREEN);
			LED_off(BLUE);
		}

	}
}
