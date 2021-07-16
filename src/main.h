#ifndef MAIN_H
#define MAIN_H

#include "stm32f4xx_hal.h"

/* External variables --------------------------------------------------------*/
extern uint8_t bufferRX[7];
extern uint8_t data[13];

//Prototypes
void LED_Init();
void UART_Init(void);
void User_Button_Init(void);

//LEDs PIN configuration
#define LED_PIN GPIO_PIN_15 | GPIO_PIN_14 | GPIO_PIN_13 | GPIO_PIN_12
#define LED_GPIO_PORT GPIOD
#define LED_GPIO_CLK_ENABLE() __HAL_RCC_GPIOD_CLK_ENABLE()

#define AT_COMMAND_LED_GREEN "AT+LED1"
#define AT_COMMAND_LED_ORANGE "AT+LED2"
#define AT_COMMAND_LED_RED "AT+LED3"
#define AT_COMMAND_LED_BLUE "AT+LED4"

/*LED turn on  commands:
    ***     AT+LED1         ---------> GREEN LED ON
    ***     AT+LED2         ---------> ORANGE LED ON
    ***     AT+LED3         ---------> RED LED ON
    ***     AT+LED4         ---------> BLUE LED ON
*/

// UART Pin configuration
#define UART_GPIO_CLK_ENABLE() __HAL_RCC_GPIOC_CLK_ENABLE()
#define UART_PERIPHERAL_CLK_ENABLE() __HAL_RCC_USART3_CLK_ENABLE()
#define UART_GPIO_PORT GPIOC
#define UART_PIN_TX GPIO_PIN_10
#define UART_PIN_RX GPIO_PIN_11

//User Button configuration
#define USER_BUTTON_CLK_ENABLE() __HAL_RCC_GPIOA_CLK_ENABLE()
#define USER_BUTTON_GPIO_PORT GPIOA
#define USER_BUTTON_PIN GPIO_PIN_0

#endif // MAIN_H