/*
 * PWM.h
 *
 *  Created on: Aug 17, 2023
 *      Author: Administrator
 */

#ifndef INC_PWM_H_
#define INC_PWM_H_

#include "main_app.h"


#define PWM_INSTANCE 			TIM2
#define PWM_CHANNEL_1			TIM_CHANNEL_1
#define PWM_CHANNEL_2			TIM_CHANNEL_2
#define PWM_CHANNEL_3			TIM_CHANNEL_3
#define PWM_CHANNEL_4			TIM_CHANNEL_4
#define PWM_GPIO				GPIOA
#define PWM_GPIO_PINS			GPIO_PIN_0 | GPIO_PIN_1
//#define PWM_GPIO_PINS			GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3
#define PWM_GPIO_AF        		GPIO_AF1_TIM2
#define MAX_PWM_USEC 			2100
#define CNTR_PWM_USEC 			1500
#define MIN_PWM_USEC 			900
#define __PWM_CLK_ENABLE()   	do { \
										__HAL_RCC_TIM2_CLK_ENABLE(); \
										__HAL_RCC_GPIOA_CLK_ENABLE(); \
								} while(0U)
#define __PWM_NVIC_ENABLE()   	do { \
										HAL_NVIC_SetPriority(USART1_IRQn, 15, 0); \
										HAL_NVIC_EnableIRQ(USART1_IRQn); \
								} while(0U)

TIM_HandleTypeDef hPWM;


/*
 * Hitec servo:
 * 	50hz period
 * 	0.9ms min / 1.5ms center / 2.1ms max
 */
void PWM_Timer_Initialization(void);
void PWM_GPIO_Initialization(TIM_HandleTypeDef *htim);
void PWM_Initialization(void);
void PWM_SET_CHANNEL1(uint16_t pwm_microsec);
void PWM_SET_CHANNEL2(uint16_t pwm_microsec);
void PWM_SET_CHANNEL3(uint16_t pwm_microsec);
void PWM_SET_CHANNEL4(uint16_t pwm_microsec);



#endif /* INC_PWM_H_ */
