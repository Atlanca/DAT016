	USE	Labdefs.s12
	
	ORG 	$1000
	
start:	LDAB 	#$FF
	STAB 	DCShadow
	
loop:	LDAB 	InPort
	JSR 	Outzero
	LDAA	DCShadow
	STAA 	OutPort
	BRA 	start
	
DCShadow	FCB	1

	USE	Subroutines.s12	
	
	