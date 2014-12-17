typedef unsigned char  *port8ptr;
typedef unsigned short *port16ptr;
typedef unsigned long  *port32ptr;


#define ML4OUT_ADDRESS 0x400
#define ML4OUT *((port8ptr) ML4OUT_ADDRESS)

#define ML4IN_ADDRESS 0x600
#define ML4IN *((port8ptr) ML4IN_ADDRESS)

#ifdef SIMULATOR
   #define DRILLSTATUS_ADDRESS 0x401
#else
   #define DRILLSTATUS_ADDRESS
