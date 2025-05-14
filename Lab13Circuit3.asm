;
; This code will cycle through a 7 segment display numerals
; 
; 
; WRITTEN: 05/14/2025 
; EDITED:  05/14/2025
; AUTHOR : Kevyn and Robert
;

; any non-repeating tasks should occur outside of the loop
SBI DDRD, 7	; configure D1 as an output pin for A
SBI DDRD, 6	; configure D2 as an output pin for B
SBI DDRD, 5	; configure D3 as an output pin for C
SBI DDRD, 4 ; configure D4 as an output pin for D
SBI DDRD, 3 ; configure D5 as an output pin for E
SBI DDRD, 2 ; configure D6 as an output pin for F
SBI DDRD, 1 ; configure D7 as an output pin for G
 
; loop subroutine starts here
loop:
	; input data from the PIND register
	IN r16, PIND
	; mask data from the PIND register
	ANDI r16, 0x01  ; selective clear
	ORI r16, 0xFC  ; selective set
	OUT PORTD, r16 ; output to 7 segment
	call DELAY

	; input data from the PIND register
	IN r16, PIND
	; mask data from the PIND register
	ANDI r16, 0x01
	ORI r16, 0x60
	OUT PORTD, r16
	call DELAY

	; input data from the PIND register
	IN r16, PIND
	; mask data from the PIND register
	ANDI r16, 0x01
	ORI r16, 0xDA
	OUT PORTD, r16
	call DELAY

	; input data from the PIND register
	IN r16, PIND
	; mask data from the PIND register
	ANDI r16, 0x01
	ORI r16, 0xF2
	OUT PORTD, r16
	call DELAY

	; input data from the PIND register
	IN r16, PIND
	; mask data from the PIND register
	ANDI r16, 0x01
	ORI r16, 0x66
	OUT PORTD, r16
	call DELAY

	; input data from the PIND register
	IN r16, PIND
	; mask data from the PIND register
	ANDI r16, 0x01
	ORI r16, 0xB6
	OUT PORTD, r16
	call DELAY

	; input data from the PIND register
	IN r16, PIND
	; mask data from the PIND register
	ANDI r16, 0x01
	ORI r16, 0xBE
	OUT PORTD, r16
	call DELAY

	; input data from the PIND register
	IN r16, PIND
	; mask data from the PIND register
	ANDI r16, 0x01
	ORI r16, 0xE4
	OUT PORTD, r16
	call DELAY

	; input data from the PIND register
	IN r16, PIND
	; mask data from the PIND register
	ANDI r16, 0x01
	ORI r16, 0XFE
	OUT PORTD, r16
	call DELAY


	; input data from the PIND register
	IN r16, PIND
	; mask data from the PIND register
	ANDI r16, 0x01
	ORI r16, 0XF6
	OUT PORTD, r16
	call DELAY
	JMP loop

DELAY:
    ldi  r18, 5
    ldi  r19, 15
    ldi  r20, 242
L1: dec  r20
    brne L1
    dec  r19
    brne L1
    dec  r18
    brne L1
	JMP loop