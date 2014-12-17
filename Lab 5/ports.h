typedef unsigned char  *port8ptr;
typedef unsigned short *port16ptr;
typedef unsigned long  *port32ptr;

// Parrallel out
#define ML4OUT_ADDRESS 0x400
#define ML4OUT *((port8ptr) ML4OUT_ADDRESS)

// Dipswitch
#define ML4IN_ADDRESS 0x600
#define ML4IN *((port8ptr) ML4IN_ADDRESS)

// Keyboard
#define KEYBOARD_ML15_ADDRESS 0x9C0
#define KEYBOARD_ML15 *((port8ptr) KEYBOARD_ML15_ADDRESS)

// Display
#define DISPLAY_DATA_ML15_ADDRESS 0x9C4
#define DISPLAY_DATA_ML15 *((port8ptr) DISPLAY_DATA_ML15_ADDRESS)

#define DISPLAY_MODE_ML15_ADDRESS 0x9C3
#define DISPLAY_MODE_ML15 *((port8ptr) DISPLAY_MODE_ML15_ADDRESS)

// Klocka
// Basadress 0x34
#define  IVEC *((unsigned char *)0x3B) 
#define  CRG_INIT *((unsigned char *)0x38)
#define  CRG_FLAG *((unsigned char *)0x37)

#define  IVEC_ADDR 0x3ff0

#ifdef SIMULATOR
   #define INTERRUPT_TIME_RATIO 0
#else
   #define INTERRUPT_TIME_RATIO 0x010
#endif

// Drill
#ifdef SIMULATOR
   #define DRILLSTATUS_ADDRESS 0x401
#else
   #define DRILLSTATUS_ADDRESS 0x600
#endif
