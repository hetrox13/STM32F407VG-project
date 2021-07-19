/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private variables ---------------------------------------------------------*/
UART_HandleTypeDef huart3;

void LED_Init()
{
    //LEDs GPIO config
    LED_GPIO_CLK_ENABLE();
    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.Pin = LED_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
    HAL_GPIO_Init(LED_GPIO_PORT, &GPIO_InitStruct);
}

void UART_Init(void)
{
    //UART GPIO config
    UART_GPIO_CLK_ENABLE();
    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.Pin = UART_PIN_TX | UART_PIN_RX;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF7_USART3;
    HAL_GPIO_Init(UART_GPIO_PORT, &GPIO_InitStruct);

    //UART peripheral config
    UART_PERIPHERAL_CLK_ENABLE();
    huart3.Instance = USART3;
    huart3.Init.BaudRate = 9600;
    huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    huart3.Init.Mode = UART_MODE_TX_RX;
    huart3.Init.OverSampling = UART_OVERSAMPLING_16;
    huart3.Init.Parity = UART_PARITY_NONE;
    huart3.Init.StopBits = UART_STOPBITS_1;
    huart3.Init.WordLength = UART_WORDLENGTH_8B;
    HAL_UART_Init(&huart3);

    /* USART3 interrupt Init */
    HAL_NVIC_SetPriority(USART3_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(USART3_IRQn);
}

void User_Button_Init(void)
{
    // User Button GPIO config
    USER_BUTTON_CLK_ENABLE();
    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.Pin = USER_BUTTON_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
    HAL_GPIO_Init(USER_BUTTON_GPIO_PORT, &GPIO_InitStruct);

    // User Button SYSCFG config
    USER_BUTTON_SYSCFG_CLK_ENABLE();

    //User Button External Interrupt Init
    HAL_NVIC_SetPriority(EXTI0_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(EXTI0_IRQn);
}
