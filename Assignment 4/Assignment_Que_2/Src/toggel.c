/*
 * toggel.c
 *
 *  Created on: Dec 18, 2025
 *      Author: aupat
 */

#include <stdint.h>
#include <stdio.h>

#include"stm32f407xx.h"
#include"toggel.h"

void switch_init(void)
{

	RCC->AHB1ENR |= BV(0);

	GPIOD->MODER &= ~(BV(0) | BV(1));

	GPIOD->OSPEEDR &= ~(BV(0) | BV(1));

	GPIOD->PUPDR &= ~(BV(0) | BV(1));
}
int button(void)
{
	if ((GPIOA->IDR) & BV(0) )
	{
		return 1;
	}
}

void led_init(void)
{
	//0. enable clock for GPIOD in AHB1
	RCC->AHB1ENR |= BV(3);
	//1. select mode as output
	GPIOD->MODER &= ~(BV(29));
	GPIOD->MODER |= BV(28);
	//2. select type as push pull
	GPIOD->OTYPER &= ~(BV(14));
	//3. select speed as low
	GPIOD->OSPEEDR &= ~(BV(29));
	GPIOD->OSPEEDR &= ~(BV(28));
	//4. select pull up/down as no
	GPIOD->PUPDR &= ~(BV(29));
	GPIOD->PUPDR &= ~(BV(28));
}
void led_on(void)
{
	GPIOD->ODR ^= BV(14);
}


