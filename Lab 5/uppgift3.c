#include "clock.h"
#include "displayML15.h"

void main(){
	init_clock();
	while(1){
		time_type time = get_time();//123442; //
		unsigned int time2 = (unsigned int) time;
		display_dec(time2);
	}
}
