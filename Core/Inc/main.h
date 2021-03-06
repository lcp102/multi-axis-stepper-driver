/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdbool.h>
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */
#define PRESCALER 256.0
volatile uint8_t newCommandAvailable;

typedef struct StepperMotor
{
	void (*sendPulse)();
	void (*setDirection)(int);
	volatile int8_t direction;

	volatile int absolutePosition;
	volatile int16_t currentCount;
	volatile int16_t targetCount;

	//Other motion parameters
	volatile uint8_t rampingUp;
	volatile uint8_t rampingDown;
	volatile uint8_t rampUpCount;
	volatile uint8_t rampDownCount;


	//Set pulseFlag equal to 0 for no pulse, 1 for a pulse
	volatile uint8_t pulseFlag;
	TIM_HandleTypeDef* timerHandle;
	volatile float scaleFactor;
	volatile float estDurationOfMovement;


	//For fresh instructions from USB, all of them are zero  otherwise
	volatile int8_t newDirection;
	volatile int16_t newAbsoluteTarget;
	volatile int16_t newAbsoluteTargetUSB;

}StepperMotor;

StepperMotor motor[3];

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
