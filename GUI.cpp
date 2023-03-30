#include "GUI.h"
#include "dungeon.h"
#include<iostream>
#include <cstdlib>

using namespace::std;

//void GUI(dungeon board, int xpos, int ypos) {
//	/*
//	INPUTS:
//		board: the board we are playing on
//		xpos: the x coordinate the player is currently on
//		ypos: the y coordinate the player is currently on
//	OUTUTS:
//		n/a
//	PURPOSE:
//		outputs the board in the display with the player on it
//	*/
//
//}

void GUI(int _numRow, int _numCol, int _type, int _printSize) {
	//assuming that the inputs have been sterilized already (type is 1/0, others are positive non-0 integers)
	int numRow = _numRow,
		numCol = _numCol,
		type = _type,
		printSize = _printSize,//variable to store the max string length that needs to fit in a space
		minSize,//minimum allowable cell width
		xDim,
		yDim;
	bool allowSplit = false;//are you allowed to split a name in half?


	//set the minimum sizes
	if (type == 1) { minSize = 5; }
	else { minSize = 7; };

	//set the print sizes
	if (type == 1) { 
		if (printSize >= minSize) {
			printSize = 5;
			if (printSize % 2 == 0) printSize += 1;
		}
	}
	else { 
		if (printSize <= minSize) {
			printSize = 11;
		}
		else {
			printSize += 3 - printSize % 4;
		}
	
	};
	bool countup = false;
	//draw the board

	char** board;
	

	if (type == 1) {
		//printing square grid
		//easier, cause rows and columns are in a square grid
	}
	else {
		/*printing hex grid
		* need to deal with the offset of being a hex grid
		* I hate c++... need to use an array in an array to use 2d
		* using constant "n" that everything can be based upon
		* we have 2*n unique rows
		* numChar = numChar + (numChar + 1)%4
		* numChar = 4n - 1
		* n = (numChar + 1)/4
		* Width 1 + 4n
		* numSlope -1 + 4n
		* Height 1 + 2n
		* slope n
		* top 1 + 4n
		* width of board: (numSlope) + (numCol)*(numSlope+top)
		* n + numCol*(2n + 1)
		* height of board: height*numCol -1
		*/

		int n = (printSize + 1) / 4;

		yDim = (1 + 2 * n) * numRow - 1;
		xDim = numCol * (3 * n + 1) + n;

		//might be a way todo this for each row more easily
		board = new char* [yDim];
		for (int i = 0; i < yDim; i++) {
			board[i] = new char[xDim];
			int _i = i % (n * 2);
			for (int j = 0; j < xDim; j++) {
				bool spec;
				spec = false;
				if (spec) {
					/*
					* 4-_i%4||
					*/
				}
				else {
					board[i][j] = ' ';
				}

			}
		}





		
		//this just prints the board
		for (int i = 0; i < yDim; i++) {
			for (int j = 0; j < xDim; j++) {
				cout << board[i][j];
			}
			cout << endl;
		}
	}
}
