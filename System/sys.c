#include "sys.h"

void NVIC_Gonfig(void)
{
	NVIC_InitTypeDef NVIC_Initstruct;
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	NVIC_Initstruct.NVIC_IRQChannel                   = EXTI9_5_IRQn;
	NVIC_Initstruct.NVIC_IRQChannelCmd                = ENABLE;
	NVIC_Initstruct.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_Initstruct.NVIC_IRQChannelSubPriority        =0;
	
	NVIC_Init(&NVIC_Initstruct);
		
	NVIC_Initstruct.NVIC_IRQChannel					  = USART1_IRQn;
	NVIC_Initstruct.NVIC_IRQChannelCmd				  = ENABLE;
	NVIC_Initstruct.NVIC_IRQChannelPreemptionPriority = 2;
	NVIC_Initstruct.NVIC_IRQChannelSubPriority     	  =2;
	NVIC_Init(&NVIC_Initstruct);

}


