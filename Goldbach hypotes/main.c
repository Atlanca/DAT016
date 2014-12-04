// c-fil, main.c

#include <stdio.h>
#include "is_primtal.h"

int main(int argc, char **argv){
	while(1){
	
	int p;
	scanf("%i",&p);
	
	if(p < 1){
	printf("Välj ett tal större än 1\n");
	}else{
		if(is_prime(p)){
		printf("%i är ett primtal",p);	
		}else{
		printf("%i är inte ett primtal",p);
		}
	}

	}
return 0;
}