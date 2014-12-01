
	USE	Labdefs.s12

Port1:	EQU	$400
Port2:	EQU	$401

	ORG	$1000
main:
; Nollställer variabler
	CLR	Var1
	CLR	Var2
; Initiera avbrottsvektor IRQ
	LDX	#IrqR
	STX	$3FF2
; Nollstäl I-bit, tillåt avbrott
	CLI

	
; Huvudprogram:
; Ökar Var1. 
; Skriver ut Var1 och Var2
main_loop:
	INC	Var1
	MOVB	Var1,Port1
	MOVB	Var2,Port2
	BRA	main_loop
	
; Avbrottsrutin
; Ökar Var2
IrqR:	INC 	Var2
	CLR	ML19_AckIrq_1
	RTI
	
; Variabler
Var1:	RMB	1
Var2:	RMB	1