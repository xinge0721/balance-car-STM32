#include "stm32f10x.h"                  // Device header
#include "sys.h"

float Pitch,Roll,Yaw;						//角度
short gyrox,gyroy,gyroz;				//陀螺仪--角速度
short aacx,aacy,aacz;						//加速度

int main(void)
{	
	//delay_init();

//	NVIC_Gonfig();
	
//	MPU_Init();
//	
//	mpu_dmp_init();

//	MPE_EXTI_Init();
	
	Encoder_TIM2_Init();
	Encoder_TIM4_Init();
	Motor_Init();

	PWM_Init_TIM1(0,3599);

	while(1)
	{
		Load(3500,3500);
		

	}

}
