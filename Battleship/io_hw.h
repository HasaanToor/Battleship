#include "stdbool.h"

void displaySea(void);

////////////////////////////////////////////////////

void ClockInit(void);
void Init(void);
void delay(void);
void shdelay(void);

////////////////////////////////////////////////////

void segA(bool on);
void segB(bool on);
void segC(bool on);
void segD(bool on);
void segE(bool on);
void segF(bool on);
void segG(bool on);
void LED(bool on);

////////////////////////////////////////////////////

bool sw0(void);
bool sw1(void);
bool sw2(void);
bool sw3(void);
bool swBlue(void);

////////////////////////////////////////////////////

void display0(void);
void display1(void);
void display2(void);
void display3(void);
void display4(void);
void display5(void);
void display6(void);
void display7(void);
void display8(void);
void display9(void);
void displayA(void);
void displayB(void);
void displayC(void);
void displayD(void);
void displayE(void);
void displayF(void);

////////////////////////////////////////////////////

void displayNothing(void);
void displayError(void);
void displayBye(void);
void displayHit(void);
void displayMiss(void);
void displaySunk(void);
void displayAllSunk(void);
void displayGrid(void);
void displayRow(void);
void displayCol(void);

////////////////////////////////////////////////////

int switchValue(void);
void displayHexValue(int value);
