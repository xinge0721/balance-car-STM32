//#include "sys.h"


//float Med_Angle=4.35;	
//float Target_Speed=10;	
//	int PWM_out;

//float 
//	Vertical_Kp = 100,
//	Vertical_Kd= 100;

//float 
//	Velocity_Kp= 100,
//	Velocity_Ki= 100;

//float
//	Turn_Kd= 100;
//int Encoder_Left,Encoder_Right;

//int Vertical_out,Velocity_out,Turn_out;//ֱ����&�ٶȻ�&ת�� ���������

//int boot1,boot2;
////ֱ����
//int Vertical(float real,float ideal,float gyro_Y)
//{
//	PWM_out =Vertical_Kp*(real-ideal) + Vertical_Kd * gyro_Y;
//	return PWM_out;
//}

////�ٶȻ�PI��Kp*Ek+Ki*Ek_S

//int Velocity(int real_left,int real_right,float ideal)
//{
//	static int Encoder_S,EnC_Err_Lowout_last,EnC_Err_Lowout,real;
//	float a=0.7;
//	int PWM_out;
//	//��ͨ�˲�
//	
//	real = (real_left + real_right) - ideal;
//		
//	EnC_Err_Lowout=(1-a)*real+a*EnC_Err_Lowout_last;//ʹ�ò��θ���ƽ�����˳���Ƶ���ţ���ֹ�ٶ�ͻ�䡣
//	EnC_Err_Lowout_last=EnC_Err_Lowout;//��ֹ�ٶȹ����Ӱ��ֱ����������������
//	
//	Encoder_S += EnC_Err_Lowout;
//	
//	Encoder_S=Encoder_S>10000?10000:(Encoder_S<(-10000)?(-10000):Encoder_S);

//	PWM_out = Velocity_Kp * EnC_Err_Lowout + Velocity_Ki * Encoder_S;
//	return PWM_out;
//}

//int Turn(int gyro_Z)//����Ϊʲô��������ƫ���ǣ���ʹ��������ԭʼ����gyro_Z����Ϊ������ƫ�������ۻ����ģ������ʱ���ϵ�����ۻ�����
//{
//	int PWM_out;
//	
//	PWM_out=Turn_Kd*gyro_Z;//�ٶȻ����ԣ���ע�͵�ֱ�������ٶȻ������㣬��1��-1��Ȼ���ص���ת�������һ��������֤�������˼���
//	return PWM_out;
//}

//void EXTI9_5_IRQHandler(void)
//{
//	if(EXTI_GetITStatus(EXTI_Line5)!=0)//һ���ж�
//	{	
//		if(!PBin(5))//�����ж�
//		{
//			EXTI_ClearITPendingBit(EXTI_Line5);//����жϱ�־λ
//			//1.�ɼ�MPU6050������Ϣ
//			Encoder_Left = Encoder_Get(2);
//			Encoder_Right= Encoder_Get(4);
//			mpu_dmp_get_data(&Pitch,&Roll,&Yaw);		//�Ƕ�
//			MPU_Get_Gyroscope(&gyrox,&gyroy,&gyroz);	//������
//			MPU_Get_Accelerometer(&aacx,&aacy,&aacz);	//���ٶ�
//			
//			//2.������ѹ��ջ������У�����������������
//			
//			Velocity_out = Vertical(Velocity_out - Med_Angle,Roll,gyroy);
//			Vertical_out = Velocity(Encoder_Left,Encoder_Right,Target_Speed);
//			Turn_out = Turn(gyroz);
//			
//			
//			//3.�ѿ�����������ص�����ϣ�������յĵĿ��ơ�
//			boot1 = Vertical_out - Turn_out;
//			boot2 = Vertical_out + Turn_out;
//			Motor_section(&boot1,&boot2);
//			Motor_Speed(boot1,boot2);

//		}
//	}	
//}
