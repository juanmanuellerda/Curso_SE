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

		unsigned int x = 255;
		int c, a = 0;

		while (1) {
			if (a==0){
						c++;
						if (c>250){
							a=1;
						}
			}
			if (a==1){
						c--;
						if(c<1){
						a=0;
						}
			}
		GPIOD->ODR ^= BIT_12;
		delay (x + c*20);
		GPIOD->ODR ^= BIT_12;
		GPIOD->ODR ^= BIT_13;
		delay (x + c*20);
		GPIOD->ODR ^= BIT_13;
		GPIOD->ODR ^= BIT_14;
		delay (x + c*20);
		GPIOD->ODR ^= BIT_14;
		GPIOD->ODR ^= BIT_15;
		delay (x + c*20);
		GPIOD->ODR ^= BIT_15;

		}
}
