/*=============================================================================
 * Author: Ignacio Majul <imajul89@gmail.com>
 * Date: 2019/09/15
 *===========================================================================*/

/*=====[Inclusions of function dependencies]=================================*/

#include "../../../Mis_programas/encoder/inc/encoder.h"

#include "sapi.h"

char* itoa(int value, char* result, int base) {
   // check that the base if valid
   if (base < 2 || base > 36) { *result = '\0'; return result; }

   char* ptr = result, *ptr1 = result, tmp_char;
   int tmp_value;

   do {
      tmp_value = value;
      value /= base;
      *ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value - value * base)];
   } while ( value );

   // Apply negative sign
   if (tmp_value < 0) *ptr++ = '-';
   *ptr-- = '\0';
   while(ptr1 < ptr) {
      tmp_char = *ptr;
      *ptr--= *ptr1;
      *ptr1++ = tmp_char;
   }
   return result;
}


int main( void )
{
	bool_t n = OFF;
	uint8_t dato1;
	uint8_t encoder0PinA = 3;
	uint8_t encoder0PinB = 4;
	uint8_t encoder0Pos = 0;
	uint8_t encoder0PinALast = LOW;
   // ----- Setup -----------------------------------
   boardConfig();
   uartConfig( UART_USB, 115200 );
   uartWriteByte( UART_USB, "hola" );

   // ----- Repeat for ever -------------------------
   while( true ) {
	   n = gpioRead(encoder0PinA);
	     if ((encoder0PinALast == LOW) && (n == HIGH)) {
	       if (gpioRead(encoder0PinB) == LOW) {
	         encoder0Pos--;
	       } else {
	         encoder0Pos++;
	       }
	       uartWriteByte( UART_USB, 1 );

	     }
	     encoder0PinALast = n;
   }

   // YOU NEVER REACH HERE, because this program runs directly or on a
   // microcontroller and is not called by any Operating System, as in the 
   // case of a PC program.
   return 0;
}
