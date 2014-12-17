#include <stdio.h>
#include "drill.h"
#include "keyboardML15.h"

void main(){

	while(1){
		unsigned char key = get_key();
		
		switch(){
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
			Outzero();
		       break;
		}
	}
}
