/********************************************************************************/
/* Author : Bassem																*/
/* Date   : 27 Sep 2020															*/
/* V01																			*/
/********************************************************************************/
#ifndef HTETRIS_PRIVATE_H
#define HTETRIS_PRIVATE_H


static void T_T(u8 x , u8 y);
static void T_T(u8 x,u8 y);		 //update Rotated Tetromino T Position
static void TT	(u8 x,u8 y);	 //update Tetromino T position
static void T_l(u8 x,u8 y);
static void Tl	(u8 x,u8 y);
static void T_L(u8 x,u8 y);
static void TL	(u8 x,u8 y);
static void T_Z(u8 x,u8 y);
static void TZ	(u8 x,u8 y);
static void TO	(u8 x,u8 y);
static void Screen_Update(void);
static void Lose(void);
static void MoveR(void);
static void MoveL(void);
static void Rotate(void);
#endif
