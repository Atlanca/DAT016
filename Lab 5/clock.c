#include "ports.h"
#include "clock.h"

typedef void (*void_void_fp)(void);

extern void_void_fp inter_routine_asm;

static volatile time_type current_time = 0;

void kvittera_crg(){
	CRG_FLAG |= 0x80;
}

void init_clock(){
	// sätt avbrottsperiod
	IVEC = 0x10;
	
	// Aktivera CRG
	CRG_INIT = 0x80;
	
	// Initiera avbrottsvektorn
	*((void_void_fp *)IVEC_ADDR) = inter_routine_asm;
	
	// Allow for interrupts
	cli_routine();
}

void clock_inter(){
	current_time += INTERRUPT_TIME_RATIO;
}

time_type get_time(){
	return current_time;
}

void hold(time_type wait_time){
	time_type target = current_time + wait_time;
	
	while(get_time() < target);
}

