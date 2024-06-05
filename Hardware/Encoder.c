#include "stm32f10x.h"                  // Device header

void Encoder_Init_1(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);		//开启GPIOA的时钟

	GPIO_InitTypeDef GPIO_InitStructure;												//初始化GPIO
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin= GPIO_Pin_1 | GPIO_Pin_0; 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
	
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;									//初始化定时器
	TIM_TimeBaseInitStruct.TIM_ClockDivision     = TIM_CKD_DIV1;
	TIM_TimeBaseInitStruct.TIM_CounterMode 		 = TIM_CounterMode_Up;
	TIM_TimeBaseInitStruct.TIM_Period        	 = 65535;
	TIM_TimeBaseInitStruct.TIM_Prescaler 	     = 0;
	TIM_TimeBaseInitStruct.TIM_RepetitionCounter = 0;
	
	TIM_TimeBaseInit(TIM2,&TIM_TimeBaseInitStruct);
	
	/*NVIC配置*/
	NVIC_InitTypeDef NVIC_InitStructure;									//定义结构体变量
	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;				//选择配置NVIC的TIM2线
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//指定NVIC线路使能
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;	//指定NVIC线路的抢占优先级为2
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;				//指定NVIC线路的响应优先级为1
	NVIC_Init(&NVIC_InitStructure);												//将结构体变量交给NVIC_Init，配置NVIC外设
	
	TIM_ICInitTypeDef TIM_ICInitStructure;
	
	TIM_EncoderInterfaceConfig(TIM2, TIM_EncoderMode_TI12, TIM_ICPolarity_Rising, TIM_ICPolarity_Rising);			//配置编码器模式
	
	TIM_ICStructInit(&TIM_ICInitStructure);												//初始化输入捕获
	TIM_ICInitStructure.TIM_ICFilter = 10;
	TIM_ICInit(TIM2, &TIM_ICInitStructure);
	
	TIM_ClearFlag(TIM2,TIM_FLAG_Update);											//清除溢出更新中断标志位
	TIM_ITConfig(TIM2,TIM_IT_Update,ENABLE);										//配置溢出更新中断标志位
	
	TIM_SetCounter(TIM2,0);																	//清零定时器
	
	TIM_Cmd(TIM2,ENABLE);																	//定时器使能
}
void Encoder_Init_2(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);		//开启GPIOA的时钟

	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin= GPIO_Pin_6 | GPIO_Pin_7; 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4,ENABLE);
	
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
	TIM_TimeBaseInitStruct.TIM_ClockDivision     = TIM_CKD_DIV1;
	TIM_TimeBaseInitStruct.TIM_CounterMode 		 = TIM_CounterMode_Up;
	TIM_TimeBaseInitStruct.TIM_Period        	 = 65535;
	TIM_TimeBaseInitStruct.TIM_Prescaler 	     = 0;
	TIM_TimeBaseInitStruct.TIM_RepetitionCounter = 0;
	
	/*NVIC配置*/
	NVIC_InitTypeDef NVIC_InitStructure;									//定义结构体变量
	NVIC_InitStructure.NVIC_IRQChannel = TIM4_IRQn;				//选择配置NVIC的TIM4线
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//指定NVIC线路使能
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;	//指定NVIC线路的抢占优先级为2
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;				//指定NVIC线路的响应优先级为1
	NVIC_Init(&NVIC_InitStructure);												//将结构体变量交给NVIC_Init，配置NVIC外设
	
	
	TIM_TimeBaseInit(TIM4,&TIM_TimeBaseInitStruct);
	
	
	TIM_ICInitTypeDef TIM_ICInitStructure;
	
	TIM_EncoderInterfaceConfig(TIM4, TIM_EncoderMode_TI12, TIM_ICPolarity_Rising, TIM_ICPolarity_Rising);
	
	TIM_ICStructInit(&TIM_ICInitStructure);
	TIM_ICInitStructure.TIM_ICFilter = 10;
	TIM_ICInit(TIM4, &TIM_ICInitStructure);
	
	TIM_ClearFlag(TIM4,TIM_FLAG_Update);
	TIM_ITConfig(TIM4,TIM_IT_Update,ENABLE);
	
	TIM_SetCounter(TIM4,0);
	
	TIM_Cmd(TIM4,ENABLE);
}

//读取速度函数

int16_t Encoder_Get(uint8_t x)
{
	uint16_t  quantity = 0;
	switch (x)
	{
		case 2 : quantity = (short)TIM_GetCounter(TIM2);TIM_SetCounter(TIM2, 0);break;
		case 4 : quantity = (short)TIM_GetCounter(TIM4);TIM_SetCounter(TIM4, 0);break;
	}
	return quantity;
}



void TIM2_IRQHandler(void)
{
		if (TIM_GetFlagStatus(TIM2, TIM_FLAG_Update) == SET)
		{ 
			TIM_ClearITPendingBit(TIM2,TIM_IT_Update);
		}
}
void TIM4_IRQHandler(void)
{
		if (TIM_GetFlagStatus(TIM4, TIM_FLAG_Update) == SET)
		{
			TIM_ClearITPendingBit(TIM4,TIM_IT_Update);
		}
}
