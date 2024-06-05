#ifndef  _MOTOR_H
#define  _MOTOR_H

#include "sys.h" 







#define Ain1  PBout(12)//14
#define Ain2  PBout(13)//15

#define Bin1  PBout(14)/*¡¾4¡¿*///13
#define Bin2  PBout(15)//12


void Stop(float *Med_Jiaodu,float *Jiaodu);
void Motor_Init(void);/*¡¾5¡¿*/
void Limit(int *motoA,int *motoB);
int GFP_abs(int p);
void Load(int moto1,int moto2);
#endif

