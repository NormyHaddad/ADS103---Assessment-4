#pragma once
#include <iostream>
#include <conio.h>
#include <string>
#include <vector>
using namespace std;

char validInputs[9] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i' };

bool IsValidPlot(char C)
{
	bool B = false;
	for (int i = 0; i < 9; i++)
	{
		if (C == validInputs[i]) 
		{ 
			B = true; 
		}
	}
	return B;
}

void ClearScreen()
{
	system("CLS");
	cout << endl;
}

void ExitGame()
{
	cout << "\tGoodbye!";
	Sleep(1500);
	exit(0);
}

vector<int> GetBoardPosition(char C)
{
	vector<int> pos;
	
	if (C == 'a') { pos = { 0, 0 }; }
	else if (C == 'b') { pos = { 0, 1 }; }
	else if (C == 'c') { pos = { 0, 2 }; }
	else if (C == 'd') { pos = { 1, 0 }; }
	else if (C == 'e') { pos = { 1, 1 }; }
	else if (C == 'f') { pos = { 1, 2 }; }
	else if (C == 'g') { pos = { 2, 0 }; }
	else if (C == 'h') { pos = { 2, 1 }; }
	else if (C == 'i') { pos = { 2, 2 }; }
	return pos;
}

struct GameBoard
{
	string grid[3][3] = { {"a", "b", "c"}, {"d", "e", "f"}, {"g", "h", "i"} };

	bool IsFull()
	{
		int count = 0;
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				if (grid[i][j] != "X" || grid[i][j] != "O")
				{
					count += 1;
				}
			}
		}
		return (count <= 0);
	}

	void ClearBoard()
	{
		grid[0][0] = "a";
		grid[0][1] = "b";
		grid[0][2] = "c";
		grid[1][0] = "d";
		grid[1][1] = "e";
		grid[1][2] = "f";
		grid[2][0] = "g";
		grid[2][1] = "h";
		grid[2][2] = "i";
	}
	
	bool IsValidInsert(int x, int y)
	{
		if (grid[x][y] == "X" || grid[x][y] == "O")
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	bool CheckForWin()
	{
		//if a horizontal row matches
		if (grid[0][0] == grid[0][1] && grid[0][1] == grid[0][2]) {return(true);}
		if (grid[1][0] == grid[1][1] && grid[1][1] == grid[1][2]) {return(true);}
		if (grid[2][0] == grid[2][1] && grid[2][1] == grid[2][2]) {return(true);}

		//if a vertical column matches
		if (grid[0][0] == grid[1][0] && grid[1][0] == grid[2][0]) {return(true);}
		if (grid[0][1] == grid[1][1] && grid[1][1] == grid[2][1]) {return(true);}
		if (grid[0][2] == grid[1][2] && grid[1][2] == grid[2][2]) {return(true);}

		//if there is a diagonal line
		if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]) {return(true);}
		if (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0]) {return(true);}

		//if there are no matches
		else {return(false);}
	}

	void PlayTurn(int x, int y, int player)
	{
		string symbol;
		vector<int> AIloc;
		if (player == 0)
		{
			symbol = "X";
		}
		else if (player == 1)
		{
			symbol = "O"; 
			AIloc = AIPlay();
			x = AIloc[0];
			y = AIloc[1];
		}

		if (IsValidInsert(x, y))
		{
			grid[x][y] = symbol;
		}
	}

	void PrintGameDisplay()
	{
		cout << endl;
		for (int i = 0; i < 3; i++)
		{
			cout << endl << "\t-------------------" << endl;
			cout << "\t|  ";
			for (int j = 0; j < 3; j++)
			{	
				cout << grid[i][j] << "  |  ";
			}
		}
		cout << endl << "\t-------------------" << endl;
	}

	vector<int> AIPlay()
	{
		vector<int> location;
		if (IsValidInsert(1, 1)) { location = { 1, 1 }; }
		else if (IsValidInsert(0, 2)) { location = {0, 2}; }
		else if (IsValidInsert(0, 0)) { location = {0, 0}; }
		else if (IsValidInsert(2, 0)) { location = {2, 0}; }
		else if (IsValidInsert(2, 2)) { location = {2, 2}; }
		else if (IsValidInsert(2, 1)) { location = {2, 1}; }
		else if (IsValidInsert(1, 2)) { location = {1, 2}; }
		else if (IsValidInsert(0, 1)) { location = {0, 1}; }
		else if (IsValidInsert(1, 2)) { location = {1, 2}; }
		return location;
	}

	void PrintPauseScreen()
	{
		ClearScreen();
		cout << "\t|---------------------|" << endl;
		cout << "\t|       Paused        |" << endl;
		cout << "\t|      P - Play       |" << endl;
		cout << "\t|      Q - Quit       |" << endl;
		cout << "\t|---------------------|" << endl;
	}

	void PrintMenuScreen()
	{
		ClearScreen();
		cout << "\t|---------------------|" << endl;
		cout << "\t|Wecome to Tic Tac Toe|" << endl;
		cout << "\t|      P - Play       |" << endl;
		cout << "\t|      Q - Quit       |" << endl;
		cout << "\t|---------------------|" << endl;
	}

	void PrintGameOverScreen()
	{
		ClearScreen();
		cout << "\t|---------------------|" << endl;
		cout << "\t|     Play Again?     |" << endl;
		cout << "\t|      P - Play       |" << endl;
		cout << "\t|      Q - Quit       |" << endl;
		cout << "\t|---------------------|" << endl;
	}

};

