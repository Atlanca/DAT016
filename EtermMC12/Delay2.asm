		ORG	$1000
;#define	SIMULATOR
		USE	Labdefs.s12

Start:		nop
DELAY:		LDX	#DelayConst
NEXT:		LEAX	-1,X
		LDY	#100
NEXT2:
		LEAY	-1,Y
		CPY	#0
		BNE	NEXT2		
		
		CPX	#0
		BNE	NEXT		
		
	;	LDAA	$400
		COMA
		ANDA	#%00000010
		STAA	$400
		NOP
		BRA	DELAY