#include <stdio.h>
#include <stdlib.h>
#include "clock.h"
#include "ports.h"

char DCShadow = 0;
int pattern[]={0,1,1,1,1,1,1,1,2,1,2,2,2,2,4,4,3,8,2,0xff};


void Hold(int time){
	while(time != 0){
	int count = 100;
	while(count > 0){
	count--;
	}
	time--;
	}
}

void Outzero(int bit){
	unsigned char bittest = 1; 
		if(bit > 7)
	   return; // Not a valid bit
	bittest = bittest << bit;
	DCShadow = DCShadow & ~bittest;
	DRILL_CONTROL= DCShadow;
}

void Outone(int bit){
	unsigned char bittest = 1;
	if(bit > 7)
	   return; // Not a valid bit
	bittest = bittest << bit;
	DCShadow = DCShadow | bittest;
	DRILL_CONTROL = DCShadow;
	}

void MotorStart(void){
//Kolla om Drill control har startat
	int time = 10;
	if((DCShadow & (0x4))==0){
	Outone(2);
	Hold(time);
	}
}

void MotorStop(void){
	Outzero(2);
}

void DrillDown(void){
	Outone(3);
}

void DrillUp(void){
	Outzero(3);
	while(DCShadow & 2 == 0); // ensure that drill goes all the way up
}

void Alarm(int count){
	int time = 5;
	while(count > 0){
	Outone(4);
	Hold(2*time);
	Outzero(4);
	Hold(time);
	count--;

	}
}

int Step(){
	int time = 5;
	if((DRILL_STATUS & 0x2)){
	Outone(0);
	Hold(3);
	Outzero(0);
	Hold(time);

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

int DrillDownTest(){
int retry = 20;
	while(retry >= 0){
//If drill down return 1

	int time = 3;
	if((DRILL_STATUS & 0x4)){
	return 1;
	}
	Hold(time);
	retry--;

	}
//If still not down alarm
	Alarm(2);
	return 0;
}

int DrillHole(void){
	char status;
	DrillDown();
	status = DrillDownTest();
	DrillUp();
	return status;
}

int RefPos(void){
	while(1){
	int a = DRILL_STATUS;
	if((DRILL_STATUS & 1))
	return 1;
	
	if(Step()==0)
	return 0;
	

	}
}

void DoAuto(void){
int i = 0;
	if(RefPos() == 0){
	   MotorStop();
	   return;
	}
	MotorStart();
	
	while(pattern[i] != 0xff){
	
	   if(Nstep(pattern[i]) == 0){
	      MotorStop();
	      return;
	   }
	
	   if(DrillHole() == 0){
	      MotorStop();
	      return;
	   }
	
	   i++;
	
	}

	
	
}
	
	