Port1:	EQU	$400
Port2:	EQU	$401

	ORG	$1000
main:
; Nollst�ller variabler
	CLR	Var1
	CLR	Var2
; Initiera avbrottsvektor IRQ
	LDX	#IrqR
	STX	$3FF2
; Nollst�l I-bit, till�t avbrott
	CLI

	
; Huvudprogram:
; �kar Var1. 
; Skriver ut Var1 och Var2
main_loop:
	INC	Var1
	MOVB	Var1,Port1
	MOVB	Var2,Port2
	BRA	main_loop
	
; Avbrottsrutin
; �kar Var2
IrqR:	INC 	Var2
	RTI
	
; Variabler
Var1:	RMB	1
Var2:	RMB	1
	