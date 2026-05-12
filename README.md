# Battleships

A project consisting of a hardware-software hybrid implementation of the classic two-player strategy guessing game.

---

## What is Battleships?

Battleship is a strategy type guessing game for two players.
It is played on ruled grids (paper or board) on which each player's fleet of warships are marked.
The locations of the fleets are concealed from the other player.
Each players layout grid contains their own ships as well as recorded shots made by the opponent.
Each players targeting grid contains a record of their own shots against the opponent.
Players alternate turns calling "shots" at the other player's ships.
This shot is recorded as a miss or a hit, if you hit all parts of a ship, it is destroyed.
The objective of the game is to destroy all of the opposing players' ships.

---

## Implementation Overview

This project combines **software** and **hardware** to simulate Battleships:

- **Software** — acts as my layout grid and contains the locations of my ships using row and column coordinates
- **Hardware** — acts as my opponents targeting grid, in other words, shots made using the hardware are made against my own ships. Consists of a 7-segment display and red LED for output and a 4-dip physical switch allowing for 16 distinct combinations for input.

---

## How to Play

### Step 1 — Set the Grid Size

1. The hardware prompts the user to input a grid size, creates a X by X grid where X is the user input.
2. The input is validated:
   - Invalid if the value is 0.
   - Invalid if the location of any of the pre-placed ships in the software lies outside of the X by X grid.
3. If invalid, the hardware indicates the error and prompts again.
4. If valid, the hardware confirms the grid is set and proceeds to the next step.

### Step 2 — Take a Shot

1. The hardware prompts for a **row** value, then a **column** value.
2. The input is validated:
   - Invalid if the value is 0.
   - Invalid if the coordinate falls outside the X by X grid.
   - Invalid if the location has already been hit.
3. If invalid, the hardware indicates the error and prompts again.
4. If valid, the shot is processed.

### Step 3 — Process the Shot

1. The software checks whether the shot matches any ship part location.
2. If there was a match then the hardware lets the user know that they have **HIT** a ship part.
   - If all parts of a ship are hit, the hardware notifies the user that the ship is sunk.
   - If the last remaining ship is sunk, the hardware announces that all ships are sunk and ends the game.
3. If there were no matches then the hardware lets the user know that they have **MISSED**.
4. Return to Step 2.

Since this was a University project, it was intended to be played with another person who had their own similar implementation of this system, allowing both players to play against each other by taking turns.

---

## Output Signal Table

The following is all the outputs that the hardware displays to the user using the 7-segment display or the red LED.

| Signal | Description |
|--------|-------------|
| `G` | Prompts user to input a grid size / Confirms grid size input |
| `GS` | Informs user that the grid size is set |
| `r` | Prompts user to input a row value / Confirms row input |
| `c` | Prompts user to input a column value / Confirms column input |
| `H` | Informs user that they've hit a ship part |
| `nH` | Informs user that they've not hit/missed |
| `S` | Informs user that they've sunk a ship |
| `AS` | Informs user that they've sunk all ships |
| `bYE` | Informs user that the game is over |
| RED LED | Informs user that they've made an invalid input |
| `0`–`F` | Hex display indicating integer values 0–15 (see table below) |

### Hex Display Values

| Display | Value | Display | Value |
|---------|-------|---------|-------|
| `0` | 0 | `8` | 8 |
| `1` | 1 | `9` | 9 |
| `2` | 2 | `A` | 10 |
| `3` | 3 | `b` | 11 |
| `4` | 4 | `C` | 12 |
| `5` | 5 | `d` | 13 |
| `6` | 6 | `E` | 14 |
| `7` | 7 | `F` | 15 |

---

## Extra Features

The following features were added beyond the original requirements of the project:

- Combined 4-dip switch input instead of 4 individual buttons.
- 1 RED LED with 7-segment display instead of 4 RED LEDs.
- The ability to change the grid size to whatever the user chooses, as long as it is valid.

### Validity Checks

- **Grid size check** — ensures the size is not 0 or negative, and that all ship parts fall within the grid.
- **Row/column check** — ensures coordinate values are not 0 or negative, and fall within the grid.
- **Already-hit check** — ensure that any part of any ship that is already "hit" does not get hit again.

---
