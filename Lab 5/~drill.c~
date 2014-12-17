#include <stdio.h>
#include "clock.h"

#define DRILL_CONTROL_ADR	0x400
#define DRILL_CONTROL *((int*)DRILL_CONTROL_ADR)

#define DRILL_STATUS_ADR	0x401
#define DRILL_STATUS	*((*int)DRILL_STATUS_ADR)

char DCShadow;

void Outzero(int bit){
	unsigned char bittest = 1; 
	bittest = bittest << bit;
	DCShadow = DCShadow & ~bittest;
	DRILL_STATUS = DCShadow;
}

void Outone(int bit){
	unsigned char bittest = 1;
	bittest = bittest << bit;
	DCShadow = DCShadow | bittest;
	DRILL_STATUS = DCShadow;
	}

void MotorStart(void){
//Kolla om Drill control har startat
	if((DCShadow && (4))==0){
	Outone(4);
	Hold(10);
	}
}

void MotorStop(void){
	Outzero(4);
}

void DrillDown(void){
	Outone(8);
}

void DrillUp(void){
	Outzero(8);
}

int Nstep(int step){
int i;
	if((DRILL_STATUS && 2) == 1){
		while(step > 0){
		Outone(1);
		Outzero(1);
		Hold(10);
		step--;
		}
	}else{
		Alarm(3);
}

void Alarm(int count){
	for(; count > 0; count--){
	Outone(16);
	Hold(10);
	Outzero(16);
	Hold(5);
	}
}

void DrillHole(void){

}