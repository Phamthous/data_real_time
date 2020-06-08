 /***********************************************************
  *   Program:    GenerAllNew driver header
  *   Created:    07 February 2006
  *   Author:     Alexander Rakhmatulin
  *                 
  *   Comments:   functions & definitions
  ************************************************************/
// LCD is connected on PORTA in 4bit mode
#include <avr/io.h>

// This is the CPU's clock frequency
//#define F_CPU 7372800.0
//14745600.0

#define delay_us(Delay) do { \
if ((float)Delay*F_CPU/4000000.0 > 1.0) \
__asm__ __volatile__ ( "ldi r30,lo8(%0)" "\n\t" \
"ldi r31,hi8(%0)" "\n" \
"L_%=:\n\t" \
"sbiw r30,1" "\n\t" \
"brne L_%=" "\n\t" \
: \
: "n" ((unsigned short)((float)(Delay)*F_CPU/4000000.0)) \
: "r30", "r31" \
); \
else \
__asm__ __volatile__ ( \
".fill %0, 2, 0" "\n\t" \
: : "I" ((unsigned short)(F_CPU/(1000000.0*(float)(Delay)))) \
); \
} while (0)

//	Добавлено виртуальное описание порта и контактов

//Sas-Sas-Sas-Sas-Sas-Sas-Sas-Sas-Sas-Sas-Sas-Sas-Sas-Sas-Sas

// Определение портов для платы GenerAllNew

// Четырехразрядная шина данных
#define LCD_DATA PORTA
#define LCD_DDR DDRA

// Управление по порту A

//#define LCD_LED_DDR DDRD		//В GenerAllNew подсветка не
//#define LCD_LED_PORT PORTD	//отключается

//----- Some redefinition ---------------------------------------
#define Reset_pin_DDR DDRB		//pin to reset AD9834
#define Reset_pin_PORT PORTB	//pin to reset AD9834
#define Reset_pin 0				//pin to reset AD9834

#define CS_DDR DDRB		//pin to select AD8370
#define CS_PORT PORTB	//pin to select AD8370
#define CS 1			//pin to select AD8370

#define FSYNC_DDR DDRB		//	SPI
#define FSYNC_Port PORTB	//	SPI
#define FSYNC PORTB4		//	SPI

#define SCK 7
#define MISO 6
#define MOSI 5
//#define SS 4

#define UsartPort PORTD
#define UsartPortDDR DDRD

#define Rx	PORTD0
#define Tx	PORTD1
#define CTS	PORTD3
#define RTS	PORTD2

#define keysPort PORTC
#define keysPortDDR DDRC
#define keysPortPin PINC

// HexKeyBoard pins(ak1604)
#define KeyRow1 PORTC4
#define KeyRow2 PORTC5
#define KeyRow3 PORTC6
#define KeyRow4 PORTC7
#define KeyColumn1 PORTC0 
#define KeyColumn2 PORTC1
#define KeyColumn3 PORTC2
#define KeyColumn4 PORTC3

/** Size of the circular receive buffer, must be power of 2 */
#define KEYS_BUFFER_SIZE 32
/* 
** high byte error return code of kgetc()
*/

#define KEYS_BUFFER_OVERFLOW  0x0200		/* ringbuffer overflow */
#define KEYS_NO_DATA          0x0100        /* no data available   */

#define E_PIN 2			//	LCD
#define RW_PIN 1		//	LCD
#define RS_PIN 0		//	LCD

#define LCD_DATA4 4		//	LCD
#define LCD_DATA5 5		//	LCD
#define LCD_DATA6 6		//	LCD
#define LCD_DATA7 7		//	LCD

#define TIMER_CLK_STOP			0x00
#define TIMER_CLK_DIV1			0x01
#define TIMER_CLK_DIV8			0x02
#define TIMER_CLK_DIV64			0x03
#define TIMER_CLK_DIV256		0x04
#define TIMER_CLK_DIV1024		0x05
#define TIMER_CLK_T_FALL		0x06
#define TIMER_CLK_T_RISE		0x07

//Sas-Sas-Sas-Sas-Sas-Sas-Sas-Sas-Sas-Sas-Sas-Sas-Sas-Sas-Sas
/* KEY DEFINITIONS ( you can change them as you please ) */

//#define ESCAPE       0x1b 	/* DEFINE ESCAPE HERE  ( global) 	*/
//#define MOVE_LEFT    0x11   	/* DEFINE LEFT ARROW HERE     		*/
//#define MOVE_RIGHT   0x12   	/* DEFINE RIGHT ARROW HERE   		*/
//#define MOVE_UP      0x13 	/* DEFINE UP ARROW HERE     		*/
//#define MOVE_DOWN    0x14   	/* DEFINE DOWN ARROW HERE    		*/
//#define ENTER        0x0d   	/* DEFINE ENTER HERE   ( global)	*/
//#define BACKSPACE    0x08   	/* DEFINE BACKSPACE  				*/

/* KEY DEFINITIONS ( you can change them as you please ) */
 
//#define ESCAPE       'A'                     /* DEFINE ESCAPE HERE  ( global)            */
//#define MOVE_LEFT    'C'                     /* DEFINE LEFT ARROW HERE for kgets()    */
//#define MOVE_RIGHT   '*'                     /* DEFINE RIGHT ARROW HERE for kgets()   */
#define ENTER        '#'                     /* DEFINE ENTER HERE   ( global)            */
#define BACKSPACE    '*'                     /* DEFINE BACKSPACE for kgeti() and kgets() */

/* Lcd driver information (you only need to change it if you decide to use your own driver) */
/* name your lcd driver header file below */
// #include                       "lcd_io.h"         
/* name your lcd_putc function below      */
#define LCD_PUTC(x)            lcd_putc(x)        
/* name your lcd driver goto_xy function below */
#define LCD_GOTOXY(x,y)        lcd_gotoxy(x,y)    
/* name your lcd function to make the cursor visible and blinking below */
#define LCD_CURSOR_ON_BLINK()  lcd_command(LCD_DISP_ON_BLINK)
/* name your lcd function to turn off the cursor  below */
#define LCD_CURSOR_OFF()       lcd_command(LCD_DISP_ON)

//Sas-Sas-Sas-Sas-Sas-Sas-Sas-Sas-Sas-Sas-Sas-Sas-Sas-Sas-Sas

//typedef unsigned char byte;

//ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss
//
//	Определение прототипов функций
//
//ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss

int kgetc(void);
unsigned long kgeti(long *data, unsigned char digits, unsigned char lcd_x, unsigned char lcd_y);
unsigned  int scan_keyb(void);
unsigned char kgetmode(void);
unsigned char kget_attenuation(unsigned char *data, unsigned char digits, unsigned char lcd_x, unsigned char lcd_y);
//ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss
