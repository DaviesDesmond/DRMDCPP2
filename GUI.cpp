#include "GUI.h"
#include "dungeon.h"
#include<iostream>
#include<cstdlib>

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

int incrementIndex(int i, int n);


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
			printSize = 7;
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
		* top 1 + 2n
		* width of board: (numSlope) + (numCol)*(numSlope+top)
		* n + numCol*(2n + 1)
		* height of board: height*numCol -1
		*/

		int n = (printSize + 1) / 4;

		yDim = (1 + 2 * n) + (2 * n) * (numRow - 1);
		xDim = numCol * (3 * n + 1) + n;

		int _i, index;
		bool doSlash,
			 doUnder = false;
		char nextChar;

		//might be a way todo this for each row more easily
		board = new char* [yDim];
		for (int i = 0; i < yDim; i++) {
			board[i] = new char[xDim];
			
			//Checking which unique row we are in to avoid duplicate characters
			_i = i % (n * 2);
			

			if (0 < _i && _i <= n) {
				//this calculates when the slopes will happen for this row
				//the first n lines 
				index = n - n * (_i / n) - _i % n;
				nextChar = '/';
			}
			else {
				index = (_i + n - 1) % n;
				nextChar = '\\';
			}
			for (int j = 0; j < xDim; j++) {
				
				
				if (j == index) {
					doSlash = true;
				}
				else {
					doSlash = false;
				}
				if (doSlash) {
					if (0 < _i && _i <= n) {
						board[i][j] = nextChar;
						index = incrementIndex(index, n);
					}
					else {
						board[i][j] = nextChar;
						index = incrementIndex(index, n);
					}
					if (nextChar == '/') {
						nextChar = '\\';
						doUnder = false;
					}
					else {
						nextChar = '/';
						doUnder = true;
					}
				}
				//need to calculate if we are in the area that needs dashes
				// only needs to happen in rows 0 and ((1+2n)+1/2)(the middle row)
				else if((_i == 0 || _i == (n)) && doUnder) {
					board[i][j] = '_';
				}
				
				else{
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


int incrementIndex(int i, int n) {
	/*
	* INPUTS:
	*	i: the column that the most recent slash was in
	*	n: the n value of the current grid
	* Returns:
	*	
	*/
	
	int baseIndex = i;
	while (baseIndex - (1 + 3 * n) >= 0) {
		baseIndex -= 1 + 3 * n;
	}
	int retVal = i + 2 + n * 2 + ((n - 1) - baseIndex) * 2;
	return retVal;
}
