#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/uart.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "conversion.h"

uint32_t SysClkFreq;

void my_UARTprintString(char * input_string);

int main(void)
{
    /*sets the clock freq
     *(external crystal freq | use external crystal | PLL source | PLL VCO to 320Mhz), desired freq
     */
    SysClkFreq = SysCtlClockFreqSet((SYSCTL_XTAL_25MHZ | SYSCTL_OSC_MAIN | SYSCTL_USE_PLL | SYSCTL_CFG_VCO_320), 120000000);

    //USRLED 1 and 2 are connected to port N, turns it on
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPION);

    //turning on URAT0
    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);

    //setting pins for RX / TX
    GPIOPinConfigure(GPIO_PA0_U0RX);
    GPIOPinConfigure(GPIO_PA1_U0TX);
    GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);

    UARTConfigSetExpClk(UART0_BASE, SysClkFreq, 115200,
                        (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE | UART_CONFIG_PAR_NONE));

    my_UARTprintString("Project for: Andrew Kuklinski | 4-8-2018");
    UARTCharPut(UART0_BASE, 10);    //carriage return
    UARTCharPut(UART0_BASE, 13);    //new line
    //configures Port N, pins 0 and 1 as output
    GPIOPinTypeGPIOOutput(GPIO_PORTN_BASE, GPIO_PIN_0);
    //writes 0x0 to both pins turning them off
    GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, 0x00);

    uint32_t counter = 0;
    uint8_t counter_buff[16] = {0};
    while(1)
    {
        GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, 1);
        //(120000000cycle/sec) * (1 call/3 cycle) * (1 sec / 2 cycle) = 20000000calls/cycle
        SysCtlDelay(2000000);
        GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0,0);
        SysCtlDelay(2000000);
        counter++;

        my_itoa(counter, counter_buff,10);
        my_UARTprintString("LED Counter: ");
        my_UARTprintString((char*)counter_buff);
        UARTCharPut(UART0_BASE, 13);    //carriage return
        UARTCharPut(UART0_BASE, 10);
    }
}


void my_UARTprintString(char * input_string)
{
    uint8_t string_length = strlen(input_string);
    uint8_t i;
    for(i=0; i<string_length; i++)
    {
        UARTCharPut(UART0_BASE, input_string[i]);
    }

}

















