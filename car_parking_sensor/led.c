/*
 ============================================================================
 Name        : led.c
 Author      : Aziza Zamel
 Description : Source file for the LED Driver
 Date        : 4/10/2024
 ============================================================================
 */
#include "led.h"
#include "gpio.h"


/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/


/*
 * Description :
 * Function responsible for:
 * 1. Initialize all Leds (red, green, blue) pins direction.
 * 2. Turn off all the Leds
 */
void LEDS_init(void){
	/* configure LEDs pins as output pins */
	GPIO_setupPinDirection(LED_RED_PORT_ID,LED_RED_PIN_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(LED_GREEN_PORT_ID,LED_GREEN_PIN_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(LED_BLUE_PORT_ID,LED_BLUE_PIN_ID,PIN_OUTPUT);

	/* turn off all the LEDs */
	GPIO_writePin(LED_RED_PORT_ID,LED_RED_PIN_ID,LED_RED_OFF);
	GPIO_writePin(LED_GREEN_PORT_ID,LED_GREEN_PIN_ID,LED_GREEN_OFF);
	GPIO_writePin(LED_BLUE_PORT_ID,LED_BLUE_PIN_ID,LED_BLUE_OFF);
}

/*
 * Description :
 * Function responsible for Turns on the specified LED.
 */
void LED_on(LED_ID id){
	if(id == RED){
		/* Turn on the red led */
		GPIO_writePin(LED_RED_PORT_ID,LED_RED_PIN_ID,LED_RED_ON);
	}
	else if(id == GREEN){
		/* Turn on the green led */
		GPIO_writePin(LED_GREEN_PORT_ID,LED_GREEN_PIN_ID,LED_GREEN_ON);
	}
	else if(id == BLUE){
		/* Turn on the blue led */
		GPIO_writePin(LED_BLUE_PORT_ID,LED_BLUE_PIN_ID,LED_BLUE_ON);
	}
}

/*
 * Description :
 * Function responsible for Turns off the specified LED.
 */
void LED_off(LED_ID id){
	if(id == RED){
		/* Turn off the red led */
		GPIO_writePin(LED_RED_PORT_ID,LED_RED_PIN_ID,LED_RED_OFF);
	}
	else if(id == GREEN){
		/* Turn off the green led */
		GPIO_writePin(LED_GREEN_PORT_ID,LED_GREEN_PIN_ID,LED_GREEN_OFF);
	}
	else if(id == BLUE){
		/* Turn off the blue led */
		GPIO_writePin(LED_BLUE_PORT_ID,LED_BLUE_PIN_ID,LED_BLUE_OFF);
	}
}
















