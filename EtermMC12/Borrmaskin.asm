	ORG $1000
Loop 	NOP ; Ge indata till register A
	STAA $400 ; Skriv till borrmaskinen
	LDAB $600 ; L�s statusregistret
	BRA Loop