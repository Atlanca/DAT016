
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
IrqR:	
	LDAA	ML19_Stat
	BITA	#1
	BEQ	IrqR_Event_2
IrqR_Event_1:
	INC 	Var2
	CLR	ML19_AckIrq_1
	BRA	IrqR_end
IrqR_Event_2:
	CLR	Var2
	CLR	ML19_AckIrq_2
IrqR_end:
	RTI
	
; Variabler
Var1:	RMB	1
Var2:	RMB	1