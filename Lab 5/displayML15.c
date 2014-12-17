#include "ports.h"

// param vec - 6 byte array
void display_digits(char *vec){
	char i;
	
	// start display
	
	DISPLAY_MODE_ML15 = 1;
	DISPLAY_DATA_ML15 = 0x90; 
	DISPLAY_MODE_ML15 = 0;
	
	
	//*((port8ptr) 0x9C3) = 1;
	
	// print digits
	
	for(i=0; i<6; i++){
		DISPLAY_DATA_ML15 = vec[i];
	}
	// end procedure:
	DISPLAY_DATA_ML15 = 0; 
	DISPLAY_DATA_ML15 = 0;
}


void display_dec(unsigned int number){
	char string[6];
	
	int i;
	for(i=5;i>=0;i--){
		string[i] = number % 10;
		number /= 10;
	}
	display_digits(string);
	
}
