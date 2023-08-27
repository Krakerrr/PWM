/*
 * PWM.h
 *
 *  Created on: Aug 17, 2023
 *      Author: Administrator
 */

#ifndef INC_PWM_H_
#define INC_PWM_H_

#include "main_app.h"


#define PWM_INSTANCE 		TIM2
#define PWM_CHANNEL_1		TIM_CHANNEL_1
#define PWM_CHANNEL_2		TIM_CHANNEL_2
#define PWM_CHANNEL_3		TIM_CHANNEL_3
#define PWM_CHANNEL_4		TIM_CHANNEL_4
#define MAX_PWM_USEC 		2100
#define CNTR_PWM_USEC 		1500
#define MIN_PWM_USEC 		900

TIM_HandleTypeDef hPWM;


/*
 * Hitec servo:
 * 	50hz period
 * 	0.9ms min / 1.5ms center / 2.1ms max
 */
void PWM_Timer_Initialization(void);
void PWM_GPIO_Initialization(void);
void PWM_Initialization(void);
void PWM_SET_CHANNEL1(uint16_t pwm_microsec);



#endif /* INC_PWM_H_ */
