#include <stdio.h>
#include "stdio_setup.h"
#include "display_uart_setup.h"

int main(void)
{
	UartInit();
	Display_Uart_Init();

	printf(" Hi Mike I am alive. \r\n");

	 Display_UartPutchar(0x11);
	 Display_UartPutchar(0x0A);
	 Display_UartPutchar(0x1B);
	 Display_UartPutchar(0x44);
	 Display_UartPutchar(0x4C);
	 Display_UartPutchar(0x1B);
	 Display_UartPutchar(0x47);
	 Display_UartPutchar(0x44);
	 Display_UartPutchar(0x00);
	 Display_UartPutchar(0x00);
	 Display_UartPutchar(0x9F);
	 Display_UartPutchar(0x67);
	 Display_UartPutchar(0x72);

	 printf("Done Mike! \r\n" );

	while(1) {
	}
}