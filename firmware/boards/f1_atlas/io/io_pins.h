#pragma once

#define LED_BLUE_PORT GPIOB
#define LED_BLUE_PIN 13
#define LL_LED_BLUE_PIN LL_GPIO_PIN_13

#define LED_GREEN_PORT GPIOA
#define LED_GREEN_PIN 8

// Communication - UART
#define UART_GPIO_PORT				GPIOA
#define LL_UART_TX_PIN				LL_GPIO_PIN_9
#define LL_UART_RX_PIN				LL_GPIO_PIN_10

// Communication - CAN1
#define CAN_GPIO_PORT				GPIOA
#define LL_CAN_TX_PIN				LL_GPIO_PIN_12
#define LL_CAN_RX_PIN				LL_GPIO_PIN_11

// LSU 4.2 - 6.8K
#define NERNST_42_ESR_DRIVER_PORT   GPIOB
#define NERNST_42_ESR_DRIVER_PIN    12

// LSU 4.9 - 22K
#define NERNST_49_ESR_DRIVER_PORT	GPIOB
#define NERNST_49_ESR_DRIVER_PIN	11

#define NERNST_49_BIAS_PORT			GPIOB
#define NERNST_49_BIAS_PIN			2

// LSU ADV - 47K
#define NERNST_ADV_ESR_DRIVER_PORT	GPIOB
#define NERNST_ADV_ESR_DRIVER_PIN	10

#define HEATER_PWM_DEVICE			PWMD3
#define HEATER_PWM_CHANNEL_0		0
#define HEATER_PWM_CHANNEL_1		1

// This board with current MCU is not able to output PWM signals to pins used for Heater MOSFETs
// Using IRQ -> GPIO proxy
#define HEATER_PWM_GPIO_PROXY		1
// L_heater_pwm - PB7
#define L_HEATER_PORT				GPIOB
#define L_HEATER_PIN				7
// R_heater_pwm - PB6
#define R_HEATER_PORT				GPIOB
#define R_HEATER_PIN				6

// PA1 TIM2_CH2
#define PUMP_DAC_PWM_DEVICE			PWMD2
#define PUMP_DAC_PWM_CHANNEL_0		2	/* left */
#define PUMP_DAC_PWM_CHANNEL_1		1 	/* right */

#define ID_SEL1_PORT				GPIOC
#define ID_SEL1_PIN					13

// PC15 - SPI1_CS1 - L_EGT
#define EGT_CS0_PORT				GPIOC
#define EGT_CS0_PIN					15
// PC14 - SPI1_CS0 - R_EGT
#define EGT_CS1_PORT				GPIOC
#define EGT_CS1_PIN					14
