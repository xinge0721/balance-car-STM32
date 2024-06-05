#ifndef __Encoder_H
#define __Encoder_H

void Encoder_Init_1(void);
void Encoder_Init_2(void);

int16_t Encoder_Get(uint8_t x);

void TIM2_IRQHandler(void);
void TIM4_IRQHandler(void);
#endif
