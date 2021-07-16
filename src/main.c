#include "main.h"
#include <stdio.h>
#include <string.h>

extern UART_HandleTypeDef huart3;

uint8_t bufferRX[7] = {0};
uint8_t data[13] = "Hello World\n";

int main(void)
{
    HAL_Init();
    LED_Init();
    UART_Init();

    HAL_UART_Transmit_IT(&huart3, "HAL_Init....LED_Init....UART_Init enabled\n", 43);
    // HAL_UART_Receive_IT(&huart3, bufferRX, sizeof(bufferRX));
    // HAL_UART_Transmit(&huart3, "HAL_Init....LED_Init....UART_Init enabled\n", 43, 1000);
    // HAL_UART_Transmit(&huart3, data, sizeof(data), 1000);

    while (1)
    {
        //__NOP();
        HAL_UART_Receive_IT(&huart3, bufferRX, sizeof(bufferRX));
        //HAL_UART_Receive(&huart3, bufferRX, sizeof(bufferRX), 2000);
        // HAL_UART_Receive_IT(&huart3, bufferRX, sizeof(bufferRX));
        // HAL_Delay(1);
        // HAL_UART_Transmit(&huart3, bufferRX, sizeof(bufferRX), 1000);
        // HAL_Delay(1000);

        // HAL_GPIO_TogglePin(LED_GPIO_PORT, LED_PIN);
        // HAL_Delay(3000);
    }
}