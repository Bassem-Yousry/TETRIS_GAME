/************************************************************************************************************************/
/* Author	: Bassem																									*/
/* Date		: 17 Aug 2020																								*/
/* Version	: V01																										*/	
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

void RCC_voidInitSysClock ( void ) 
{
	#if 	RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL
		RCC_CR 	 = 0x10000;
		RCC_CFGR = 0x01;
		
	#elif	RCC_CLOCK_TYPE == RCC_HSE_RC
		RCC_CR 	 = 0x50000;
		RCC_CFGR = 0x01; 
	
	#elif	RCC_CLOCK_TYPE == RCC_HSI
		RCC_CR 	 = 0x0081;
		RCC_CFGR = 0x00;
		
	#elif	RCC_CLOCK_TYPE == RCC_PLL
	
		#if RCC_PLL_INPUT == RCC_PLL_IN_HSI_DIV_2
			RCC_CFGR = 0x00;
			
		#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE_DIV_2
			RCC_CFGR = 0x30000;
			
		#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE
			RCC_CFGR = 0x10000;

		#else
			#error("Wrong PLL Input")
		#endif
	
		#if RCC_PLL_MUL_VAL == 2
			RCC_CFGR &= ~(0x3C0000);
			
		#elif RCC_PLL_MUL_VAL == 3
			RCC_CFGR &= ~(0x3C0000);
			RCC_CFGR |= 0x40000;
						
		#elif RCC_PLL_MUL_VAL == 4
			RCC_CFGR &= ~(0x3C0000);
			RCC_CFGR |= 0x80000;
						
		#elif RCC_PLL_MUL_VAL == 5
			RCC_CFGR &= ~(0x3C0000);
			RCC_CFGR |= 0xC0000;
						
		#elif RCC_PLL_MUL_VAL == 6
			RCC_CFGR &= ~(0x3C0000);
			RCC_CFGR |= 0x100000;
			
		#elif RCC_PLL_MUL_VAL == 7
			RCC_CFGR &= ~(0x3C0000);
			RCC_CFGR |= 0x140000;
						
		#elif RCC_PLL_MUL_VAL == 8
			RCC_CFGR &= ~(0x3C0000);
			RCC_CFGR |= 0x180000;
						
		#elif RCC_PLL_MUL_VAL == 9
			RCC_CFGR &= ~(0x3C0000);
			RCC_CFGR |= 0x1C0000;
			
		#elif RCC_PLL_MUL_VAL == 10
			RCC_CFGR &= ~(0x3C0000);
			RCC_CFGR |= 0x200000;
						
		#elif RCC_PLL_MUL_VAL == 11
			RCC_CFGR &= ~(0x3C0000);
			RCC_CFGR |= 0x240000;
						
		#elif RCC_PLL_MUL_VAL == 12
			RCC_CFGR &= ~(0x3C0000);
			RCC_CFGR |= 0x280000;
			
		#elif RCC_PLL_MUL_VAL == 13
			RCC_CFGR &= ~(0x3C0000);
			RCC_CFGR |= 0x2C0000;
						
		#elif RCC_PLL_MUL_VAL == 14
			RCC_CFGR &= ~(0x3C0000);
			RCC_CFGR |= 0x300000;
						
		#elif RCC_PLL_MUL_VAL == 15
			RCC_CFGR &= ~(0x3C0000);
			RCC_CFGR |= 0x340000;
						
		#elif RCC_PLL_MUL_VAL == 16
			RCC_CFGR &= ~(0x3C0000);
			RCC_CFGR |= 0x380000;
			
		#else
			#error("Wrong Multiplier")
		#endif				
		RCC_CR	 = 0x1000000;
		RCC_CFGR &= ~(0x03); 
		RCC_CFGR |= 0x02;
	#else
		#error("Wrong Clock Type")
	#endif
	
	
	
}

void RCC_voidEnableClock(u8 Copy_u8BusId, u8 Copy_u8PerId)
{
	if (Copy_u8PerId <= 31)
	{
		switch (Copy_u8BusId)
		{
			case RCC_AHB  : SET_BIT(RCC_AHBENR  ,Copy_u8PerId);   break;
			case RCC_APB1 : SET_BIT(RCC_APB1ENR ,Copy_u8PerId);   break;
			case RCC_APB2 : SET_BIT(RCC_APB2ENR ,Copy_u8PerId);   break;
		}
	}
	
	else
	{
		/* Return Error */
	}

}

void RCC_voidDisableClock(u8 Copy_u8BusId, u8 Copy_u8PerId)
{
	if (Copy_u8PerId <= 31)
	{
		switch (Copy_u8BusId)
		{
			case RCC_AHB  : CLR_BIT(RCC_AHBENR  ,Copy_u8PerId);   break;
			case RCC_APB1 : CLR_BIT(RCC_APB1ENR ,Copy_u8PerId);   break;
			case RCC_APB2 : CLR_BIT(RCC_APB2ENR ,Copy_u8PerId);   break;
		}
	}
	
	else
	{
		/* Return Error */
	}

}
