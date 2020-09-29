/**********************************************************/
/* Author    : Bassem Yousry                               */
/* Date      : 22 August 2020                             */
/* Version   : V01                                        */
/**********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_config.h"
#include "EXTI_private.h"

static void (*EXTI_CallBack[16])(void)  ;

void MEXTI_voidInit()
{
	SET_BIT(EXTI -> IMR , EXTI_LINE );

	#if 	EXTI_MODE	== 	RISING
		SET_BIT(EXTI -> RSTR , EXTI_LINE);
	#elif 	EXTI_MODE	== 	FALLING
		SET_BIT(EXTI -> FTSR , EXTI_LINE);
	#elif	EXTI_MODE	==	ON_CHANGE
		SET_BIT(EXTI -> RSTR , EXTI_LINE);
		SET_BIT(EXTI -> FTSR , EXTI_LINE);
	#else 	
		#error "Wrong Mode and Line Choice"
	#endif

}

void MEXTI_voidEnableEXTI(u8 Copy_u8Line)
{
		SET_BIT(EXTI->IMR , Copy_u8Line);
}
void MEXTI_voidDisableEXTI(u8 Copy_u8Line)
{
	CLR_BIT(EXTI->IMR , Copy_u8Line);
}
void MEXTI_voidSwTrigger(u8 Copy_u8Line)
{
	SET_BIT(EXTI -> SWIER , Copy_u8Line);
}

void MEXTI_voidSetCallBack(u8 Copy_u8EXTI_num,void (*ptr) (void)) // ahmed
{
		EXTI_CallBack[Copy_u8EXTI_num] = ptr ; /*ahmed*/
}

void MEXTI_voidSetSignalLatch(u8 Copy_u8Line , u8 Copy_u8Mode)
{
	switch(Copy_u8Mode)
	{
		case RISING 	:	SET_BIT(EXTI -> RSTR , Copy_u8Line); 	break;
		case FALLING	:	SET_BIT(EXTI -> FTSR , Copy_u8Line); 	break;
		case ON_CHANGE 	:	SET_BIT(EXTI -> RSTR , Copy_u8Line); 
							SET_BIT(EXTI -> RSTR , Copy_u8Line); 	break;
	}
}


void	EXTI0_IRQHandler(void)
{
	EXTI_CallBack[0]();
	/*	Clear pending Bit		*/
	SET_BIT(EXTI -> PR , 0);

}

void	EXTI1_IRQHandler(void)
{
	EXTI_CallBack[1]();
	/*	Clear pending Bit		*/
	SET_BIT(EXTI -> PR , 1);
}

void	EXTI2_IRQHandler(void)
{
	EXTI_CallBack[2]();
	/*	Clear pending Bit		*/
	SET_BIT(EXTI -> PR , 2);
}

void	EXTI3_IRQHandler(void)
{
	EXTI_CallBack[3]();
	/*	Clear pending Bit3		*/
	SET_BIT(EXTI -> PR , 3);
}

void	EXTI4_IRQHandler(void)
{
	EXTI_CallBack[4]();
	/*	Clear pending Bit		*/
	SET_BIT(EXTI -> PR , 4);
}
void	EXTI9_5_IRQHandler(void)
{
	EXTI_CallBack[5]();
	/*	Clear pending Bit		*/
	SET_BIT(EXTI -> PR , 5);
}
void	EXTI15_10_IRQHandler(void)
{
	EXTI_CallBack[10]();
	/*	Clear pending Bit		*/
	SET_BIT(EXTI -> PR , 10);
}