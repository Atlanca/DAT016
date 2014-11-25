	ORG $1000
	LDAA #1
	STAA $9C2
	LDAA #$D0
	STAA $9C3
	LDAA #0
	STAA $9C2
	LDAA #8
loop:
	; Placera lämpligt värde i ackumulator B innan instruktionen utförs
	STAB $9C3
	DECA
	BNE loop
end:
	BRA end