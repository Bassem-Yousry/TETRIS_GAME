/********************************************************************************/
/* Author : Bassem																*/
/* Date   : 21 Aug 2020															*/
/* V01																			*/
/********************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"


void DIO_voidSetPinDirection (u8 Copy_u8Port, u8 Copy_u8Pin , u8 Copy_u8Mode){

	switch(Copy_u8Port)
	{
	case GPIOA:

		if(Copy_u8Pin <= 7 )
		{//low

			GPIOA_CRL &= ~ ( ( 0b1111 )    << ( Copy_u8Pin * 4 ));// R M W
			GPIOA_CRL |= ( Copy_u8Mode ) << ( Copy_u8Pin * 4 );

		}
		else if(Copy_u8Pin <=15 )
		{//high

			Copy_u8Pin = Copy_u8Pin - 8;
			GPIOA_CRH &= ~ ( ( 0b1111 )    << ( Copy_u8Pin * 4 ) );
			GPIOA_CRH |= ( Copy_u8Mode ) << ( Copy_u8Pin * 4 );
		}

		break;

	case GPIOB:

		if(Copy_u8Pin <= 7 )
		{//low

			GPIOB_CRL &= ~ ( ( 0b1111 )    << ( Copy_u8Pin * 4 ) );// R M W
			GPIOB_CRL |= ( Copy_u8Mode ) << ( Copy_u8Pin * 4 )  ;

		}
		else if(Copy_u8Pin <=15 )
		{//high
			Copy_u8Pin = Copy_u8Pin - 8;
			GPIOB_CRH &= ~ ( ( 0b1111 )    << ( Copy_u8Pin * 4 ) );
			GPIOB_CRH |= ( Copy_u8Mode ) << ( Copy_u8Pin * 4 )  ;
		}
		break;
	case GPIOC:
		if(Copy_u8Pin <= 7 )
		{//low
			GPIOC_CRL &= ~ ( ( 0b1111 )    << ( Copy_u8Pin * 4 ) );// R M W
			GPIOC_CRL |= ( Copy_u8Mode ) << ( Copy_u8Pin * 4 )  ;
		}
		else if(Copy_u8Pin <=15 )
		{//high
			Copy_u8Pin = Copy_u8Pin - 8;
			GPIOC_CRH &= ~ ( ( 0b1111 )    << ( Copy_u8Pin * 4 ) );
			GPIOC_CRH |= ( Copy_u8Mode ) << ( Copy_u8Pin * 4 )  ;
		}
		break;
	default :break;
	}


}

void DIO_voidSetPinValue (u8 Copy_u8Port, u8 Copy_u8Pin,u8 Copy_u8Value){

	switch(Copy_u8Port)
	{
	case GPIOA:
		if( Copy_u8Value == HIGH ){
			GPIOA_BSR = (1<< Copy_u8Pin);

		}else if( Copy_u8Value == LOW ){
			GPIOA_BRR = (1<<Copy_u8Pin);
		}
		break;
		
	case GPIOB:
		if( Copy_u8Value == HIGH ){

			GPIOB_BSR = (1<< Copy_u8Pin);

		}else if( Copy_u8Value == LOW ){
			GPIOB_BRR = (1<<Copy_u8Pin);
		}
		break;
		
	case GPIOC:
		if( Copy_u8Value == HIGH ){

			GPIOC_BSR = (1<< Copy_u8Pin);

		}else if( Copy_u8Value == LOW ){
			GPIOC_BRR = (1<<Copy_u8Pin);
		}
		break;

	}

}

void DIO_voidSetPortValue (u8 Copy_u8Port, u16 Copy_u16Value){

	switch(Copy_u8Port)
	{
	case GPIOA:
			GPIOA_ODR |= Copy_u16Value ;

		break;
		
	case GPIOB:
			GPIOB_ODR |= Copy_u16Value ;

		break;
		
	case GPIOC:
			GPIOC_ODR |= Copy_u16Value ;

		break;

	}

}
void DIO_voidSetByteValue (u8 Copy_u8Port, u8 Copy_u8Value){

	switch(Copy_u8Port)
	{
	case GPIOA:
			GPIOA_ODR &= ~0xff ;
			GPIOA_ODR |= Copy_u8Value ;

		break;
		
	case GPIOB:
			GPIOB_ODR &= ~0xff ;
			GPIOB_ODR |= Copy_u8Value ;

		break;
		
	case GPIOC:
			GPIOC_ODR &= ~0xff ;
			GPIOC_ODR |= Copy_u8Value ;

		break;

	}

}

u8 DIO_voidGetPinValue (u8 Copy_u8Port, u8 Copy_u8Pin ){

	u8 LOC_u8Result = 0 ;

	switch(Copy_u8Port)
	{
	case GPIOA:
		LOC_u8Result = GET_BIT( GPIOA_IDR , Copy_u8Pin );

		break;
	case GPIOB:

		LOC_u8Result = GET_BIT( GPIOB_IDR , Copy_u8Pin );

		break;
	case GPIOC:

		LOC_u8Result = GET_BIT( GPIOC_IDR , Copy_u8Pin );

		break;
	}
	return LOC_u8Result;
}

