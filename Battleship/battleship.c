#include "../include/battleship.h"
#include <stdbool.h>
#include <stdio.h>
//#include <string.h>
#ifdef HARDWARE
#include "../include/io_hw.h"
#else
#include "../include/io.h"
#endif

void setupShips(void);

static struct Vessel vessels[1];


int main()
{
	ClockInit();
	Init();
	
	setupShips();
	int numVessels = 1;
	int numLocations = 5;
	int ships = 1;
	
	bool gridValid = false;
	bool gridTooSmall = false;
	bool enterGrid = true;
	
	bool gameOver = false;
	bool alreadyHit = false;
	bool enterValue = true;
	
	int gridSize = 10;
	int grid = 0;
	int value = 0;
	int row = 0;
	int col = 0;
	
	////////////////////////////////////////////////////
	
	while (!gridValid)
	{
		while (enterGrid)
		{
			displayGrid();
			delay();
			
			while (swBlue())
			{
				grid = switchValue();
				displayHexValue(grid);
			}
			gridSize = grid;
			
			displayNothing();
			displayGrid();
			shdelay();
			displayHexValue(gridSize);
			shdelay();
			displayNothing();
			
			if (gridSize < 1) {
				displayError();
				enterGrid = true;
			}
			else
				enterGrid = false;
			
		}
		
		for (int a = 0; a < numVessels; a++) {
			for (int b = 0; b < numLocations; b++) {
				if (gridSize < vessels[a].locations[b].r || gridSize < vessels[a].locations[b].c) {
					gridTooSmall = true;
					goto earlyEnd;
				}
			}
		}
		
		displayGrid();
		shdelay();
		display5();
		shdelay();
		displayNothing();
		
		earlyEnd:
		
		if (gridTooSmall) {
			displayError();
			enterGrid = true;
			gridTooSmall = false;
		}
		else
			gridValid = true;
		
	}
	
	////////////////////////////////////////////////////
	
	while (!gameOver)
	{
		while (enterValue)
		{
			displayRow();
			delay();
			
			while (swBlue())
			{
				value = switchValue();
				displayHexValue(value);
			}
			row = value;
			
			displayCol();
			delay();
			
			while (swBlue())
			{
				value = switchValue();
				displayHexValue(value);
			}
			col = value;
			
			displayNothing();
			displayRow();
			shdelay();
			displayHexValue(row);
			shdelay();
			displayCol();
			shdelay();
			displayHexValue(col);
			shdelay();
			displayNothing();
			
			if (row > gridSize || row < 1 || col > gridSize || col < 1) {
				displayError();
				enterValue = true;
			}
			else
				enterValue = false;
		}
		
		for (int i = 0; i < numVessels; i++) {
			for (int j = 0; j < numLocations; j++) {
				if (row == vessels[i].locations[j].r && col == vessels[i].locations[j].c) {
					if (vessels[i].locations[j].h == true) {
						alreadyHit = true;
						goto endLoop;
					}
					else {
						displayHit();
						displayNothing();
						vessels[i].locations[j].h = true;
						vessels[i].length--;
						
						if (vessels[i].length == 0) {
							displaySunk();
							displayNothing();
							vessels[i].sunk = true;
							ships--;
						}
						
						goto endLoop;
					}
				}
			}
		}
		
		displayMiss();
		displayNothing();
		
		endLoop:
		
		if (ships == 0) {
			displayAllSunk();
			gameOver = true;
		}
		else if (alreadyHit) {
			displayError();
			enterValue = true;
			alreadyHit = false;
		}
		else
			enterValue = true;
		
	}
	
	////////////////////////////////////////////////////
	
	displayNothing();
	displayBye();
	
	return 0;
}




void setupShips(void)
{
	
	//strcpy(vessels[0].name, "Destroyer");
	vessels[0].sunk = false;
	vessels[0].length = 2;
	vessels[0].locations[0].r = 9;
	vessels[0].locations[0].c = 8;
	vessels[0].locations[0].h = false;
	vessels[0].locations[1].r = 9;
	vessels[0].locations[1].c = 9;
	vessels[0].locations[1].h = false;
	vessels[0].locations[2].r = 0;
	vessels[0].locations[2].c = 0;
	vessels[0].locations[2].h = true;
	vessels[0].locations[3].r = 0;
	vessels[0].locations[3].c = 0;
	vessels[0].locations[3].h = true;
	vessels[0].locations[4].r = 0;
	vessels[0].locations[4].c = 0;
	vessels[0].locations[4].h = true;
	
	////////////////////////////////////////////////////
	
	//strcpy(vessels[1].name, "Submarine");
	vessels[1].sunk = false;
	vessels[1].length = 3;
	vessels[1].locations[0].r = 7;
	vessels[1].locations[0].c = 1;
	vessels[1].locations[0].h = false;
	vessels[1].locations[1].r = 8;
	vessels[1].locations[1].c = 1;
	vessels[1].locations[1].h = false;
	vessels[1].locations[2].r = 9;
	vessels[1].locations[2].c = 1;
	vessels[1].locations[2].h = false;
	vessels[1].locations[3].r = 0;
	vessels[1].locations[3].c = 0;
	vessels[1].locations[3].h = true;
	vessels[1].locations[4].r = 0;
	vessels[1].locations[4].c = 0;
	vessels[1].locations[4].h = true;
	
	//strcpy(vessels[2].name, "Cruiser");
	vessels[2].sunk = false;
	vessels[2].length = 3;
	vessels[2].locations[0].r = 1;
	vessels[2].locations[0].c = 8;
	vessels[2].locations[0].h = false;
	vessels[2].locations[1].r = 1;
	vessels[2].locations[1].c = 9;
	vessels[2].locations[1].h = false;
	vessels[2].locations[2].r = 1;
	vessels[2].locations[2].c = 10;
	vessels[2].locations[2].h = false;
	vessels[2].locations[3].r = 0;
	vessels[2].locations[3].c = 0;
	vessels[2].locations[3].h = true;
	vessels[2].locations[4].r = 0;
	vessels[2].locations[4].c = 0;
	vessels[2].locations[4].h = true;
	
	////////////////////////////////////////////////////
	
	//strcpy(vessels[3].name, "Battleship");
	vessels[3].sunk = false;
	vessels[3].length = 4;
	vessels[3].locations[0].r = 7;
	vessels[3].locations[0].c = 5;
	vessels[3].locations[0].h = false;
	vessels[3].locations[1].r = 7;
	vessels[3].locations[1].c = 6;
	vessels[3].locations[1].h = false;
	vessels[3].locations[2].r = 7;
	vessels[3].locations[2].c = 7;
	vessels[3].locations[2].h = false;
	vessels[3].locations[3].r = 7;
	vessels[3].locations[3].c = 8;
	vessels[3].locations[3].h = false;
	vessels[3].locations[4].r = 0;
	vessels[3].locations[4].c = 0;
	vessels[3].locations[4].h = true;
	
	////////////////////////////////////////////////////
	
	//strcpy(vessels[4].name, "Carrier");
	vessels[4].sunk = false;
	vessels[4].length = 5;
	vessels[4].locations[0].r = 2;
	vessels[4].locations[0].c = 2;
	vessels[4].locations[0].h = false;
	vessels[4].locations[1].r = 3;
	vessels[4].locations[1].c = 2;
	vessels[4].locations[1].h = false;
	vessels[4].locations[2].r = 4;
	vessels[4].locations[2].c = 2;
	vessels[4].locations[2].h = false;
	vessels[4].locations[3].r = 5;
	vessels[4].locations[3].c = 2;
	vessels[4].locations[3].h = false;
	vessels[4].locations[4].r = 6;
	vessels[4].locations[4].c = 2;
	vessels[4].locations[4].h = false;
	
}
