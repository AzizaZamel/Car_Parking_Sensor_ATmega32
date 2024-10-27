/*
 ============================================================================
 Name        : ATmega32_Registers.h
 Author      : Aziza Zamel
 Description : Header file for ATmega32 Registers Declaration
 Date        : 25/9/2024
 ============================================================================
 */


#ifndef ATMEGA32_REGISTERS_H_
#define ATMEGA32_REGISTERS_H_

#include "ATmega32_register_unions.h"


/*********************************** GPIO Registers Definitions ********************************/
#define PORTA_REG     (*(volatile GPIO_Reg_Type * const)0x3B)
#define DDRA_REG      (*(volatile GPIO_Reg_Type * const)0x3A)
#define PINA_REG      (*(volatile const GPIO_Reg_Type * const)0x39)

#define PORTB_REG     (*(volatile GPIO_Reg_Type * const)0x38)
#define DDRB_REG      (*(volatile GPIO_Reg_Type * const)0x37)
#define PINB_REG      (*(volatile const GPIO_Reg_Type * const)0x36)

#define PORTC_REG     (*(volatile GPIO_Reg_Type * const)0x35)
#define DDRC_REG      (*(volatile GPIO_Reg_Type * const)0x34)
#define PINC_REG      (*(volatile const GPIO_Reg_Type * const)0x33)

#define PORTD_REG     (*(volatile GPIO_Reg_Type * const)0x32)
#define DDRD_REG      (*(volatile GPIO_Reg_Type * const)0x31)
#define PIND_REG      (*(volatile const GPIO_Reg_Type * const)0x30)
/***********************************************************************************************/


/*********************************** ADC Registers Definitions ********************************/
#define ADMUX_REG     (*(volatile ADC_ADMUX_Type * const)0x27)
#define ADCSRA_REG    (*(volatile ADC_ADCSRA_Type * const)0x26)
#define ADC_REG       (*(volatile ADC_Data_Type * const)0x24)

/***********************************************************************************************/

#define SREG_REG     (*(volatile SREG_Type * const)0x5F)

/***********************************************************************************************/


/*********************************** Timer0 Registers Definitions ******************************/
#define TCCR0_REG     (*(volatile Timer0_TCCR0_Type * const)0x53)
#define TCNT0_REG     (*(volatile Timer0_TCNT0_Type * const)0x52)
#define OCR0_REG     (*(volatile Timer0_OCR0_Type * const)0x5C)
#define TIFR_REG      (*(volatile Timers_TIFR_Type * const)0x58)
#define TIMSK_REG     (*(volatile Timers_TIMSK_Type * const)0x59)

/***********************************************************************************************/


/*********************************** Timer1 Registers Definitions ******************************/
#define TCNT1_REG     (*(volatile Timer1_TCNT1_Type * const)0x4C)
#define TCCR1A_REG    (*(volatile Timer1_TCCR1A_Type * const)0x4F)
#define TCCR1B_REG    (*(volatile Timer1_TCCR1B_Type * const)0x4E)
#define OCR1A_REG     (*(volatile Timer1_OCR1A_Type * const)0x4A)
#define OCR1B_REG     (*(volatile Timer1_OCR1B_Type * const)0x48)
#define ICR1_REG      (*(volatile Timer1_ICR1_Type * const)0x46)
/***********************************************************************************************/


#endif /* ATMEGA32_REGISTERS_H_ */
