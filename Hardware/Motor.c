#include "stm32f10x.h"                  // Device header
#include "motor.h"
#include "PWM.h"
#define Ain1 PBout(14)
#define Ain2 PBout(15)

#define Bin1 PBout(13)
#define Bin2 PBout(12)


#define Motor_MAX 7200
#define	Motor_MIN 0
/**
  * 函    数：直流电机初始化
  * 参    数：无
  * 返 回 值：无
  */
void Motor_Init(void)
{
	/*开启时钟*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);		//开启GPIOA的时钟
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);						

	PWM_Init();													//初始化直流电机的底层PWM
}

void Motor_section(int* Ain,int* Bin)
{
	if(*Ain > Motor_MAX)      *Ain = Motor_MAX;
	else if(*Ain < Motor_MIN) *Ain = Motor_MIN;
	
	if(*Bin > Motor_MAX)      *Bin = Motor_MAX;
	else if(*Bin < Motor_MIN) *Bin = Motor_MIN;
}

int Motor_abs(int moto)
{
	return moto > 0 ? moto: -moto;
}

void Motor_Speed(int motoA,int motoB)
{
	if(motoA > 0)     Ain1=1,Ain2=0;
	else if(motoA < 0)Ain1=0,Ain2=1;
	else 			  Ain1=0,Ain2=0;
	TIM_SetCompare1(TIM1,Motor_abs(motoA));
	
	if(motoB > 0)	  Bin1=1,Bin2=0;
	else if(motoB < 0)Bin1=0,Bin2=1;
	else 			  Bin1=0,Bin2=0;
	TIM_SetCompare4(TIM1,Motor_abs(motoB));
}


