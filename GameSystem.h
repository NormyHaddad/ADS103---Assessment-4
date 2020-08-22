#pragma once
#include <iostream>
#include <conio.h>
#include <string>
#include <vector>
using namespace std;

char validInputs[9] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i' };

bool IsValidPlot(char C)
{
	bool B = 0;
	for (int i = 0; i < 9; i++)
	{
		if (C == validInputs[i]) 
		{ 
			B = 1; 
		}
	}
	return B;
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
		if (player == 0)
		{
			symbol = "X";
		}
		else if (player == 1)
		{
			symbol = "O";
		}

		if (IsValidInsert(x, y))
		{
			grid[x][y] = symbol;
		}
	}

	void PrintGameDisplay()
	{
		
		for (int i = 0; i < 3; i++)
		{
			cout << endl << "  -------------------" << endl;
			cout << "  |  ";
			for (int j = 0; j < 3; j++)
			{
				/*
				if (grid[i][j] != "X" || grid[i][j] != "O")
				{
					cout << " " << "  |  ";
				}
				else
				{
					cout << grid[i][j] << "  |  ";
				}
				*/
				cout << grid[i][j] << "  |  ";
			}
		}
		cout << endl << "  -------------------" << endl;
	}

	vector<int> AIPlay()
	{

	}

	void PrintPauseScreen()
	{
		cout << "\t|-------------------|" << endl;
		cout << "\t|      Paused       |" << endl;
		cout << "\t|      P - Play       |" << endl;
		cout << "\t|      Q - Quit       |" << endl;
		cout << "\t|---------------------|" << endl;
	}

	void PrintMenuScreen()
	{
		cout << "\t|---------------------|" << endl;
		cout << "\t|Wecome to Tic Tac Toe|" << endl;
		cout << "\t|      P - Play       |" << endl;
		cout << "\t|      Q - Quit       |" << endl;
		cout << "\t|---------------------|" << endl;
	}

	void PrintGameOverScreen()
	{
		cout << "\t|---------------------|" << endl;
		cout << "\t|     Play Again?     |" << endl;
		cout << "\t|      P - Play       |" << endl;
		cout << "\t|      Q - Quit       |" << endl;
		cout << "\t|---------------------|" << endl;
	}

};

