/*
 * gpio.h
 *
 *  Created on: Dec 18, 2025
 *      Author: aupat
 */

#ifndef gpio
#define gpio


#define BV(n) (1 << (n))

void switch_init(void);
int switch_status(void);

#define GREEN_LED     12
#define ORANGE_LED    13
#define RED_LED       14
#define BLUE_LED      15

#define LED_PORT GPIOD


void led_init(void);
void led_one(void);
void led_two(void);
void led_three(void);
void led_four(void);

#endif /* MY_SWITCH_H_ */
