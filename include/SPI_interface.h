/***************************************************************/
/* Author    : Ahmed Assaf                                     */
/* Version   : V01                                             */
/* Date      : 16 SEP 2020                                     */
/***************************************************************/
#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

void MSPI1_voidInit(void); /* Home Work */

void MSPI1_voidSendReceiveSynch(u8 Copy_u8DataToTransmit, u8 *Copy_DataToReceive);

void MSPI1_voidSendReceiveAsynch(u8 Copy_u8DataToTransmit, void (*CallBack)(u8));

#endif