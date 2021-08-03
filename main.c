/*
 * main.c
 *
 *  Created on: Jul 24, 2021
 *      Author: thanhchuong
 */

#include <stdio.h>
#include <stdint.h>

#include <util/delay.h>
#include <avr/io.h>

#include <avr/USART_Interrupt_Serial.h>

int main(){
  //Initialize for USART
  USART_init();
  while(1){
    //Send Char one by one with singel quote
    USART_send('C',0);
    USART_send('H',0);
    USART_send('U',0);
    USART_send('O',0);
    USART_send('N',0);
    USART_send('G',0);
    USART_send('\n',0);
    //Send String with double quotes
    USART_putstring("CODER",0);
    USART_putstring("\n",0);
    //Delay for 1s
    _delay_ms(1000);
	}
}
