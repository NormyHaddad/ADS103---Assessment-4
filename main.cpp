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
	bool gameIsRunning = false;
	GameBoard myBoard;
	bool turnPlayer = 0;
	int randomNum;
	unsigned int seed = time(0);
	srand(seed);
	char input;

	myBoard.PrintMenuScreen();
	cin >> input;
	if (input == 'q')
	{
		exit(0);
	}
	if (input == 'p')
	{
		gameIsRunning = true;
	}

	while (gameIsRunning)
	{
		vector<int> coordinates;
		char location;
		cout << "\tEnter a grid location: ";
		cin >> location;
		cout << location << endl;
		if (location == 'p')
		{

		}

		if (IsValidPlot(location))
		{
			coordinates = GetBoardPosition(location);
			myBoard.PlayTurn(coordinates[0], coordinates[1], turnPlayer);
			turnPlayer = !turnPlayer;
			system("CLS");
			myBoard.PrintGameDisplay();
			cout << coordinates[0] << coordinates[1] << endl << turnPlayer << endl;
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
			cin >> input;
			if (input == 'p')
			{
				myBoard.ClearBoard();
				gameIsRunning = true;
			}
			if (input == 'q')
			{
				system("CLS");
				cout << "\tGoodbye!";
				Sleep(1500);
				exit(0);
			}
		}
	}
}