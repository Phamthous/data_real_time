/*
 * IncFile1.h
 *
 * Created: 07/06/2020 10:43:44 AM
 *  Author: HCMUS-VL-VLKT
 */ 


#ifndef DHT_H_
#define DHT_H_

#include <stdio.h>
#include <avr/io.h>

//setup port
#define DHT_DDR DDRD
#define DHT_PORT PORTD
#define DHT_PIN PIND
#define DHT_INPUTPIN PD6

//sensor type
#define DHT_DHT11 1
#define DHT_FLOAT 0

//timeout retries
#define DHT_TIMEOUT 200

//functions
#if DHT_FLOAT == 1
extern int8_t dht_gettemperature(float *temperature);
extern int8_t dht_gethumidity(float *humidity);
extern int8_t dht_gettemperaturehumidity(float *temperature, float *humidity);
#elif DHT_FLOAT == 0
extern int8_t dht_gettemperature(int8_t *temperature);
extern int8_t dht_gethumidity(int8_t *humidity);
extern int8_t dht_gettemperaturehumidity(int8_t *temperature, int8_t *humidity);
#endif

#endif