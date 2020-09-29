/********************************************************************************/
/* Author : Bassem																*/
/* Date   : 27 Sep 2020															*/
/* V01																			*/
/********************************************************************************/
#include <stdio.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "STK_interface.h"
#include "SPI_interface.h"
#include "RCC_interface.h"
#include "EXTI_interface.h"
#include "NVIC_interface.h"
#include "TFT_interface.h"

#include "HTETRIS_private.h"
#include "HTETRIS_interface.h"
#include "HTETRIS_config.h"

#define Null (void *) 0



/*
	HIGH
	MEDIUM
	LOW
*/


static volatile  u8 Shape_Num=0;
static u8 Score = 0;
static u8 global_Rotate=0;

struct Node{
	u8 x;
	u8 y;
	struct Node * next;
};

static u16 Area []={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static struct Node * Tetromino_Z =Null;
static struct Node * Tetromino_T =Null;
static struct Node * Tetromino_O =Null;
static struct Node * Tetromino_L=Null;
static struct Node * Tetromino_l =Null;
static struct Node * global_Tetromino=Null;

void TetrminoInit(struct Node * Head , u8 Block_num){
	for(int i =0 ;i<Block_num;i++){
		struct Node * node;
		node =Head;
		while(node->next != Null){
			node=node->next;
		}
		struct Node *New =Null;
		New = (struct Node*)malloc(sizeof(struct Node)) ;
		New->x=200;New->y=200;New->next=Null;
		node->next = New;

	}
}


static void T_T(u8 x,u8 y){
	u8 count=0;
			u8 Values [3][2]={{x,y-1},{x,y+1},{x+1,y}};
			Tetromino_T->x=x;Tetromino_T->y=y;
			struct Node *node=Tetromino_T;
			while(node->next!=Null){
				node=node->next;
				node->x=Values[count][0];
				node->y=Values[count][1];
				count++;
			}
}
static void TT(u8 x,u8 y){
		u8 count=0;
		u8 Values [3][2]={{x,y-1},{x+1,y},{x-1,y}};
		Tetromino_T->x=x;Tetromino_T->y=y;
		struct Node *node=Tetromino_T;
		while(node->next!=Null){
			node=node->next;
			node->x=Values[count][0];
			node->y=Values[count][1];
			count++;
		}
}
static void T_l(u8 x,u8 y){
	u8 count=0;
	u8 Values [4]={x+1,x+2,x-1,x-2};
	Tetromino_l->x=x;Tetromino_l->y=y;
	struct Node *node=Tetromino_l;
	while(node->next!=Null){
		node=node->next;
		node->y=y;
		node->x=Values[count];
		count++;
	}

}
static void Tl(u8 x,u8 y){
	u8 count=0;
	u8 Values [4]={y+1,y+2,y-1,y-2};
	Tetromino_l->x=x;Tetromino_l->y=y;
	struct Node *node=Tetromino_l;
	while(node->next!=Null){
		node=node->next;
		node->x=x;
		node->y=Values[count];
		count++;
	}

}
static void T_L(u8 x,u8 y){
		u8 count=0;
		u8 Values [4][2]={{x+1,y},{x+2,y},{x-1,y},{x+2,y+1}};
		struct Node *node=Tetromino_L;
		node->x=x;
		node->y=y;
		while(node->next!=Null){
			node=node->next;
			node->x=Values[count][0];
			node->y=Values[count][1];
			count++;
		}}
static void TL(u8 x,u8 y){
		u8 count=0;
		u8 Values [4][2]={{x,y+1},{x,y+2},{x,y-1},{x+1,y-1}};
		struct Node *node=Tetromino_L;
		node->x=x;
		node->y=y;
		while(node->next!=Null){
			node=node->next;
			node->x=Values[count][0];
			node->y=Values[count][1];
			count++;
		}}
static void T_Z(u8 x,u8 y){
		u8 count=0;
		u8 Values [3][2]={ {x+1,y},{x,y+1},{x+1,y-1}};
		Tetromino_Z->x=x;Tetromino_Z->y=y;
		struct Node *node=Tetromino_Z;
		while(node->next!=Null){
			node=node->next;
			node->x=Values[count][0];
			node->y=Values[count][1];
			count++;
		}}
static void TZ(u8 x,u8 y){
		u8 count=0;
		u8 Values [3][2]={ {x,y-1},{x+1,y},{x-1,y-1}};
		Tetromino_Z->x=x;Tetromino_Z->y=y;
		struct Node *node=Tetromino_Z;
		while(node->next!=Null){
			node=node->next;
			node->x=Values[count][0];
			node->y=Values[count][1];
			count++;
		}}
static void TO(u8 x,u8 y){
		u8 count=0;
		u8 Values [3][2]={{x+1,y},{x,y+1},{x+1,y+1} };
		Tetromino_O->x=x;Tetromino_O->y=y;
		struct Node *node=Tetromino_O;
		while(node->next!=Null){
			node=node->next;
			node->x=Values[count][0];
			node->y=Values[count][1];
			count++;
		}}


void HTETRIS_voidTetrisInit(){
	Tetromino_Z =(struct Node*)malloc(sizeof(struct Node));
	Tetromino_T =(struct Node*)malloc(sizeof(struct Node));
	Tetromino_O =(struct Node*)malloc(sizeof(struct Node));
	Tetromino_L=(struct Node*)malloc(sizeof(struct Node));
	Tetromino_l =(struct Node*)malloc(sizeof(struct Node));
	Tetromino_Z->next=Null;
	Tetromino_Z->y=0;
	Tetromino_L->next=Null;
	Tetromino_T->next=Null;
	Tetromino_O->next=Null;
	Tetromino_l->next=Null;
	TetrminoInit(Tetromino_Z,3);
	TetrminoInit(Tetromino_l,4);
	TetrminoInit(Tetromino_L,4);
	TetrminoInit(Tetromino_O,3);
	TetrminoInit(Tetromino_T,3);
	TL(1,14);
	TO(4,14);
	TZ(6,14);
	Tl(8,14);
	TT(5,14);
		MNVIC_voidEnableInterrupt(9);
		MNVIC_voidEnableInterrupt(10);

		MNVIC_voidEnableInterrupt(23);
		MEXTI_voidSetCallBack(5 , Rotate);
		MEXTI_voidEnableEXTI(8);
		MEXTI_voidSetSignalLatch(8 , FALLING);

		MEXTI_voidSetCallBack(3 , MoveL);
		MEXTI_voidSetCallBack(4 , MoveR);

		MEXTI_voidEnableEXTI(3);
		MEXTI_voidSetSignalLatch(3 , FALLING);
		MEXTI_voidEnableEXTI(4);
		MEXTI_voidSetSignalLatch(4 , FALLING);

	MSTK_voidSetIntervalPeriodic(Speed,HTETRIS_voidStart);
	HTFT_voidFillColor ( BackGroundColor);

}


static void Screen_Update(){
	HTFT_voidDrawRect (  0, 100, 140,160, BackGroundColor);
	s8 SCORE[20];
	sprintf(SCORE,"SCORE : %i",Score);
	 HTFT_voidDrawText (SCORE,  120, 145 ,1,0Xfffe);

	for(int i =0;i<14;i++){
		for(int j =0 ; j<10;j++){
			if( !GET_BIT(Area[i],j) )    //empty block
			{
				HTFT_voidDrawFrameRect (  j*10,  j*10+10, i*10, i*10+10, FrameColor);
			}else{
				HTFT_voidDrawFrameRect (  j*10,  j*10+10, i*10, i*10+10, TetrominoColor);
			}
		}
	}
}


void Update_Ter(struct Node * Tetromino){
	struct Node * node;
			node =Tetromino;
			node->y--;
			while(node->next != Null){
				node=node->next;
				node->y--;
			}
}

void Print_Ter(struct Node * Tetromino){
	struct Node * node;
			node =Tetromino;
			u8 x = node->x;
			u8 y = node->y;
			if(x<10&&y<14){HTFT_voidDrawFrameRect (  x*10,  x*10+10, y*10, y*10+10, TetrominoColor);}
			while(node->next != Null){
				node=node->next;
				 x = node->x;
				 y = node->y;
				 if(x<10&&y<14){HTFT_voidDrawFrameRect (  x*10,  x*10+10, y*10, y*10+10, TetrominoColor);}
			}

}

void Update_Frame(struct Node * Tetromino){

			struct Node * node;
			node =Tetromino;
			u8 x = node->x;
			u8 y = node->y;
			SET_BIT(Area[y],x);
			while(node->next != Null){
				node=node->next;
				x = node->x;
				 y = node->y;
				SET_BIT(Area[y],x);

			}
}

u8 StopTer(struct Node * Tetromino){
	struct Node * node=Tetromino;
	u8 flag=0;
	u8 y =node->y;
	u8 x = node->x;
	if (y==0){flag= 2;}
	u8 z =GET_BIT( Area[y],x);
	if ( z )
	{
		return 1;
	}
	while(node->next !=Null){
		node =node->next;
		y =node->y;
		x= node->x;
		if (y==0){flag= 2;}
		z =GET_BIT( Area[y],x);
		if ( z )
		{
			return 1;
		}
	}
	if (flag){return 2;}
return 0;	//return 0-> don't stop  , 1-> increase y position by 1 then stop , 2-> stop
}

static void MoveL(){
	for(int d=0;d<1000;d++){asm("NOP");}
	u8  X=global_Tetromino->x; u8 Y =global_Tetromino->y;


	if( X==9){return;}
	if(GET_BIT(Area[Y],X+1)){return;}
u8 x,y;
	struct Node * node = global_Tetromino;
	while(node->next!=Null){
		node=node->next;
		 x=node->x;  y =node->y;
		if(x==9){return;}
		if(GET_BIT(Area[y],x+1)){return;}  // check boundaries first
	}

	switch (Shape_Num){
				case 0: global_Rotate ?	T_T(X+1,Y):TT(X+1,Y);  break;
				case 1:	TO(X+1,Y);  break;
				case 2:	global_Rotate ?	T_Z(X+1,Y):TZ(X+1,Y);  break;
				case 3: global_Rotate ?	T_L(X+1,Y):TL(X+1,Y);  break;
				case 4:	global_Rotate ?	T_l(X+1,Y):Tl(X+1,Y);  break;
				}
}


static void MoveR(){



	u8  X=global_Tetromino->x; u8 Y =global_Tetromino->y;

		if(  X==0){return;}
		if(GET_BIT(Area[Y],X-1)){return;}
	u8 x,y;
		struct Node * node = global_Tetromino;
		while(node->next!=Null){
			node=node->next;
			 x=node->x;  y =node->y;
			if(x==0){return;}
			if(GET_BIT(Area[y],x-1)){return;}
		}

		switch (Shape_Num){
					case 0:	global_Rotate ? T_T(X-1,Y):TT(X-1,Y);  break;
					case 1:	TO(X-1,Y);  break;
					case 2:	global_Rotate ? T_Z(X-1,Y):TZ(X-1,Y);  break;
					case 3: global_Rotate ? T_L(X-1,Y):TL(X-1,Y);  break;
					case 4:	global_Rotate ? T_l(X-1,Y):Tl(X-1,Y);  break;
					}
}

static void Lose(){
	MSTK_voidStopInterval();
	 HTFT_voidDrawRect (  0,127, 0,160, 0);
	 HTFT_voidDrawText ("GAME OVER", 110,60 , 2,0xfe0);
	 u8 s [20];
	 sprintf(s,"SCORE : %i",Score);
	 HTFT_voidDrawText (s, 110,40 , 2,0xffff);


}
static void Rotate(){
	u8  X=global_Tetromino->x; u8 Y =global_Tetromino->y;

	if( (X>=8||X<=1) && Shape_Num !=0){return;}
	if(GET_BIT(Area[Y],X+1) || GET_BIT(Area[Y],X-1) ){return;}

	global_Rotate=(++global_Rotate+2)%2;
	switch (Shape_Num)
	{

	case 0:global_Rotate ? T_T(X,Y):TT(X,Y);break;
	case 1:break;
	case 2:global_Rotate ? T_Z(X,Y): TZ(X,Y);break;
	case 3:global_Rotate ? T_L(X,Y): TL(X,Y);break;
	case 4:global_Rotate ? T_l(X,Y): Tl(X,Y);break;

	}

}



void HTETRIS_voidStart(){
	u8 swap;
	for(int i =0;i<14;i++){
		if(Area[i]==1023) { //if a row is full remove it
			swap = i;
			Score++;
			for(int j=0;j<10;j++){
				CLR_BIT(Area[i],j);
			}
		for( ;swap<14;swap++){
			SWP_BYTE(Area[swap],Area[swap+1]);
						}

		}
	}

	switch (Shape_Num){
	case 0:	global_Tetromino=Tetromino_T;  break;
	case 1: global_Tetromino=Tetromino_O;  break;
	case 2:	global_Tetromino=Tetromino_Z;  break;
	case 3: global_Tetromino=Tetromino_L;  break;
	case 4:	global_Tetromino=Tetromino_l;  break;
	}

	Screen_Update();
	
	Update_Ter(global_Tetromino);
	
	u8 y =global_Tetromino->y;
	u8 x = global_Tetromino->x;
	u8 z = StopTer(global_Tetromino);
	
	if (z)
	{

		if(z==1){
			switch (Shape_Num){
			case 0:	global_Rotate ? T_T(x,y+1):TT(x,y+1);  break;
			case 1:	TO(x,y+1);  break;
			case 2:	global_Rotate ? T_Z(x,y+1):TZ(x,y+1);  break;
			case 3: global_Rotate ? T_L(x,y+1):TL(x,y+1);  break;
			case 4:	global_Rotate ? T_l(x,y+1):Tl(x,y+1);  break;
			}
		}
		global_Rotate=0;
		Update_Frame(global_Tetromino);
		switch (Shape_Num){
					case 0:	TT(5,14);  break;
					case 1:	TO(5,14);  break;
					case 2:	TZ(5,14);  break;
					case 3: TL(5,14);  break;
					case 4:	Tl(5,14);  break;
					}
		Shape_Num=global_Tetromino->y%5;
	}
	Print_Ter(global_Tetromino);
	if(Area[15]!=0){Lose();} //boundary is exceeded

}
