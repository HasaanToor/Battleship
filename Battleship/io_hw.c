#include "../include/io_hw.h"
#include "stm32f10x.h"


void displaySea(void)
{
		//Cant display the sea on our hardware
}

////////////////////////////////////////////////////
////////////////////////////////////////////////////
////////////////////////////////////////////////////

void ClockInit()
{
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_IOPBEN | RCC_APB2ENR_IOPCEN;
}

void Init()
{
	
	GPIOA->CRL |= (uint32_t)0x33040044;
	GPIOA->CRL &= ~(uint32_t)0xCC0B00BB;
	
	
	GPIOA->CRH |= (uint32_t)0x00000333;
	GPIOA->CRH &= ~(uint32_t)0x00000CCC;
	
	GPIOB->CRL |= (uint32_t)0x03300004;
	GPIOB->CRL &= ~(uint32_t)0x0CC0000B;
	
	GPIOB->CRH |= (uint32_t)0x00000300;
	GPIOB->CRH &= ~(uint32_t)0x00000C00;
	
	GPIOC->CRH |= (uint32_t)0x00400000;
	GPIOC->CRH &= ~(uint32_t)0x00B00000;
}

void delay()
{
	unsigned volatile int c, d;
	
	for (c = 1; c <= 3000; c++)
		for (d = 1; d <= 3000; d++)
			{}
}

void shdelay()
{
	unsigned volatile int c, d;
	
	for (c = 1; c <= 3000; c++)
		for (d = 1; d <= 1500; d++)
			{}
}

////////////////////////////////////////////////////
////////////////////////////////////////////////////
////////////////////////////////////////////////////

void segA(bool on)
{
	if (on)
		GPIOA->ODR |= (uint32_t)0x00000040;
	else
		GPIOA->ODR &= ~(uint32_t)0x00000040;
}

void segB(bool on)
{
	if (on)
		GPIOA->ODR |= (uint32_t)0x00000080;
	else
		GPIOA->ODR &= ~(uint32_t)0x00000080;
}

void segC(bool on)
{
	if (on)
		GPIOA->ODR |= (uint32_t)0x00000200;
	else
		GPIOA->ODR &= ~(uint32_t)0x00000200;
}

void segD(bool on)
{
	if (on)
		GPIOA->ODR |= (uint32_t)0x00000100;
	else
		GPIOA->ODR &= ~(uint32_t)0x00000100;
}

void segE(bool on)
{
	if (on)
		GPIOB->ODR |= (uint32_t)0x00000400;
	else
		GPIOB->ODR &= ~(uint32_t)0x00000400;
}

void segF(bool on)
{
	if (on)
		GPIOB->ODR |= (uint32_t)0x00000020;
	else
		GPIOB->ODR &= ~(uint32_t)0x00000020;
}

void segG(bool on)
{
	if (on)
		GPIOA->ODR |= (uint32_t)0x00000400;
	else
		GPIOA->ODR &= ~(uint32_t)0x00000400;
}

void LED(bool on)
{
	if (on)
		GPIOB->ODR |= (uint32_t)0x00000040;
	else
		GPIOB->ODR &= ~(uint32_t)0x00000040;
}

////////////////////////////////////////////////////

bool sw0()
{
	volatile unsigned int checkIDR = (GPIOA->IDR & (uint32_t)0x00000001);
	if (checkIDR == (uint32_t)0x00000001)
		return true;
	else
		return false;
}

bool sw1()
{
	volatile unsigned int checkIDR = (GPIOA->IDR & (uint32_t)0x00000002);
	if (checkIDR == (uint32_t)0x00000002)
		return true;
	else
		return false;
}

bool sw2()
{
	volatile unsigned int checkIDR = (GPIOA->IDR & (uint32_t)0x00000010);
	if (checkIDR == (uint32_t)0x00000010)
		return true;
	else
		return false;
}

bool sw3()
{
	volatile unsigned int checkIDR = (GPIOB->IDR & (uint32_t)0x00000001);
	if (checkIDR == (uint32_t)0x00000001)
		return true;
	else
		return false;
}

bool swBlue()
{
	volatile unsigned int checkIDR = (GPIOC->IDR & (uint32_t)0x00002000);
	if (checkIDR == (uint32_t)0x00002000)
		return true;
	else
		return false;
}

////////////////////////////////////////////////////
////////////////////////////////////////////////////
////////////////////////////////////////////////////

void display0()
{
	segA(true);
	segB(true);
	segC(true);
	segD(true);
	segE(true);
	segF(true);
	segG(false);
}

void display1()
{
	segA(false);
	segB(true);
	segC(true);
	segD(false);
	segE(false);
	segF(false);
	segG(false);
}

void display2()
{
	segA(true);
	segB(true);
	segC(false);
	segD(true);
	segE(true);
	segF(false);
	segG(true);
}

void display3()
{
	segA(true);
	segB(true);
	segC(true);
	segD(true);
	segE(false);
	segF(false);
	segG(true);
}

void display4()
{
	segA(false);
	segB(true);
	segC(true);
	segD(false);
	segE(false);
	segF(true);
	segG(true);
}

void display5()
{
	segA(true);
	segB(false);
	segC(true);
	segD(true);
	segE(false);
	segF(true);
	segG(true);
}

void display6()
{
	segA(true);
	segB(false);
	segC(true);
	segD(true);
	segE(true);
	segF(true);
	segG(true);
}

void display7()
{
	segA(true);
	segB(true);
	segC(true);
	segD(false);
	segE(false);
	segF(false);
	segG(false);
}

void display8()
{
	segA(true);
	segB(true);
	segC(true);
	segD(true);
	segE(true);
	segF(true);
	segG(true);
}

void display9()
{
	segA(true);
	segB(true);
	segC(true);
	segD(true);
	segE(false);
	segF(true);
	segG(true);
}

void displayA()
{
	segA(true);
	segB(true);
	segC(true);
	segD(false);
	segE(true);
	segF(true);
	segG(true);
}

void displayB()
{
	segA(false);
	segB(false);
	segC(true);
	segD(true);
	segE(true);
	segF(true);
	segG(true);
}

void displayC()
{
	segA(true);
	segB(false);
	segC(false);
	segD(true);
	segE(true);
	segF(true);
	segG(false);
}

void displayD()
{
	segA(false);
	segB(true);
	segC(true);
	segD(true);
	segE(true);
	segF(false);
	segG(true);
}

void displayE()
{
	segA(true);
	segB(false);
	segC(false);
	segD(true);
	segE(true);
	segF(true);
	segG(true);
}

void displayF()
{
	segA(true);
	segB(false);
	segC(false);
	segD(false);
	segE(true);
	segF(true);
	segG(true);
}

////////////////////////////////////////////////////

void displayNothing()
{
	segA(false);
	segB(false);
	segC(false);
	segD(false);
	segE(false);
	segF(false);
	segG(false);
	shdelay();
}

void displayError()
{
	LED(true);
	displayNothing();
	delay();
	LED(false);
}

void displayBye()
{
	displayB();
	shdelay();
	segA(false);
	segB(true);
	segC(true);
	segD(true);
	segE(false);
	segF(true);
	segG(true);
	shdelay();
	displayE();
	shdelay();
	displayNothing();
}

void displayHit()
{
	segA(false);
	segB(true);
	segC(true);
	segD(false);
	segE(true);
	segF(true);
	segG(true);
	delay();
}

void displayMiss()
{
	segA(true);
	segB(true);
	segC(true);
	segD(false);
	segE(true);
	segF(true);
	segG(false);
	shdelay();
	displayHit();
}

void displaySunk()
{
	display5();
	delay();
}

void displayAllSunk()
{
	displayA();
	shdelay();
	displaySunk();
}

void displayGrid()
{
	segA(true);
	segB(false);
	segC(true);
	segD(true);
	segE(true);
	segF(true);
	segG(false);
}

void displayRow()
{
	segA(false);
	segB(false);
	segC(false);
	segD(false);
	segE(true);
	segF(false);
	segG(true);
}

void displayCol()
{
	segA(false);
	segB(false);
	segC(false);
	segD(true);
	segE(true);
	segF(false);
	segG(true);
}

////////////////////////////////////////////////////
////////////////////////////////////////////////////
////////////////////////////////////////////////////

int switchValue()
{
	int value = 0;
	
	if (sw0())
		value += 1;
	
	if (sw1())
		value += 2;
	
	if (sw2())
		value += 4;
	
	if (sw3())
		value += 8;
	
	return value;
}

////////////////////////////////////////////////////

void displayHexValue(int value)
{
	if (value == 0)
		display0();
	else if (value == 1)
		display1();
	else if (value == 2)
		display2();
	else if (value == 3)
		display3();
	else if (value == 4)
		display4();
	else if (value == 5)
		display5();
	else if (value == 6)
		display6();
	else if (value == 7)
		display7();
	else if (value == 8)
		display8();
	else if (value == 9)
		display9();
	else if (value == 10)
		displayA();
	else if (value == 11)
		displayB();
	else if (value == 12)
		displayC();
	else if (value == 13)
		displayD();
	else if (value == 14)
		displayE();
	else if (value == 15)
		displayF();
	else
		displayNothing();
}

////////////////////////////////////////////////////
////////////////////////////////////////////////////
////////////////////////////////////////////////////
