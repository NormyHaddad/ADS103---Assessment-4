#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <conio.h>
#include <vector>
#include <Windows.h>
#include "GameSystem.h"
using namespace std;

enum
{
	PLAYER = 0,
	AI = 1,
};

int main()
{
	int playerDice = 0;
	int AIDice = 0;
	bool gameIsRunning = false;
	GameBoard myBoard;
	bool turnPlayer = 0;
	int randomNum;
	unsigned int seed = time(0);
	srand(seed);
	char input;

	myBoard.PrintMenuScreen();
	cout << "\tEnter your choice: ";
	cin >> input;
	if (input == 'q')
	{
		exit(0);
	}
	if (input == 'p')
	{
		gameIsRunning = true;
	}

	do
	{
		playerDice = (rand() % 5) + 1;
		AIDice = (rand() % 5) + 1;
	} while (playerDice == AIDice);

	ClearScreen();
	cout << "\n\tYour dice roll: " << playerDice << endl;
	Sleep(1000);
	cout << "\tAI dice roll: " << AIDice << endl;
	Sleep(1000);

	if (AIDice > playerDice)
	{
		cout << "\n\tRip, AI goes first";
		turnPlayer = AI;
	}
	else if (playerDice > AIDice)
	{
		cout << "\n\tHooray, you go first";
		turnPlayer = PLAYER;
	}
	Sleep(2000);

	while (gameIsRunning)
	{
		ClearScreen();
		myBoard.PrintGameDisplay();
		vector<int> coordinates;
		char location = 'a';
		if (turnPlayer == 0)
		{
			cout << "\tEnter a grid location: ";
			cin >> location;
		}
		if (location == 'p')
		{
			myBoard.PrintPauseScreen();
			cout << "\t";
			cin >> location;
			if (location == 'q')
			{
				ExitGame();
			}
			else if (location == 'p')
			{
				myBoard.PrintGameDisplay();
			}
		}

		if (IsValidPlot(location))
		{
			coordinates = GetBoardPosition(location);
			myBoard.PlayTurn(coordinates[0], coordinates[1], turnPlayer);
			turnPlayer = !turnPlayer;
			ClearScreen();
			myBoard.PrintGameDisplay();
		}
		if (myBoard.CheckForWin())
		{
			gameIsRunning = false;
			if (turnPlayer == AI)
			{
				cout << "  Congratulations, you won!" << endl;
			}
			else if (turnPlayer == PLAYER)
			{
				cout << "  Aww man, you lost. ;(" << endl;
			}
			Sleep(1500);
			myBoard.PrintGameOverScreen();
			cout << "\t";
			cin >> input;
			if (input == 'p')
			{
				main();
			}
			if (input == 'q')
			{
				ClearScreen();
				ExitGame();
			}
		}
		if (myBoard.IsFull() && !myBoard.CheckForWin())
		{
			cout << "Whoops, nobody won\n";
			myBoard.PrintGameOverScreen();
			cout << "\t";
			cin >> input;
			if (input == 'p')
			{
				main();
			}
			if (input == 'q')
			{
				ClearScreen();
				ExitGame();
			}
		}
	}
}