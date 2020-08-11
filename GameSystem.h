#pragma once
#include <string>
using namespace std;

struct GameBoard
{
	string grid[3][3] = { {"a", "b", "c"}, {"d", "e", "f"}, {"g", "h", "i"} };
	
	bool isValidInsert(int x, int y)
	{
		if (grid[x][y] != "X" || grid[x][y] != "O")
		{
			return (true);
		}
		else
		{
			return (false);
		}
	}

	bool checkForWin()
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

	void insertSymbol(string str, int x, int y)
	{
		grid[x][y] = str;
	}

	void playTurn(int x, int y, int player)
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

		if (isValidInsert(x, y))
		{
			grid[x][y] = symbol;
		}
	}

	void printGameDisplay()
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
};