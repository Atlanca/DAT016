// U113

int a;
static int b;

// U114
int j,k;
unsigned int uj,uk;
void u114()
{
	if(k < 100)
		j=1;
	else
		j=2;
		
	// unsigned variation
	if(uk < 100)
		uj=1;
	else
		uj=2;
}

// U115
long int la;
short int sa, sb;

void u115(){
	sa = la;
	sa = (short int) la;
}


// U116
unsigned int ia;
unsigned short int usb,usc;
void u116(){
	ia = (usb<<2) - usc;
}

// U117
void u117(){
	int a;
	short int b;
	char c;
	
	a=1;
	b=2;
	c=3;
}


// U118
void do_nothing();
void u118(){
	do_nothing();
}

// U119
int do_something();
void u119(){
	int result;
	result = do_something();
}


// U120
int max(int n1, int n2);
void u120(){
	int result,low,high;
	result = max(low, high);
}