#include "stm32f10x.h"                  // Device header

/**
  * 函    数：PWM初始化
  * 参    数：无
  * 返 回 值：无
  */
void PWM_Init(u16 Psc,u16 per)
{
	/*开启时钟*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_TIM1, ENABLE);			//开启GPIOA的时钟
	
	/*GPIO初始化*/
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Pin  =  GPIO_Pin_8 | GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);								
																	
	
	/*配置时钟源*/
	TIM_InternalClockConfig(TIM1);														//选择TIM1为内部时钟
	
	/*时基单元初始化*/
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;							//定义结构体变量
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;     //时钟分频，选择不分频，此参数用于配置滤波器时钟，不影响时基单元功能
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up; //计数器模式，选择向上计数
	TIM_TimeBaseInitStructure.TIM_Period      = Psc;                 	//计数周期，即ARR的值
	TIM_TimeBaseInitStructure.TIM_Prescaler   = per;             		//预分频器，即PSC的值
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;           //重复计数器，高级定时器才会用到
	TIM_TimeBaseInit(TIM1, &TIM_TimeBaseInitStructure);             //将结构体变量交给TIM_TimeBaseInit，配置TIM2的时基单元
	
	TIM_OCInitTypeDef TIM_OCInitStructure;	
	


	/*输出比较初始化*/ 
	TIM_OCInitStructure.TIM_OCMode      = TIM_OCMode_PWM1;          //初始化输出比较
	TIM_OCInitStructure.TIM_OCPolarity  = TIM_OCPolarity_High;      
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;   
	TIM_OCInitStructure.TIM_Pulse 		= 0;								
	
	TIM_OC1Init(TIM1,&TIM_OCInitStructure);
	TIM_OC4Init(TIM1,&TIM_OCInitStructure);
	
	TIM_CtrlPWMOutputs(TIM1,ENABLE);//高级定时器专属——MOE主输出使能
	

	TIM_OC1PreloadConfig(TIM1, TIM_OCPreload_Enable);//OC1预装载寄存器使能
	TIM_OC4PreloadConfig(TIM1, TIM_OCPreload_Enable);//OC4预装载寄存器使能

    TIM_ARRPreloadConfig(TIM1, ENABLE);//TIM1在ARR上预载寄存器使能
	
		/*TIM使能*/
	TIM_Cmd(TIM1, ENABLE);			
	
}

/**
  * 函    数：PWM设置CCR
  * 参    数：Compare 要写入的CCR的值，范围：0~100
  * 返 回 值：无
  * 注意事项：CCR和ARR共同决定占空比，此函数仅设置CCR的值，并不直接是占空比
  *           占空比Duty = CCR / (ARR + 1)
  */
void PWM_SetCompare2(uint16_t Compare)
{
	TIM_SetCompare2(TIM2, Compare);		//设置CCR3的值
}

void PWM_SetCompare4(uint16_t Compare)
{
	TIM_SetCompare4(TIM4, Compare);		//设置CCR3的值
}
