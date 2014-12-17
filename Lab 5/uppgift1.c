
#include "ports.h"

void main(){
	while(1){
		char b = ML4IN;
		ML4OUT = b;
	}
}
