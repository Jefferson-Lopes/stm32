/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Jefferson Lopes
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include "stm32f767xx.h"

#define GPIOB_EN            (1U<<1)

int main(void){
	RCC->AHB1ENR |= GPIOB_EN;
	GPIOB->MODER |= (1U<<0);
	GPIOB->MODER &=~ (1U<<1);

	GPIOB->ODR |= (1U<<0);
}
