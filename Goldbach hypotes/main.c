// c-fil, main.c

#include <stdio.h>
#include "is_primtal.h"

int main(int argc, char **argv){
	while(1){
	
	int p;
	scanf("%i",&p);
	
	if(p < 1){
	printf("V�lj ett tal st�rre �n 1\n");
	}else{
		if(is_prime(p)){
		printf("%i �r ett primtal",p);	
		}else{
		printf("%i �r inte ett primtal",p);
		}
	}

	}
return 0;
}