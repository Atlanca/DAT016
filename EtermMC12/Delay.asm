; USES REG. X & Y
DELAY:		PSHX
		PSHY
		LDX	#DelayConst
NEXT:		LEAX	-1,X
		LDY	#100
NEXT2:
		LEAY	-1,Y
		CPY	#0
		BNE	NEXT2
				
		CPX	#0
		BNE	NEXT
		PULY
		PULX
		RTS
		