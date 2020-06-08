#define F_CPU 16000000UL
#include <stdio.h>
#include <stdlib.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <PHT_LCD16x2_4bit.h>

#include "DHT.h"
#define DHT_TYPE DHT_DHT22
#define DHT_FLOAT 0

int main(void)
{
	lcd_init();
	char printbuff[100];
	char printbuff1[100];
	float temperature = 0;
	float humidity = 0;
	for (;;) {
		if(dht_gettemperaturehumidity(&temperature, &humidity) != -1) {

			#if DHT_FLOAT == 0
			itoa(temperature, printbuff, 10);
			#elif DHT_FLOAT == 1
			dtostrf(temperature, 3, 3, printbuff);
			#endif
			lcd_setcursor(0,1);
			lcd_string(printbuff);
			#if DHT_FLOAT == 0
			itoa(humidity, printbuff1, 10);
			#elif DHT_FLOAT == 1
			dtostrf(humidity, 3, 3, printbuff1);
			#endif
			lcd_setcursor(0,2);
			lcd_string(printbuff1);

			} else {
		}

		_delay_ms(1500);
	}
	
	return 0;
}
