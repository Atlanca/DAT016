#include "ports.h"

unsigned char get_key(){

	unsigned char key;
	while(1){
		key = KEYBOARD_ML15;
		
		if((key & 0x80) == 0){ // key pressed
			while(KEYBOARD_ML15 & 0x80); // wait until release
			return key;
		}
	}
}