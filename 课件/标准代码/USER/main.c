#include "stm32f10x.h"
#include "sys.h" 

float Pitch,Roll,Yaw;						//�Ƕ�
short gyrox,gyroy,gyroz;				//������--���ٶ�
short aacx,aacy,aacz;						//���ٶ�
int Encoder_Left,Encoder_Right;	//���������ݣ��ٶȣ�

int PWM_MAX=3600,PWM_MIN=-3600;	//PWM�޷�����
int MOTO1,MOTO2;								//���װ�ر���

extern int Vertical_out,Velocity_out,Turn_out;
int main(void)	
{
	delay_init();
	NVIC_Config();
	uart1_init(115200);
	
	OLED_Init();
	OLED_Clear();
	
	MPU_Init();
	mpu_dmp_init();
	MPU6050_EXTI_Init();
	
	Encoder_TIM2_Init();
	Encoder_TIM4_Init();
	Motor_Init();
	PWM_Init_TIM1(0,3599);
  while(1)	
	{
		OLED_Float(0,0,Roll,1);//�����
		OLED_Float(50,50,Yaw,1);//ƫ����
	} 	
}



