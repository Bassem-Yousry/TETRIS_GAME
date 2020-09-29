/***********************************************************/
/* Author    : Ahmed Assaf                                 */
/* Date      : 21 Sep 2020                                 */
/* Version   : V01                                         */
/***********************************************************/
#ifndef TFT_INTERFACE_H
#define TFT_INTERFACE_H

void HTFT_voidInitialize   (void);
void HTFT_voidDisplayImage (const u16* Copy_Image);
void HTFT_voidFillColor ( u16 Copy_u16Color);
void HTFT_voidDrawRect ( u8 x1, u8 x2, u8 y1, u8 y2, u16 Copy_u16Color);
void HTFT_voidDrawChar (u8 Copy_u8Char, u8 x1, u8 y1, u8 Copy_u8Size,u16 Copy_u16Color);
void HTFT_voidDrawText (s8* Copy_u8Text, u8 x1, u8 y1, u8 Copy_u8Size,u16 Copy_u16Color);
void HTFT_voidDrawCircle (u8* Copy_u8Char, u8 x1, u8 y1, u16 Copy_u16Color);
#endif
