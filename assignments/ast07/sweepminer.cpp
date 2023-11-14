#include "sweepminer.h"
#include <iomanip>
#include <vector> 

using namespace std;

//vv Uncomment next line to get helpful debug statements, but leave commented for final submission vv
//#define DEBUG 

/* Your description here */
void Sweepminer::allocateBoard()
{
	//TODO: Dynamically allocate the 2D board array (please don't linearize)
	//You can assume that the height and width have already been set before calling
	//After allocating, fill the board with maxDist to mark as uninitialized

	int maxDist = width + height + 1; //Maximum possible distance a space could be from bomb
	board = new int * [height];
	for(int i = 0; i < height; i++){
		board[i] = new int [width];
	}
}

/* */
void Sweepminer::deallocateBoard()
{
	//TODO: Deallocate the 2D board array
	//You can assume that the height and width have already been set before calling
	for(int i = 0; i < height; i++){
		delete [] board[i];
	}
	delete [] board;
}

/* */
void Sweepminer::generateDistances(Position pos, int distance)
{
	//TODO: Finish the function
	//This function should recursively mark the distances of all squares
	//to the closest bomb. 
	
	//If the position on the board is already closer to another bomb (i.e.
	//the distance in the current spot is less than the distance param)
	//Then it does not need replaced

	//Otherwise, the distance should be replaced and the adjacent squares should
	//Also have their distances generated as long as they are in bounds
	//(You can check the bounds as either base cases or before recursively calling)
	//Consider the variables you have access to and how you might check whether a square
	//is within the boundaries of the board (e.g. Something like (-1, 4) is out of
	//bounds of a 10x10 board).

	//Please see the pdf and video for a more detailed explanation




	// generateDistances(pos, distance);
}

//------------------------------------ FUNCTIONS FOR SKELETON ------------------------------------
/* Populates the board by randomly generating where the bombs go and then
calling the generateDistances function to fill in the distances */
void Sweepminer::populateBoard(const int& bomb_count)
{
	vector<Position> bombPositions;
	int i, j;
	Position* temp;
	bool duplicatePosition = false;

	for (i = 0; i < bomb_count; i++)
	{
		//Generate the next bomb position and make sure it's not a duplicate
		temp = new Position(rand() % width, rand() % height);
		while (duplicatePosition)
		{
			duplicatePosition = false;
			for (j = 0; j < (int)bombPositions.size(); j++)
			{
				if (bombPositions[j] == *temp)
				{
					duplicatePosition = true;
					break;
				}
			}
		}

		//Then, add the bomb and generate its distances
		generateDistances(*temp, 0); //Position is temp, distance to bomb is 0
		delete temp;
	
		//Debug print info
		#ifdef DEBUG
		cout << "Board after putting bomb " << i << " at (" << temp.x << ", " << temp.y << ")" << endl;
		printBoard();
		#endif
	}
}

/* Prints all of the distances to flags to the terminal */
void Sweepminer::printBoard()
{
	int i, j;
	cout << setfill('-') << setw(3 * width + 3) << "" << setfill(' ') << endl; //Print top border
	for (i = 0; i < height; i++)
	{
		cout << "| "; //Print left border
		for (j = 0; j < width; j++)
		{
			if (board[i][j] == 0) //If this spot contains a bomb/flag, print its
				cout << " " << flag << " ";
			else //Else print the distance
				cout << setw(2) << right << board[i][j] << " ";
		}
		cout << "|" << endl; //Print right border
	}
	cout << setfill('-') << setw(3 * width + 3) << "" << setfill(' ') << endl; //Print bottom border
}