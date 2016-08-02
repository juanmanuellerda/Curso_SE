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
			
#define BIT_24 0X1000000
#define BIT_26 0X4000000
#define BIT_28 0X10000000
#define BIT_30 0X40000000
#define BIT_12 0X1000
#define BIT_13 0X2000
#define BIT_14 0X4000
#define BIT_15 0X8000

void delay (uint16_t delay);

void main(void)
{
//configuración

//habilito el clk del bus GPIOD

	RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
	GPIOD->MODER |= BIT_24;
	GPIOD->MODER |= BIT_26;
	GPIOD->MODER |= BIT_28;
	GPIOD->MODER |= BIT_30;


	while (1) {
		//aplicación

		GPIOD->ODR ^= BIT_12;
		delay (5000);
		GPIOD->ODR ^= BIT_12;
		GPIOD->ODR ^= BIT_13;
		delay (5000);
		GPIOD->ODR ^= BIT_13;
		GPIOD->ODR ^= BIT_14;
		delay (5000);
		GPIOD->ODR ^= BIT_14;
		GPIOD->ODR ^= BIT_15;
		delay (5000);
		GPIOD->ODR ^= BIT_15;
	}
}


void delay(uint16_t delay) {
	uint8_t i;
	while (delay-- > 0) {
		for (i = 100; i > 0; i--) {
			asm("nop");
		}
	}
}
