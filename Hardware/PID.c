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

//int Vertical_out,Velocity_out,Turn_out;//直立环&速度环&转向环 的输出变量

//int boot1,boot2;
////直立环
//int Vertical(float real,float ideal,float gyro_Y)
//{
//	PWM_out =Vertical_Kp*(real-ideal) + Vertical_Kd * gyro_Y;
//	return PWM_out;
//}

////速度环PI：Kp*Ek+Ki*Ek_S

//int Velocity(int real_left,int real_right,float ideal)
//{
//	static int Encoder_S,EnC_Err_Lowout_last,EnC_Err_Lowout,real;
//	float a=0.7;
//	int PWM_out;
//	//低通滤波
//	
//	real = (real_left + real_right) - ideal;
//		
//	EnC_Err_Lowout=(1-a)*real+a*EnC_Err_Lowout_last;//使得波形更加平滑，滤除高频干扰，防止速度突变。
//	EnC_Err_Lowout_last=EnC_Err_Lowout;//防止速度过大的影响直立环的正常工作。
//	
//	Encoder_S += EnC_Err_Lowout;
//	
//	Encoder_S=Encoder_S>10000?10000:(Encoder_S<(-10000)?(-10000):Encoder_S);

//	PWM_out = Velocity_Kp * EnC_Err_Lowout + Velocity_Ki * Encoder_S;
//	return PWM_out;
//}

//int Turn(int gyro_Z)//这里为什么不传这里偏航角，而使用陀螺仪原始数据gyro_Z，因为陀螺仪偏航角是累积误差的，他会把时间上的误差累积起来
//{
//	int PWM_out;
//	
//	PWM_out=Turn_Kd*gyro_Z;//速度环极性，先注释掉直立环和速度环的运算，给1和-1，然后沿地旋转，如果有一股阻力则证明调对了极性
//	return PWM_out;
//}

//void EXTI9_5_IRQHandler(void)
//{
//	if(EXTI_GetITStatus(EXTI_Line5)!=0)//一级判定
//	{	
//		if(!PBin(5))//二级判定
//		{
//			EXTI_ClearITPendingBit(EXTI_Line5);//清除中断标志位
//			//1.采集MPU6050数据信息
//			Encoder_Left = Encoder_Get(2);
//			Encoder_Right= Encoder_Get(4);
//			mpu_dmp_get_data(&Pitch,&Roll,&Yaw);		//角度
//			MPU_Get_Gyroscope(&gyrox,&gyroy,&gyroz);	//陀螺仪
//			MPU_Get_Accelerometer(&aacx,&aacy,&aacz);	//加速度
//			
//			//2.将数据压入闭环控制中，计算出控制输出量。
//			
//			Velocity_out = Vertical(Velocity_out - Med_Angle,Roll,gyroy);
//			Vertical_out = Velocity(Encoder_Left,Encoder_Right,Target_Speed);
//			Turn_out = Turn(gyroz);
//			
//			
//			//3.把控制输出量加载到电机上，完成最终的的控制。
//			boot1 = Vertical_out - Turn_out;
//			boot2 = Vertical_out + Turn_out;
//			Motor_section(&boot1,&boot2);
//			Motor_Speed(boot1,boot2);

//		}
//	}	
//}
