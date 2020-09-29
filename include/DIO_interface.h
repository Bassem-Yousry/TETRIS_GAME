/********************************************************************************/
/* Author : Bassem																*/
/* Date   : 21 Aug 2020															*/
/* V01																			*/
/********************************************************************************/

#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

#define HIGH    1
#define LOW     0

#define GPIOA   0
#define GPIOB   1
#define GPIOC   2

#define PIN0      0
#define PIN1      1
#define PIN2      2
#define PIN3      3
#define PIN4      4
#define PIN5      5
#define PIN6      6
#define PIN7      7
#define PIN8      8
#define PIN9      9
#define PIN10     10
#define PIN11     11
#define PIN12     12
#define PIN13     13
#define PIN14     14
#define PIN15     15

#define INPUT_ANLOG               0b0000
#define INPUT_FLOATING            0b0100
#define INPUT_PULLUP_PULLDOWN     0b1000

// For INPUT_PULLUP_PULLDOWN ,use ODR register =1    -> up          ,   0 -> down

//For Speed 10
#define OUTPUT_SPEED_10MHZ_PP     0b0001
#define OUTPUT_SPEED_10MHZ_OD     0b0101
#define OUTPUT_SPEED_10MHZ_AFPP   0b1001
#define OUTPUT_SPEED_10MHZ_AFOD   0b1101

//For Speed 2
#define OUTPUT_SPEED_2MHZ_PP      0b0010
#define OUTPUT_SPEED_2MHZ_OD      0b0110
#define OUTPUT_SPEED_2MHZ_AFPP    0b1010
#define OUTPUT_SPEED_2MHZ_AFOD    0b1110

//For Speed 50
#define OUTPUT_SPEED_50MHZ_PP     0b0011
#define OUTPUT_SPEED_50MHZ_OD     0b0111
#define OUTPUT_SPEED_50MHZ_AFPP   0b1011
#define OUTPUT_SPEED_50MHZ_AFOD   0b1111

void DIO_voidSetPinDirection (u8 Copy_u8Port, u8 Copy_u8Pin , u8 Copy_u8Mode);
void DIO_voidSetPinValue (u8 Copy_u8Port, u8 Copy_u8Pin,u8 Copy_u8Value);
void DIO_voidSetByteValue (u8 Copy_u8Port, u8 Copy_u8Value);
void DIO_voidSetPortValue (u8 Copy_u8Port, u16 Copy_u16Value);
u8 DIO_voidGetPinValue (u8 Copy_u8Port, u8 Copy_u8Pin );





#endif	