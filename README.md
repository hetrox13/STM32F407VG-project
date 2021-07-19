# STM32F407VG-project by Evaldas Mendzaris :)

STM32F4 DISCOVERY Board project. This project was written in VScode IDE with PlatformIO.

![STM32 Discovery](/images/STM32F4DISCOVERY.jpg)

In this small project, the board is programmed to send and receive UART interrupt requests. By receiving AT serial commands you can control to toggle LEDs individualy.
With External Interrupts enabled, pressing user button will toggle 4 LEDs simultaneously.
````
     AT+LED1         ---------> GREEN LED ON
     AT+LED2         ---------> ORANGE LED ON
     AT+LED3         ---------> RED LED ON
     AT+LED4         ---------> BLUE LED ON
````

![serial](/images/serial.png)
