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
    User_Button_Init();

    HAL_UART_Transmit_IT(&huart3, "HAL_Init....LED_Init....UART_Init enabled\n", 43);

    while (1)
    {
        //__NOP();
        HAL_UART_Receive_IT(&huart3, bufferRX, sizeof(bufferRX));
    }
}