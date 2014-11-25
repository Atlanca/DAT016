Outzero:
	LDAA	#1
	LDAB	InPort
	BITB	#7
	BEQ	ifBZero
	BITB	#%11111000
	BNE	return
loop2:
	ASLA
	DECB
	BNE	loop2
ifBZero:	ANDA	DCShadow
	COMA
	STAA	DrillControl
	STAA	DCShadow

return:	RTS	


Outone:
	LDAA	#1
	LDAB	InPort
	BITB	#%11111000
	BNE	returnOutone
	BITB	#7
	BEQ	ifBZero2
loop3:
	ASLA
	DECB
	BNE	loop3
ifBZero2:
	ORAA	DCShadow
	STAA	DrillControl
	STAA	DCShadow
returnOutone: 
	RTS 