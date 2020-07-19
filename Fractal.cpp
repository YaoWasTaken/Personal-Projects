#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

void SierpenskiTriangle(int size, char arr[][96], int x, int y, int newLine);

int main() {
	int size;
	int actualSize = 1;
	int row;
	int col;
	int i;
	int j;

	char drawingBoard[96][96];

	for (i = 0; i < 96; ++i) {
		for (j = 0; j < 96; ++j) {
			drawingBoard[i][j] = ' ';
		}
	}
	cout << "Enter a size (1 - 5)\n"; 
	cin >> size;

	for (i = 1; i <= size; ++i) {
		actualSize = actualSize * 2;
	}

	SierpenskiTriangle(actualSize, drawingBoard, 0, 0, actualSize);

	for (row = 0; row < 96; ++row) {

		if (row == actualSize) {
			break;	
		}

		for (col = 0; col < 96; ++col) {
			if (drawingBoard[row][col] == '\n') {
				cout << drawingBoard[row][col];
				break;
			}
			cout << drawingBoard[row][col];

		}
	}

	return 0;
}

void SierpenskiTriangle(int size, char arr[][96], int x, int y, int constSize) {
	int row;
	int col;
	int space;
	int i; // i is a space index to determine the number of spaces as opposed to using the number of rows
	row = x;

	for (i = 0; i < size; ++i) {

		if (i == size - 1) {

			col = y;

			arr[row][col] = '/';

			++col;

			for (space = 0; space < i * 2; ++space) {
				arr[row][col] = '_';
				++col;
			}
			
			arr[row][col] = '\\';

			

			if (col > constSize) {
				++col;
				arr[row][col] = '\n'; 
			}
		}

		else {
			col = y;
			for (space = 0; space < size - i - 1; ++space) {
				arr[row][col] = ' ';
				++col;
			} 

			arr[row][col] = '/';
			
			++col;

			for (space = 0; space < i * 2; ++space) {
				arr[row][col] = ' ';
				++col;
			}

			arr[row][col] = '\\';

			++col;

			if (col > constSize) {
				arr[row][col] = '\n';
			}
		}

		++row;
	}
	
	if (size != 2) {
		SierpenskiTriangle(size / 2, arr, x, y + size / 2, constSize); // top
	}

	if (size != 2) {
		SierpenskiTriangle(size / 2, arr, x + size / 2, y, constSize); // left
	}

	if (size != 2) {
		SierpenskiTriangle(size / 2, arr, x + size / 2, y + size, constSize); // right side
	}
	//ERROR: right and the left triangles are interferring with each other
}
	

