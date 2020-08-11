#include <iostream>
#include <ctime>
#include <cstdlib>
#include <conio.h>
#include "GameSystem.h"
#include <iostream>
using namespace std;

enum
{
	PLAYER = 0,
	AI = 1,
};

int main()
{
	bool isVictory = false;
	GameBoard myBoard;
	bool turnPlayer = 0;
	int randomNum = 0;
	unsigned int seed = time(0);
	srand(seed);

	myBoard.playTurn(0, 0, PLAYER);
	myBoard.playTurn(1, 0, PLAYER);
	myBoard.playTurn(2, 0, PLAYER);

	myBoard.playTurn(0, 2, AI);
	myBoard.playTurn(1, 2, AI);
	myBoard.playTurn(2, 2, AI);

	myBoard.printGameDisplay();
	isVictory = myBoard.checkForWin();
	cout << "  " << isVictory;
	_getch();
}