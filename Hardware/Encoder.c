#include "stm32f10x.h"                  // Device header

void Encoder_Init_1(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);		//开启GPIOA的时钟

	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin= GPIO_Pin_1 | GPIO_Pin_0; 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
	
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
	TIM_TimeBaseInitStruct.TIM_ClockDivision     = TIM_CKD_DIV1;
	TIM_TimeBaseInitStruct.TIM_CounterMode 		 = TIM_CounterMode_Up;
	TIM_TimeBaseInitStruct.TIM_Period        	 = 65535;
	TIM_TimeBaseInitStruct.TIM_Prescaler 	     = 0;
	TIM_TimeBaseInitStruct.TIM_RepetitionCounter = 0;
	
	TIM_TimeBaseInit(TIM2,&TIM_TimeBaseInitStruct);
	
	TIM_ICInitTypeDef TIM_ICInitStructure;
	TIM_ICStructInit(&TIM_ICInitStructure);
	TIM_ICInitStructure.TIM_Channel = TIM_Channel_1;
	TIM_ICInitStructure.TIM_ICFilter = 0xF;
	TIM_ICInit(TIM2, &TIM_ICInitStructure);
	TIM_ICInitStructure.TIM_Channel = TIM_Channel_2;
	TIM_ICInitStructure.TIM_ICFilter = 0xF;
	TIM_ICInit(TIM2, &TIM_ICInitStructure);
	
	TIM_EncoderInterfaceConfig(TIM2, TIM_EncoderMode_TI12, TIM_ICPolarity_Rising, TIM_ICPolarity_Rising);
	
	TIM_Cmd(TIM2,ENABLE);
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
	
	TIM_TimeBaseInit(TIM4,&TIM_TimeBaseInitStruct);
	
	TIM_ICInitTypeDef TIM_ICInitStructure;
	
	TIM_EncoderInterfaceConfig(TIM4, TIM_EncoderMode_TI12, TIM_ICPolarity_Rising, TIM_ICPolarity_Rising);
	
	TIM_ICStructInit(&TIM_ICInitStructure);
	
	TIM_ICInitStructure.TIM_ICFilter = 0xF;
	TIM_ICInit(TIM4, &TIM_ICInitStructure);

	TIM_ClearFlag(TIM2,TIM_FLAG_Update);
	
	
	TIM_Cmd(TIM4,ENABLE);
}

int16_t Encoder_Get(uint8_t x)
{
	uint16_t  quantity = 0;
	switch (x)
	{
		case 1 : quantity = TIM_GetCounter(TIM2);TIM_SetCounter(TIM2, 0);break;
		case 2 : quantity = TIM_GetCounter(TIM4);TIM_SetCounter(TIM4, 0);break;
	}
	return quantity;
}

	


