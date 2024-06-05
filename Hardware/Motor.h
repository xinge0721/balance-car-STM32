#ifndef __MOTOR_H
#define __MOTOR_H


#include "sys.h"

void Motor_Init(void);

void Motor_section(int* Ain,int* Bin);

int Motor_abs(int moto);

void Motor_Speed(int motoA,int motoB);
#endif
