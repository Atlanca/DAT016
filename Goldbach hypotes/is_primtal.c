
//c-fil, is_primtal.c

#include <stdio.h>
#include <math.h>

int is_prime(int p){

if(p<2){
return 0;
}

int tmp = (int)(sqrt(p)), count;

for(count = 2; count <= tmp; count++){
	if(p%count == 0){
	return 0;
	}
	
}	
return 1;
}