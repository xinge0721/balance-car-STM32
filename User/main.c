#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Motor.h"
#include "Key.h"

uint8_t KeyNum;		//定义用于接收按键键码的变量
int8_t Speed;		//定义速度变量

int main(void)
{
	OLED_Init();
	while(1)
	{
			OLED_ShowNum(1,1,1,1);
	OLED_ShowNum(1,1,1,1);
	OLED_ShowNum(2,1,1,1);
	OLED_ShowNum(3,1,1,1);
	OLED_ShowNum(4,1,1,1);

	}

}
