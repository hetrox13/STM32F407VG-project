/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* External variables --------------------------------------------------------*/
extern UART_HandleTypeDef huart3;

void SysTick_Handler(void)
{
    HAL_IncTick();
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    HAL_UART_Transmit(&huart3, " command sent:\n", 16, 1000);

    if (memcmp(bufferRX, AT_COMMAND_LED_GREEN, 7) == 0)
    {
        HAL_GPIO_TogglePin(LED_GPIO_PORT, GPIO_PIN_12);
    }
    else if (memcmp(bufferRX, AT_COMMAND_LED_ORANGE, 7) == 0)
    {
        HAL_GPIO_TogglePin(LED_GPIO_PORT, GPIO_PIN_13);
    }
    else if (memcmp(bufferRX, AT_COMMAND_LED_RED, 7) == 0)
    {
        HAL_GPIO_TogglePin(LED_GPIO_PORT, GPIO_PIN_14);
    }
    else if (memcmp(bufferRX, AT_COMMAND_LED_BLUE, 7) == 0)
    {
        HAL_GPIO_TogglePin(LED_GPIO_PORT, GPIO_PIN_15);
    }
    else
    {
        HAL_UART_Transmit(&huart3, "command not found\n", 19, 1000);
    }
}

void USART3_IRQHandler(void)
{
    HAL_UART_IRQHandler(&huart3);
}

void EXTI0_IRQHandler(void)
{
    HAL_GPIO_EXTI_IRQHandler(USER_BUTTON_PIN);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    if (GPIO_Pin == USER_BUTTON_PIN)
    {
        HAL_GPIO_TogglePin(LED_GPIO_PORT, LED_PIN);
    }
}
