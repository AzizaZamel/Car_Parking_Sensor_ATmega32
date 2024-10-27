/*
 ============================================================================
 Name        : ultrasonic.c
 Author      : Aziza Zamel
 Description : Source file for the Ultrasonic Sensor Driver
 Date        : 8/10/2024
 ============================================================================
 */

#include "ultrasonic.h"
#include "icu.h"
#include "gpio.h"
#include "util/delay.h"



/*******************************************************************************
 *                           Global Variables                                  *
 *******************************************************************************/

static uint8 g_edgeCount = 0;
static uint16 g_timeHigh = 0;



/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*
 * Description : Function to initialize the Ultrasonic sensor
 * 	1. Initialize the ICU driver as required.
 * 	2. Set up the ICU callback function.
 * 	3. Set the direction for the trigger pin as output through the GPIO driver.
 */
void Ultrasonic_init(void) {

	/* Create configuration structure for ICU driver */
	ICU_ConfigType ICU_Configurations = { F_CPU_8, RAISING };

	/* Set the Call back function pointer in the ICU driver */
	ICU_setCallBack(Ultrasonic_edgeProcessing);

	/* Initialize both the ICU driver */
	ICU_init(&ICU_Configurations);

	/* configure trigger pin as output pin */
	GPIO_setupPinDirection(ULTRASONIC_TRIG_PORT_ID, ULTRASONIC_TRIG_PIN_ID,
			PIN_OUTPUT);

	/* Initialize the trigger pin by zero */
	GPIO_writePin(ULTRASONIC_TRIG_PORT_ID, ULTRASONIC_TRIG_PIN_ID, LOGIC_LOW);
}


/*
 * Description :
 * Function responsible for Send the trigger pulse to the ultrasonic sensor.
 */
void Ultrasonic_Trigger(void){
	GPIO_writePin(ULTRASONIC_TRIG_PORT_ID,ULTRASONIC_TRIG_PIN_ID,LOGIC_HIGH);
	_delay_us(10);
	GPIO_writePin(ULTRASONIC_TRIG_PORT_ID,ULTRASONIC_TRIG_PIN_ID,LOGIC_LOW);
}

/*
 * Description :
 * Function responsible for:
 * 1. Send the trigger pulse by using the Ultrasonic_Trigger function.
 * 2. Start the measurement process via the ICU driver.
 */
uint16 Ultrasonic_readDistance(void){
	/* Send the trigger pulse */
	Ultrasonic_Trigger();
	for(;;){
		if(g_edgeCount == 2){
			g_edgeCount = 0;
			/* The distance of Object (in cm) = 340000*time/2 =17000 * time
			 *  frequency for ATmega32 = 16Mhz, with Prescaler F_CPU/8  for timer frequency
			 *  Then time to execute 1 instruction is 0.5 us.
			 *  then time = TIMER_value * 5 * 10^-7
			 *  then distance in cm = TIMER_value * 0.0085
			 *  and add 0.5 to round the result
		     */
//			return g_timeHigh * 0.0085 + 0.5;
			return ((uint32)g_timeHigh * 85 + 5000) / 10000;
		}
	}
}



/*
 * Description :
 * This is the callback function called by the ICU driver.
 * It calculates the high time (pulse time) generated by the ultrasonic sensor.
 */
void Ultrasonic_edgeProcessing(void) {
	g_edgeCount++;
	if (g_edgeCount == 1) {
		/*
		 * Clear the timer counter register to start measurements from the
		 * first detected rising edge
		 */
		ICU_clearTimerValue();

		/* Detect falling edge */
		ICU_setEdgeDetectionType(FALLING);
	}
	else if (g_edgeCount == 2) {
		/* Store the High time value */
		g_timeHigh = ICU_getInputCaptureValue();

		/* Clear the timer counter register to start measurements again */
		ICU_clearTimerValue();

		/* Detect rising edge */
		ICU_setEdgeDetectionType(RAISING);
	}
}

