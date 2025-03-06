/*
  Lab 5 Circuit 3
  Using and manipulating the WDT
  By: Robert Guziec, Ben Zambrano
  Written: March 06, 2025
  I/O Pins
  A0: 
  A1:
  A2:
  A3:
  A4:
  A5:
  D0:
  D1: 
  D2: Setup LED
  D3: Loop LED
  D4: 
  D5: 
  D6: 
  D7: 
  D8:  
  D9:  
  D10: 
  D11: 
  D12:
  D13: 
*/

void setup() {
  
  cli();
  // Configure output
  DDRD = 0x0C;

  
  // Blink setup LED
  PORTD |= 0x04;
  _delay_ms(250);
  PORTD &= 0xFB;

  
  // Configure prescaler for WDT
  // Configure WDE for reset after 64 ms
  WDTCSR |= 0x18;
  WDTCSR = 0x0B;
  sei();


}

void loop() {
  unsigned int j = 0;
  for( unsigned int n = 1000; j < n; j ++ ){
    asm volatile ("wdr");
    PORTD ^= 0x08;
    // Call delay function and pass variable j
    msdelay(j);
   
  }

}

// External function used for increases the delay of the main loop
unsigned char msdelay(unsigned int x){
  
  // For loop that iterates until i is greater than the passed variable x
  for (unsigned int i = 0; i < x; i++){
    _delay_us(1000);
  }
}
