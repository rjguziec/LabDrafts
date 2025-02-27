/*
  Lab 4, Circuit 2
  Didsplay Light exposure value from photoresistor measurement onto an LCD screen
  By: Robert Guziec, Jay Hill
  Written: February 27, 2025
  I/O Pins
  A0: PHOTORESISTOR
  A1:
  A2:
  A3:
  A4:
  A5:
  D0:
  D1:
  D2:
  D3:
  D4:
  D5:
  D6:
  D7:
  D8: R/S
  D9: E
  D10: DB4
  D11: DB5
  D12: DB6
  D13: DB7
*/

#include "hd44780.h"

// Gross Global variables
const unsigned char N = 90;
volatile static unsigned int LIGHTVAL[N] = {};

void setup() {
  cli();
  // Configure ADC
  ADCSRA = 0xEF;
  ADCSRB = 0x00;
  ADMUX = 0x40;
  sei();
  // Initialize LCD screen
  lcd_init();
}

void loop() {
  //CALCULATION(S)
  // Calculate exposure from given ADC average with ones precision percentage
  // NOTE; Used equation is for ADC high of 900 and ADC low of 5
  int light =  (10L * ave(LIGHTVAL, N)) / 90;

  // LCD SCREEN DISPLAY CODE
  // Clear screen
  lcd_clrscr();
  //Write string "Exposure:" on LCD
  lcd_puts("Exposure:");
  const char charBufferValue = 4;
  char charBufferT[charBufferValue];
  //Convert exposure result to a string, base 10
  itoa(light, charBufferT, 10);
  //Go to second line of LCD using hex
  lcd_goto(0x40);
  //Display ADC result with units
  lcd_puts(charBufferT);
  lcd_putc(37);
  _delay_ms(50);
}

// Function that will calculate and return the average of sampled temperatures from loop
int ave(unsigned int *dataLight, unsigned char k) {
  // Initialize sum variable to zero
  unsigned long sum = 0;

  // For loop that iterates to calculate the average of collected data
  // from our array
  for (unsigned char j = 0; j < k; j++) {
    sum += dataLight[j];
  }

  sum /= k;
  return sum;
}

// Declare our interupt
ISR(ADC_vect) {
  // Circular Buffer for ADC values to be stored into temperature array
  static unsigned char x = 0;
  LIGHTVAL[x] = ADC;
  x++;
  if (x == N) {
    x = 0;
  }
}






