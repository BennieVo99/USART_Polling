/**************************************************
* Function name	: static void USART_init(void)
* Created by	: thanhchuong
* Date created	: Aug 2, 2021
* Description	: Use to set baud rate
                  set frame format
                  enable receiver and transmitter
**************************************************/

/**************************************************
* Function name	        : static void USART_send(char data, uint8_t usart_num)
* char data             : Data need to transmit
* unit8_t usart_num	: The codition number to transmit
* Created by		: thanhchuong
* Date created		: Aug 2, 2021
* Description		: Send the data and send 1 letter per command
                          such as send 'C' 'H' 'U' 'O' 'N' 'G'
**************************************************/

/**************************************************
* Function name         : static void USART_putstring(char *StringPtr, uint8_t usart_num)
* char *StringPtr       : Data need to transmit
* unit8_t usart_num     : The codition number to transmit
* Created by            : thanhchuong
* Date created          : Aug 2, 2021
* Description           : Send the data and many letter per command
                          such as send  'CODER'
**************************************************/


#ifndef USART_POLLING_SERIAL_V2_H_
#define USART_POLLING_SERIAL_V2_H_


/*Initialize for USART*/
static void USART_init(void)
{
  _inline_USART_init();
}


static void USART_send(char data, uint8_t usart_num)
{
  _inline_USART_send(data,usart_num);
}


static void USART_putstring(char *StringPtr, uint8_t usart_num)
/*sends the characters from the string one at a time to the USART*/
{
  _inline_USART_putstring(StringPtr,usart_num);
}


static void USART_putstring_P(const char *StringPtr, uint8_t usart_num)
/*sends the characters from the string one at a time to the USART*/
{
  while(pgm_read_byte(StringPtr) != 0x00)
  {
    USART_send(pgm_read_byte(StringPtr++),usart_num);
  }
}

#endif /* USART_POLLING_SERIAL_V2_H_ */
