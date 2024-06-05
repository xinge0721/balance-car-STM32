#ifndef __PID_H
#define __PID_H

typedef struct PID
{
	int error;			//���
	int error_list;		//��һ�����
	float kp;			//����
	float ki;			//΢��
	float kd;			//����
}PID;

typedef struct calculate
{
	float ratio;		//	
	float differential; //
	float integral;		//����
	float total_points; //PID�ܷ�

}cl;

#endif
