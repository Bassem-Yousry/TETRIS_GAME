/**********************************************************/
/* Author    : Bassem Yousry                               */
/* Date      : 22 August 2020                             */
/* Version   : V01                                        */
/**********************************************************/
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

#define			LINE0				0
#define			LINE1				1
#define			LINE2				2
#define			LINE3				3
#define			LINE4				4
#define			LINE5				5
#define			LINE6				6
#define			LINE7				7
#define			LINE8				8
#define			LINE9				9
#define			LINE10				10
#define			LINE11				11
#define			LINE12				12
#define			LINE13				13
#define			LINE14				14
#define			LINE15				15



#define			RISING				0
#define			FALLING				1
#define			ON_CHANGE			2

void MEXTI_voidInit();
void MEXTI_voidEnableEXTI(u8 Copy_u8Line);
void MEXTI_voidDisableEXTI(u8 Copy_u8Line);
void MEXTI_voidSwTrigger(u8 Copy_u8Line);
void MEXTI_voidSetSignalLatch(u8 Copy_u8Line , u8 Copy_u8Mode);
void MEXTI_voidSetCallBack(u8 Copy_u8EXTI_num,void (*ptr) (void)) ;

#endif