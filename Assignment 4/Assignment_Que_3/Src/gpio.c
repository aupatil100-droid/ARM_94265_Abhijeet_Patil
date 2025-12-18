/*
 * gpio.c
 *
 *  Created on: Dec 18, 2025
 *      Author: aupat
 */

#include <stdint.h>
#include <stdio.h>
#include"stm32f407xx.h"
#include"gpio.h"


void switch_init(void)
{
	//0. enable clock for GPIOA in AHB1
	RCC->AHB1ENR |= BV(0);
	//1. select mode as Input
	GPIOA->MODER &= ~(BV(0) | BV(1) );


	//2. select type as push pull
	//GPIOA->OTYPER &= ~(BV(0) );
	//3. select speed as low
	GPIOA->OSPEEDR &= ~(BV(0) | BV(1));

	//4. select pull up/down as no
	GPIOA->PUPDR &= ~(BV(0) | BV(1));

}
int switch_status(void)
{
	if ((GPIOA->IDR) & BV(0) )
	{
		return 1 ; // switch is press
	}
	else
	{
		return 0 ; // switch is nor press
	}
}

void led_init(void)
{
	//0. enable clock for GPIOD in AHB1
	RCC->AHB1ENR |= BV(3);
	//1. select mode as output
	LED_PORT->MODER &= ~(BV(25) | BV(27) | BV(29) | BV(31));
	LED_PORT->MODER |= BV(24) | BV(26) | BV(28) | BV(30);
	//2. select type as push pull
	LED_PORT->OTYPER &= ~(BV(12) | BV(13) | BV(14) | BV(15));
	//3. select speed as low
	LED_PORT->OSPEEDR &= ~(BV(25) | BV(27) | BV(29) | BV(31));
	GPIOD->OSPEEDR &= ~(BV(24) | BV(26) | BV(28) | BV(30));
	//4. select pull up/down as no
	LED_PORT->PUPDR &= ~(BV(25) | BV(27) | BV(29) | BV(31));
	LED_PORT->PUPDR &= ~(BV(24) | BV(26) | BV(28) | BV(30));
}
void led_one(void)
{
	GPIOD->ODR |= BV(GREEN_LED);
}

void led_two(void)
{
	GPIOD->ODR |= BV(GREEN_LED)| BV(BLUE_LED);
}
void led_three(void)
{
	GPIOD->ODR&=~( BV(GREEN_LED)|  BV(BLUE_LED));
}
void led_four(void)
{
	GPIOD->ODR &=~( BV(GREEN_LED)| BV(BLUE_LED));
}

