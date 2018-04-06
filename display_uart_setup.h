#ifndef DISPLAY_UART_SETUP_H_
#define DISPLAY_UART_SETUP_H_

void Display_Uart_Init(void);
void Display_UartPutchar(char data);
int Display_UartGetchar(void);
void Display_SendData( unsigned char* buf, unsigned char len);

#endif /*DISPLAY_UART_SETUP_H_ */