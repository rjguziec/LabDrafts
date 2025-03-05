/*
  Lab 5, Circuit 2
  Description Using interrupts and building off of Circuit 1, create a multifunctional calculator
    and display an ERROR if divide zero
  By: Robert Guziec, Ben Zambrano
  Written: Marh 5, 2025
  Edited: March 5, 2025
  I/O Pins
  A0: 
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
  D8:  BLUE LED (loop)
  D9:  GREEN LED (setup)
  D10: 
  D11: 
  D12: 
  D13: 
*/

void setup()
{
  // Setup output
  DDRB = 0x03;

  // Flash setup LED
  PORTB ^= 0x02;
  _delay_ms(250);
  PORTB ^= 0x02;

  WDTCSR |= 0x18;
  
}

void loop()
{
  unsigned char = 0;
  for (j = 0, j < n, j + 5){
    
  }
}



