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

//PB0

#define PERIPH_BASE         (0x40000000UL)
#define AHB1_PERIPH_OFFSET  (0x00020000UL)
#define AHB1_PERIPH_BASE    (PERIPH_BASE + AHB1_PERIPH_OFFSET)
#define GPIOB_OFFSET        (0x0400U)
#define GPIOB_BASE          (AHB1_PERIPH_BASE + GPIOB_OFFSET)
#define RCC_OFFSET          (0x3800UL)
#define RCC_BASE            (AHB1_PERIPH_BASE + RCC_OFFSET)
#define AHB1EN_R_OFFSET     (0x0030UL)
#define RCC_AHB1EN_R        (*(volatile unsigned int *)(RCC_BASE + AHB1EN_R_OFFSET))
#define GPIOB_EN            (1U<<1)
#define MODE_R_OFFSET       (0X0000Ul)
#define GPIOB_MODE_R        (*(volatile unsigned int *)(GPIOB_BASE + MODE_R_OFFSET))
#define OD_R_OFFSET         (0x0014UL)
#define GPIOB_OD_R          (*(volatile unsigned int *)(GPIOB_BASE + OD_R_OFFSET))
#define PIN0                (1U<<0)
#define LED_PIN             PIN0


int main(void){
	// enable clock access to GPIOB
	RCC_AHB1EN_R |= GPIOB_EN;

	// set PB0 as output pin
	GPIOB_MODE_R |= (1U<<0);
	GPIOB_MODE_R &=~(1U<<1);

	for(;;){
		// toggle PB0
		GPIOB_OD_R ^= LED_PIN;

		// delay
		for (int i = 0; i < 100000; i++){}
	}
}
