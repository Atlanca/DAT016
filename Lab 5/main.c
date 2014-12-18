#include <stdio.h>
#include "drill.h"
#include "keyboardML15.h"
#include "clock.h"

//#define AUTO_ONLY

void main(){
init_clock();
#ifdef AUTO_ONLY
	DoAuto()
#else
	while(1){
		unsigned char key = get_key();
		
		switch(key){
		    case 0:
			MotorStart();
		       break;
		    case 1:
			MotorStop();
		       break;
		    case 2:
			DrillDown();
		       break;
		    case 3:
			DrillUp();
		       break;
		    case 4:
			Nstep(3);
		       break;
		    case 5:
			DrillHole();
		       break;
		    case 6:
			RefPos();
		       break;
		    case 7:
			DoAuto();
		       break;
		}
	}
#endif

}
