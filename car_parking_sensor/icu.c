/*
 ============================================================================
 Name        : icu.c
 Author      : Aziza Zamel
 Description : Source file for the AVR ICU driver
 Date        : 8/10/2024
 ============================================================================
 */
#include "icu.h"
#include "common_macros.h" /* To use the macros like SET_BIT */
#include <avr/interrupt.h> /* For ICU ISR */
#include "ATmega32_Registers.h" /* To use ICU/Timer1 Registers */

/*******************************************************************************
 *                           Global Variables                                  *
 *******************************************************************************/

/* Global variables to hold the address of the call back function in the application */
static volatile void (*g_callBackPtr)(void) = NULL_PTR;

/*******************************************************************************
 *                       Interrupt Service Routines                            *
 *******************************************************************************/

ISR(TIMER1_CAPT_vect)
{
	if(g_callBackPtr != NULL_PTR)
	{
		/* Call the Call Back function in the application after the edge is detected */
		(*g_callBackPtr)(); /* another method to call the function using pointer to function g_callBackPtr(); */
	}
}

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
/*
 * Description : Function to initialize the ICU driver
 * 	1. Set the required clock.
 * 	2. Set the required edge detection.
 * 	3. Enable the Input Capture Interrupt.
 * 	4. Initialize Timer1 Registers
 */
void ICU_init(const ICU_ConfigType * Config_Ptr)
{
	/* Configure ICP1/PD6 as i/p pin */
	DDRD_REG.bits.Bit6 = LOGIC_LOW;

	/* Timer1 always operates in Normal Mode */
	TCCR1A_REG.Byte = LOGIC_LOW;
	TCCR1A_REG.Bits.FOC1A_bit = LOGIC_HIGH;
	TCCR1A_REG.Bits.FOC1B_bit = LOGIC_HIGH;

	/*
	 * insert the required clock value in the first three bits (CS10, CS11 and CS12)
	 * of TCCR1B Register
	 */
	TCCR1B_REG.Bits.CS1_bits = Config_Ptr->clock;

	/*
     * insert the required edge type in ICES1 bit in TCCR1B Register
	 */
	TCCR1B_REG.Bits.ICES1_bit = Config_Ptr->edge;

	/* Initial Value for Timer1 */
	TCNT1_REG.TwoBytes = 0;

	/* Initial Value for the input capture register */
	ICR1_REG.TwoBytes = 0;

	/* Enable the Input Capture interrupt to generate an interrupt when edge is detected on ICP1/PD6 pin */
	TIMSK_REG.Bits.TICIE1_bit = LOGIC_HIGH;
}

/*
 * Description: Function to set the Call Back function address.
 */
void ICU_setCallBack(void(*a_ptr)(void))
{
	/* Save the address of the Call back function in a global variable */
	g_callBackPtr = a_ptr;
}

/*
 * Description: Function to set the required edge detection.
 */
void ICU_setEdgeDetectionType(const ICU_EdgeType a_edgeType)
{
	/*
	 * insert the required edge type in ICES1 bit in TCCR1B Register
	 */
	TCCR1B_REG.Bits.ICES1_bit = a_edgeType;
}

/*
 * Description: Function to get the Timer1 Value when the input is captured
 *              The value stored at Input Capture Register ICR1
 */
uint16 ICU_getInputCaptureValue(void)
{
	return ICR1_REG.TwoBytes;
}

/*
 * Description: Function to clear the Timer1 Value to start count from ZERO
 */
void ICU_clearTimerValue(void)
{
	TCNT1_REG.TwoBytes = 0;
}

/*
 * Description: Function to disable the Timer1 to stop the ICU Driver
 */
void ICU_deInit(void)
{
	/* Clear All Timer1/ICU Registers */
	TCCR1A_REG.Byte = 0;
	TCCR1B_REG.Byte = 0;
	TCNT1_REG.TwoBytes = 0;
	ICR1_REG.TwoBytes = 0;

	/* Disable the Input Capture interrupt */
	TIMSK_REG.Bits.TICIE1_bit = LOGIC_LOW;

	/* Reset the global pointer value */
	g_callBackPtr = NULL_PTR;
}
