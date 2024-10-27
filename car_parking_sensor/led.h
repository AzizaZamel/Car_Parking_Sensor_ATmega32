/*
 ============================================================================
 Name        : led.h
 Author      : Aziza Zamel
 Description : Header file for the LED Driver
 Date        : 4/10/2024
 ============================================================================
 */
#ifndef LED_H_
#define LED_H_


/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/* LEDs HW Ports and Pins Ids and type of connection */
#define LED_RED_PORT_ID				PORTC_ID
#define LED_RED_PIN_ID				PIN0_ID
#define LED_RED_CONNECTION          POSITIVE

#define LED_GREEN_PORT_ID			PORTC_ID
#define LED_GREEN_PIN_ID			PIN1_ID
#define LED_GREEN_CONNECTION        POSITIVE

#define LED_BLUE_PORT_ID			PORTC_ID
#define LED_BLUE_PIN_ID				PIN2_ID
#define LED_BLUE_CONNECTION         POSITIVE


#if(LED_RED_CONNECTION == POSITIVE)

#define LED_RED_ON					LOGIC_HIGH
#define LED_RED_OFF					LOGIC_LOW


#elif(LED_RED_CONNECTION == NEGATIVE)

#define LED_RED_ON					LOGIC_LOW
#define LED_RED_OFF					LOGIC_HIGH

#endif

#if(LED_GREEN_CONNECTION == POSITIVE)

#define LED_GREEN_ON					LOGIC_HIGH
#define LED_GREEN_OFF					LOGIC_LOW

#elif(LED_GREEN_CONNECTION == NEGATIVE)

#define LED_GREEN_ON					LOGIC_LOW
#define LED_GREEN_OFF					LOGIC_HIGH

#endif


#if(LED_BLUE_CONNECTION == POSITIVE)

#define LED_BLUE_ON					LOGIC_HIGH
#define LED_BLUE_OFF				LOGIC_LOW

#elif(LED_BLUE_CONNECTION == NEGATIVE)

#define LED_BLUE_ON					LOGIC_LOW
#define LED_BLUE_OFF				LOGIC_HIGH

#endif



/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/

typedef enum
{
	RED,GREEN,BLUE
}LED_ID;


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/


/*
 * Description :
 * Function responsible for:
 * 1. Initialize all Leds (red, green, blue) pins direction.
 * 2. Turn off all the Leds
 */
void LEDS_init(void);

/*
 * Description :
 * Function responsible for Turns on the specified LED.
 */
void LED_on(LED_ID id);

/*
 * Description :
 * Function responsible for Turns off the specified LED.
 */
void LED_off(LED_ID id);

#endif /* LED_H_ */
