/*
 * delay.c
 *
 *  Created on: 2 de ago. de 2016
 *      Author: jmLerda
 */

#include <stdint.h>
#include "delay.h"


void delay(uint16_t delay) {
	uint8_t i;
	while (delay-- > 0) {
		for (i = 10; i > 0; i--) {
			asm("nop");
		}
	}
}

