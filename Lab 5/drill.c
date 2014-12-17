#include <stdio.h>
#include <stdlib.h>
#include "clock.h"
#include "ports.h"

char DCShadow = 0;
int pattern[]={0,1,1,1,1,1,1,1,2,1,2,2,2,2,4,4,3,8,2,0xff};


void hold(time_type time){
	while(time != 0){
	unsigned long count = 1000;
	while(count > 0){
	count--;
	}
	time--;
	}
}

void Outzero(int bit){
	if(bit > 7)
	   return; // Not a valid bit
	   
	unsigned char bittest = 1; 
	bittest = bittest << bit;
	DCShadow = DCShadow & ~bittest;
	DRILL_STATUS = DCShadow;
}

void Outone(int bit){
	if(bit > 7)
	   return; // Not a valid bit
	   
	unsigned char bittest = 1;
	bittest = bittest << bit;
	DCShadow = DCShadow | bittest;
	DRILL_STATUS = DCShadow;
	}

void MotorStart(void){
//Kolla om Drill control har startat
	time_type time = 10;
	if((DCShadow && (4))==0){
	Outone(4);
	hold(time);
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
	time_type time = 5;
	while(count > 0){
	   Outone(4);
	   hold(2*time);
	   Outzero(4);
	   hold(time);
	   count--;
	}
}

int Step(){
	time_type time = 5;
	if((DRILL_STATUS && 2)==1){
	   Outone(1);
	   Outzero(1);
	   hold(time);
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
	   time_type time = 3;
	   if((DRILL_STATUS && 4)==1){
	      return 1;
	   }
	   hold(time);
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
	   if(DRILL_STATUS && 1)
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
	
	