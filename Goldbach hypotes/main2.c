#include <stdio.h>
#include "is_primtal.h"

int main(int argc, char **argv){
int t;
while(1){
scanf("%d", &t);
	
	if(t%2){
	printf("Talet är udda!");
	
	}else{
	
	int count = 2;

	for(;count <= t/2;count++){
	if(is_prime(count)&&is_prime(t-count)){
	printf("%i + %i\n", count, t-count);
	}
	
	}
}

}

}