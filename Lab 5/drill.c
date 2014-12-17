#include <stdio.h>
#include "clock.h"
#include "ports.h"

#define DRILL_CONTROL_ADR	0x400
#define DRILL_CONTROL *((port8ptr)DRILL_CONTROL_ADR)

#define DRILL_STATUS_ADR	0x401
#define DRILL_STATUS	*((port8ptr)DRILL_STATUS_ADR)

char DCShadow = 0;

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

void Alarm(int count){
	while(count > 0){
	Outone(16);
	Hold(10);
	Outzero(16);
	Hold(5);
	count--;
	}
}

int Step(){
	if((DRILL_STATUS && 2)==1){
	Outone(1);
	Outzero(1);
	Hold(5);
	}else{
	Alarm(3);
	return 0;
	}
	return 1;
}

int Nstep(int step){
	while(step > 0){
	step--;

		if(!Step()){
		return 0;
		}
	
	}
	return 1;
}


void DrillHole(void){

}