/*
 * PWM.c
 *
 *  Created on: Aug 17, 2023
 *      Author: Administrator
 */


#include "PWM.h"

void PWM_Timer_Initialization(void)
{
	TIM_OC_InitTypeDef tim2PWM_Config = {0};
	// 50 HZ for 50mhz clock
	hPWM.Instance 			= PWM_INSTANCE;
	hPWM.Init.Prescaler 	= 49;
	hPWM.Init.Period		= 20000-1;
	if ( HAL_TIM_PWM_Init(&hPWM) != HAL_OK)
	{
		RF_SendMsg("PWM_Init error \r\n");
		Error_Handler();
	}


	tim2PWM_Config.OCMode     	= TIM_OCMODE_PWM1;
	tim2PWM_Config.OCPolarity 	= TIM_OCPOLARITY_HIGH;
	tim2PWM_Config.Pulse 		= CNTR_PWM_USEC;

	if( HAL_TIM_PWM_ConfigChannel(&hPWM, &tim2PWM_Config, TIM_CHANNEL_1) != HAL_OK )
	{
		RF_SendMsg("HAL_TIM_PWM_ConfigChannel1 error \r\n");
		Error_Handler();
	}

	if( HAL_TIM_PWM_ConfigChannel(&hPWM, &tim2PWM_Config, TIM_CHANNEL_2) != HAL_OK )
	{
		RF_SendMsg("HAL_TIM_PWM_ConfigChannel2 error \r\n");
		Error_Handler();
	}
	//
	//	if( HAL_TIM_PWM_ConfigChannel(&hPWM, &tim2PWM_Config, TIM_CHANNEL_3) != HAL_OK )
	//	{
	//		RF_SendMsg("HAL_TIM_PWM_ConfigChannel3 error \r\n");
	//		Error_Handler();
	//	}
	//
	//	if( HAL_TIM_PWM_ConfigChannel(&hPWM, &tim2PWM_Config, TIM_CHANNEL_4) != HAL_OK )
	//	{
	//		RF_SendMsg("HAL_TIM_PWM_ConfigChannel4 error \r\n");
	//		Error_Handler();
	//	}
}

void PWM_GPIO_Initialization(TIM_HandleTypeDef *htim)
{
	if( htim->Instance == PWM_INSTANCE)
	{
		GPIO_InitTypeDef tim2oc_ch_gpios;
		// enable peripheral clocks for timer2
		__PWM_CLK_ENABLE();

		// config gpios to behave as timer2 channel 1-2-3-4
		tim2oc_ch_gpios.Pin 		= PWM_GPIO_PINS;
		tim2oc_ch_gpios.Mode 		= GPIO_MODE_AF_PP;
		tim2oc_ch_gpios.Pull   	 	= GPIO_NOPULL;
		tim2oc_ch_gpios.Speed   	= GPIO_SPEED_FREQ_HIGH;
		tim2oc_ch_gpios.Alternate 	= PWM_GPIO_AF;
		HAL_GPIO_Init(PWM_GPIO, &tim2oc_ch_gpios);

		// nvic setting
		__PWM_NVIC_ENABLE();
	}
}

void PWM_Initialization(void)
{
	PWM_Timer_Initialization();
	if( HAL_TIM_PWM_Start(&hPWM, TIM_CHANNEL_1) != HAL_OK )
	{
		RF_SendMsg("HAL_TIM_PWM_Start error \r\n");
		Error_Handler();
	}

	if( HAL_TIM_PWM_Start(&hPWM, TIM_CHANNEL_2) != HAL_OK )
	{
		RF_SendMsg("HAL_TIM_PWM_Start error \r\n");
		Error_Handler();
	}

//	if( HAL_TIM_PWM_Start(&hPWM, TIM_CHANNEL_3) != HAL_OK )
//	{
//		RF_SendMsg("HAL_TIM_PWM_Start error \r\n");
//		Error_Handler();
//	}
//
//	if( HAL_TIM_PWM_Start(&hPWM, TIM_CHANNEL_4) != HAL_OK )
//	{
//		RF_SendMsg("HAL_TIM_PWM_Start error \r\n");
//		Error_Handler();
//	}

	PWM_SET_CHANNEL1(CNTR_PWM_USEC);

	PWM_SET_CHANNEL2(CNTR_PWM_USEC);
}

void PWM_SET_CHANNEL1(uint16_t pwm_microsec)
{
	if(pwm_microsec >MAX_PWM_USEC)
		pwm_microsec = MAX_PWM_USEC;
	if(pwm_microsec < MIN_PWM_USEC)
		pwm_microsec = MIN_PWM_USEC;
	__HAL_TIM_SET_COMPARE(&hPWM, PWM_CHANNEL_1, pwm_microsec);
}

void PWM_SET_CHANNEL2(uint16_t pwm_microsec)
{
	if(pwm_microsec >MAX_PWM_USEC)
		pwm_microsec = MAX_PWM_USEC;
	if(pwm_microsec < MIN_PWM_USEC)
		pwm_microsec = MIN_PWM_USEC;
	__HAL_TIM_SET_COMPARE(&hPWM, PWM_CHANNEL_2, pwm_microsec);
}

void PWM_SET_CHANNEL3(uint16_t pwm_microsec)
{
	if(pwm_microsec >MAX_PWM_USEC)
		pwm_microsec = MAX_PWM_USEC;
	if(pwm_microsec < MIN_PWM_USEC)
		pwm_microsec = MIN_PWM_USEC;
	__HAL_TIM_SET_COMPARE(&hPWM, PWM_CHANNEL_3, pwm_microsec);
}

void PWM_SET_CHANNEL4(uint16_t pwm_microsec)
{
	if(pwm_microsec >MAX_PWM_USEC)
		pwm_microsec = MAX_PWM_USEC;
	if(pwm_microsec < MIN_PWM_USEC)
		pwm_microsec = MIN_PWM_USEC;
	__HAL_TIM_SET_COMPARE(&hPWM, PWM_CHANNEL_4, pwm_microsec);
}
