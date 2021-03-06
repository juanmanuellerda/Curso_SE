/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/

#include "stm32f4xx.h"
#include "stm32f4_discovery.h"
#include "delay.h"
#include "bits.h"

void main(void)
{
//configuración

//habilito el clk del bus GPIOD

		RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
		GPIOD->MODER |= BIT_24;
		GPIOD->MODER |= BIT_26;
		GPIOD->MODER |= BIT_28;
		GPIOD->MODER |= BIT_30;

		float x = 500;
			int c = 0;
	while (1) {
		c++;

		GPIOD->ODR ^= BIT_12;
		delay (x + 50*c);
		GPIOD->ODR ^= BIT_12;
		GPIOD->ODR ^= BIT_13;
		delay (x + 50*c);
		GPIOD->ODR ^= BIT_13;
		GPIOD->ODR ^= BIT_14;
		delay (x + 50*c);
		GPIOD->ODR ^= BIT_14;
		GPIOD->ODR ^= BIT_15;
		delay (x + 50*c);
		GPIOD->ODR ^= BIT_15;
	}
}
