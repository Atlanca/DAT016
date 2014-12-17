	IMPORT	_clock_inter
	EXPORT	_inter_routine_asm
_inter_routine_asm:
	JSR	_clock_inter
	RTI
	
	EXPORT	_cli_routine
_cli_routine:
	CLI
	RTS