===============================================
================= Battleships =================
===============================================

What is Battleships and how to play it
-----------------------------------------------

Battleship is a strategy type guessing game for two players.
It is played on ruled grids (paper or board) on which each player's fleet of warships are marked.
The locations of the fleets are concealed from the other player.
Each players layout grid contains their own ships as well as recorded shots made by the opponent.
Each players targeting grid contains a record of their own shots against the opponent.
Players alternate turns calling "shots" at the other player's ships.
This shot is recorded as a miss or a hit, if you hit all parts of a ship, it is destroyed.
The objective of the game is to destroy all of the opposing players' ships.

===============================================

In my implementation I used a combination of software and hardware to simulate battleships

The software acts as my layout grid and contains the locations of my ships using row and column coordinates

The hardware acts as my opponents targeting grid, in other words, shots made using the hardware are made against my own ships

-----------------------------------------------

The general formula goes as follows:

1.1) The hardware prompts the user for a grid size
1.2) The hardware will confirm the users input and check if it is invalid or valid
1.2.1) The grid size is considered invalid if the location of any of the ships in the software lies outside of the X by X grid
1.2.2) For example, if I have part of a ship at row 6 column 10, and I set grid size to 9, this is considered invalid as I have a ship part outside of the 9 by 9 grid
1.3) If the grid size is invalid then the hardware will indicate this and continue to ask until valid
1.4) If the grid size is valid then the hardware lets the user know that the grid is set and moves to step 2.1)

2.1) The hardware prompts the user for a row value
2.2) The hardware prompts the user for a column value
2.3) The hardware will confirm the users input and check if it is invalid or valid
2.3.1) The row or column value is considered invalid if the value is 0, if the value is outside the X by X grid, or if there is a ship part at the given row and column grid location that has already been hit
2.3.2) For example, if the grid size is set to 10, and I try to shoot at row 6 column 11, this is considered invalid as column 11 is outside of the 10 by 10 grid
2.4) If the shot is invalid then the hardware will indicate this and continue to ask until valid
2.5) If the shot is valid then move to step 3.1)

3.1) The software checks if the inputted shot matches with any location of any ship part
3.2) If there was a match then the hardware lets the user know that they have hit a ship part
3.2.1) If they shoot every part of a particular ship, the hardware lets the user know that they sunk a ship
3.3) Return to step 2.1)
3.4) If there were no matches then the hardware lets the user know that they have missed
3.5) Return to step 2.1)
3.6) If the ship sunk from step 3.2.1) was the last remaining ship then the hardware lets the user know that all ships are sunk and ends the program.

===============================================

Output Signal Table

+-----+--------------------------------------------------------------------------+
|     |										 |
|  G  | Prompts user to input a grid size / Confirms users grid size input	 |
|     |										 |
+-----+--------------------------------------------------------------------------+
|     |										 |
|  GS | Informs user that grid size is set					 |
|     |										 |
+-----+--------------------------------------------------------------------------+
|     |										 |
|  r  | Prompts user to input a row value / Confirms users row input		 |
|     |										 |
+-----+--------------------------------------------------------------------------+
|     |										 |
|  c  | Prompts user to input a column value / Confirms users column input	 |
|     |										 |
+-----+--------------------------------------------------------------------------+
|     |										 |
|  H  | Informs user that they've hit a ship part				 |
|     |										 |
+-----+--------------------------------------------------------------------------+
|     |										 |
|  nH | Informs user that they've not hit a ship part (miss)			 |
|     |										 |
+-----+--------------------------------------------------------------------------+
|     |										 |
|  S  | Informs user that they've sunk a ship					 |
|     |										 |
+-----+--------------------------------------------------------------------------+
|     |										 |
|  AS | Informs user that they've sunk all ships				 |
|     |										 |
+-----+--------------------------------------------------------------------------+
|     |										 |
| bYE | Informs user that the game is over					 |
|     |										 |
+-----+--------------------------------------------------------------------------+
| RED |										 |
| LED | Informs user that they've made an invalid input				 |
|     |										 |
+-----+--------------------------------------------------------------------------+
|     |										 |
| 0-F | Indicates integer values 0 through 15 outlined in table below		 |
|     |                                                                          |
|     |	hex display | int value							 |
|     | 0	    | 0								 |
|     | 1	    | 1								 |
|     | 2	    | 2								 |
|     | 3	    | 3								 |
|     | 4	    | 4								 |
|     | 5	    | 5								 |
|     | 6	    | 6								 |
|     | 7	    | 7								 |
|     | 8	    | 8								 |
|     | 9	    | 9								 |
|     | A	    | 10							 |
|     | b	    | 11							 |
|     | C	    | 12							 |
|     | d	    | 13							 |
|     | E	    | 14							 |
|     | F	    | 15							 |
+-----+--------------------------------------------------------------------------+

===============================================

Problems encountered and extra features
-----------------------------------------------
A major problem I encountered during my project was when implementing my dynamic grid size functionality.
The problem was that I was using "sizeof(vessels)" in order to find how many vessels were in play.
However this did not yield a value of 5 (to indicate 5 ships) like I had hoped, and instead was giving a very random large number.
This led to my entire dynamic grid size functionality to not work as it was comparing numbers that didnt exist/were randomly set from memory.
I fixed this by simply creating a variable called "numVessels" and assigning it a value of 5.

I implemented several extra features compared to the original document.
These being the use of the combined 4 dip switch instead of 4 individual buttons,
the use of 1 RED LED along with the 7 segment display instead of 4 RED LEDs,
and finally the ability to change the grid size to whatever the user chooses, as long as it is valid.

I implemented several validity checks, these include:
Valid grid size check, to ensure the grid size is not 0 or negative, as well as to ensure the grid contains all current ships within it
Valid row/column value check, to ensure the row or column coordinate is not 0 or negative, as well as to ensure the coordinate is within the grid
Already hit check, to ensure that any part of any ship that is already "hit" does not get hit again

===============================================

Configuration options
-----------------------------------------------
Adjustable grid size, with validity checks to ensure correct functionality

===============================================