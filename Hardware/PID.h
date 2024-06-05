#ifndef __PID_H
#define __PID_H

typedef struct PID
{
	int error;			//误差
	int error_list;		//上一次误差
	float kp;			//比例
	float ki;			//微分
	float kd;			//积分
}PID;

typedef struct calculate
{
	float ratio;		//	
	float differential; //
	float integral;		//积分
	float total_points; //PID总分

}cl;

#endif
