#include "keyboardML15.h"

void main(){
	while(1){
	
		unsigned char a = get_key();
		display_dec((unsigned int)a);
		
	}
}
