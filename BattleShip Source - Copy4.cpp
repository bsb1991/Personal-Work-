#include <cstdlib>
#include <iostream>
#include <ctime>
#include <string>
#include <iomanip>
#include <ctype.h>
#include "stdafx.h"

using namespace std;

const int ROWS = 10;
const int COLS = 10;
const int NUM_OF_SHIPS = 5;
int eShips = 17;
int uShips = 17;
char rowLet;
bool victory = false;

void enemyDisplay(string board[][COLS]);
void placeShips(string board[][COLS]);
void printBoard(string board[ROWS][COLS]);

int main()
{

	srand(static_cast<unsigned int>(time(NULL)));
	string enemy1[ROWS][COLS], enemy2[ROWS][COLS], userBoard[ROWS][COLS];

	int iGuess, jGuess, iCGuess, jCGuess;
	char letGuess;
	int length = sizeof(letGuess)/sizeof(char);
	char upper;

    //kevin did this it was originally the full-sized title but the command prompt was too small so now its just this
	cout << "*****************************************" << endl;
	cout << "*****************************************" << endl;
	cout << "** BBBBBBBBBBBBB        SSSSSSSSSSSS   **" << endl;
	cout << "** BBBBBBBBBBBBBB       SSSSSSSSSSSS   **" << endl;
	cout << "** BBBBB    BBBBBB    SSS              **" << endl;
	cout << "** BBBBB     BBBBB    SSS              **" << endl;
	cout << "** BBBBBBBBBBBBBBB    SSS              **" << endl;
	cout << "** BBBBBBBBBBBBBB       SSSSSSSSSSSS   **" << endl;
	cout << "** BBBBBBBBBBBBBB       SSSSSSSSSSSS   **" << endl;
	cout << "** BBBBB   BBBBBB                  SSS **" << endl;
	cout << "** BBBBB    BBBBBB                 SSS **" << endl;
	cout << "** BBBBB     BBBBB                 SSS **" << endl;
	cout << "** BBBBBBBBBBBBBBB      SSSSSSSSSSSS   **" << endl;
	cout << "** BBBBBBBBBBBBBB       SSSSSSSSSSSS   **" << endl;
	cout << "***BATTLE SHIP             BY          **" << endl;
	cout << "*********************Kevin Merrell*******" << endl;
	cout << "**********************Lucas Zimmerman****" << endl;
	cout << "***********************Bobby Borislavov**" << endl;
	cout << "*****************************************" << endl;
	cout << endl;
	
	cout << "Welcome to BattleShip" << endl
		<< "Many have faired these rough seas in pursuit of Victory!" << endl
		<< "Do you have what it takes to lead this fleet!?" << endl << endl;

	system("pause");
	system("CLS");

	cout << "The rules are easy." << endl
		<< "Each side will take turns targeting a location on each other's map." << endl
		<< "If a ship is hit, the map will indicate this by using (X) to symbolize it." << endl
		<< "Otherwise, the symbol (O) will indicate a miss" << endl
		<< "When an entire fleet has been sunk, there is a winner and...."
		<< "Well, you know" << endl << endl;

	system("pause");
	system("CLS");


	cout << "Let's Begin!!!" << endl;

	enemyDisplay(enemy1);
	placeShips(enemy2);

	placeShips(userBoard);
	printBoard(userBoard);

	while (victory == false)
	{
		do
		{
			do
			{
				cout << endl;
				cout << "Choose a position to target: ";
				cin >> letGuess;
				cin >> jGuess;
				
				cout << endl;
				
				upper = toupper(letGuess);

				switch (upper)
				{
				case 'A':
					iGuess = 1;
					break;
				case 'B':
					iGuess = 2;
					break;
				case 'C':
					iGuess = 3;
					break;
				case 'D':
					iGuess = 4;
					break;
				case 'E':
					iGuess = 5;
					break;
				case 'F':
					iGuess = 6;
					break;
				case 'G':
					iGuess = 7;
					break;
				case 'H':
					iGuess = 8;
					break;
				case 'I':
					iGuess = 9;
					break;
				case 'J':
					iGuess = 10;
					break;
				default:
					cout << "please guess choose between letters: (A-J)" << endl;
					break;
				}

				

			} while (!(letGuess == 'a' || letGuess == 'A' || letGuess == 'b' || letGuess == 'B' ||
			letGuess == 'c' || letGuess == 'C' || letGuess == 'd' || letGuess == 'D' ||
			letGuess == 'e' || letGuess == 'E' || letGuess == 'f' || letGuess == 'F' ||
			letGuess == 'g' || letGuess == 'G' || letGuess == 'h' || letGuess == 'H' ||
			letGuess == 'i' || letGuess == 'I' || letGuess == 'j' || letGuess == 'J')|| jGuess < 1 || jGuess > 10);

			
			if (enemy1[iGuess - 1][jGuess - 1] == "[ X ]" || enemy1[iGuess - 1][jGuess - 1] == "[ O ]")
				cout << "!! You have already targeted this position !!" << endl << "Please choose again." << endl;
		} while (enemy1[iGuess - 1][jGuess - 1] == "[ X ]" || enemy1[iGuess - 1][jGuess - 1] == "[ O ]");

		system("CLS");

		if (enemy2[iGuess - 1][jGuess - 1] == "[ S ]")
		{
			cout << "That's a hit!!" << endl;;
			enemy1[iGuess - 1][jGuess - 1] = "[ X ]";
			eShips -= 1;
		}
		else
		{
			cout << "You missed!!" << endl;
			enemy1[iGuess - 1][jGuess - 1] = "[ O ]";
		}

		printBoard(enemy1);
		cout << endl;
		printBoard(userBoard);

		system("pause");

		do
		{
		Randomize:

			iCGuess = rand() % ROWS;
			jCGuess = rand() % COLS;
		} while (userBoard[iCGuess][jCGuess] == "[ X ]" || userBoard[iCGuess][jCGuess] == "[ O ]");

		system("CLS");

		if (userBoard[iCGuess][jCGuess] == "[ S ]")
		{
			cout << "The enemy hit our ship!!" << endl;;
			userBoard[iCGuess][jCGuess] = "[ X ]";
			uShips -= 1;
		}
		else
		{
			cout << "The enemy missed." << endl;
			userBoard[iCGuess][jCGuess] = "[ O ]";
		}

		printBoard(enemy1);
		cout << endl;
		printBoard(userBoard);

		system("pause");

		if (eShips == 0 || uShips == 0)
			victory = true;
	}

	if (eShips == 0)
		cout << "Congratulations!!" << endl
		<< "You have put yourself in the face of danger and have came out victorious!" << endl;
	else
		cout << "You should've promoted a plebe into your position!" << endl
		<< "They would have had much more tatical intuiton than you!!" << endl;


	system("pause");
	return 0;
}//end main

 // This function prints an formats the board to display a representation of the enemies map
void enemyDisplay(string board[][COLS])
{
	int numRow = 1;

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			board[i][j] = "[ ~ ]";	// ~ = waves and a position not targeted by user yet.
		}//end for
	}//end for

	cout << "      1    2    3    4    5    6    7    8    9   10" << endl; // grid colums by number

																			// this switch convers the row to represent letter values
	for (int i = 0; i < ROWS; i++)
	{
		switch (numRow)
		{
		case 1:
			rowLet = 'A';
			break;
		case 2:
			rowLet = 'B';
			break;
		case 3:
			rowLet = 'C';
			break;
		case 4:
			rowLet = 'D';
			break;
		case 5:
			rowLet = 'E';
			break;
		case 6:
			rowLet = 'F';
			break;
		case 7:
			rowLet = 'G';
			break;
		case 8:
			rowLet = 'H';
			break;
		case 9:
			rowLet = 'I';
			break;
		case 10:
			rowLet = 'J';
			break;
		}




		// this is where the board prints and displays
		cout << setw(3) << right << rowLet << " ";
		numRow++;
		for (int j = 0; j < COLS; j++)
		{
			cout << board[i][j];
		}
		cout << endl;
	}
	cout << endl;
	return;
}



void placeShips(string board[][COLS])
{
	int ships[NUM_OF_SHIPS] = { 5, 4, 3, 3, 2 }; // represents the ships' length
	int iStart, jStart, ort, rows, cols;
	int numRow = 1;


	// formats  the board to make a grid of '~' 
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			board[i][j] = "[ ~ ]";
		}//end for
	}//end for

	 // this will place all ships on the enemy board without overlapping
	for (int i = 0; i < NUM_OF_SHIPS; i++)
	{
		//istantiates iStart, jStart, and ort until location doesnt have a ship piece
	Randomize:
		do
		{
			iStart = rand() % ROWS;
			jStart = rand() % COLS;
			ort = rand() % 2;
		} while (board[iStart][jStart] == "[ S ]");

		if (ort == 0) //Lays ship horizontally
		{
			// this makes sure that the ship will start on the board
			while (jStart + ships[i] >= COLS)
			{
				jStart = rand() % COLS;
			}

			// this will check to make sure that the are no ship pieces between the length of the ship being placed
			for (int cols = jStart; cols < jStart + ships[i]; cols++)
			{
				if (board[iStart][cols] == "[ S ]")
					goto Randomize;
			}

			//this places ship after all previous checks have been met
			for (int cols = jStart; cols < jStart + ships[i]; cols++)
			{
				board[iStart][cols] = "[ S ]";
			}

		}

		if (ort == 1) //Lays ships vetically 
		{
			// this makes sure that the ship will start on the board
			while (iStart + ships[i] >= ROWS)
			{
				iStart = rand() % ROWS;
			}

			// this will check to make sure that the are no ship pieces between the length of the ship being placed
			for (int rows = iStart; rows < iStart + ships[i]; rows++)
			{
				if (board[rows][jStart] == "[ S ]")
					goto Randomize;
			}

			//this places ship after all previous checks have been met
			for (int rows = iStart; rows < iStart + ships[i]; rows++)
			{
				board[rows][jStart] = "[ S ]";
			}
		}
	}
	return;
}

void printBoard(string board[ROWS][COLS])
{
	int numRow = 1;
	cout << "      1    2    3    4    5    6    7    8    9   10" << endl;

	for (int i = 0; i < ROWS; i++)
	{
		switch (numRow)
		{
		case 1:
		{
			rowLet = 'A';
			break;
		}
		case 2:
		{
			rowLet = 'B';
			break;
		}
		case 3:
		{
			rowLet = 'C';
			break;
		}
		case 4:
		{
			rowLet = 'D';
			break;
		}
		case 5:
		{
			rowLet = 'E';
			break;
		}
		case 6:
		{
			rowLet = 'F';
			break;
		}
		case 7:
		{
			rowLet = 'G';
			break;
		}
		case 8:
		{
			rowLet = 'H';
			break;
		}
		case 9:
		{
			rowLet = 'I';
			break;
		}
		case 10:
		{
			rowLet = 'J';
			break;
		}

		}

		cout << setw(3) << right << rowLet << " ";
		numRow++;
		for (int j = 0; j < COLS; j++)
		{
			cout << board[i][j];
		}
		cout << endl;
	}
	return;

}



