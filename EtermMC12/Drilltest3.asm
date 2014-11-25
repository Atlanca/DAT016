	ORG	$1000
	USE	Labdefs.s12


start:
	JSR	Vrid1Steg
	BRA	start
	
	USE	Delay2.asm
	
Vrid1Steg:
	ORAA 	#1
	STAA	DrillControl
	JSR	DELAY
	ANDA	#%11111110
	STAA	DrillControl
	JSR	DELAY
	RTS