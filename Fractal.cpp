#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

void SierpenskiTriangle(int size, char arr[][128], int x, int y, int newLine);

int main() {
	int size;
	int actualSize = 1;
	int row;
	int col;
	int i;
	int j;

	char drawingBoard[128][128];

	for (i = 0; i < 128; ++i) {
		for (j = 0; j < 128; ++j) {
			drawingBoard[i][j] = ' ';
		}
	}
	cout << "Enter the number of recursions (0 - 5)\n"; 
	cin >> size;

	for (i = 0; i <= size; ++i) {
		actualSize = actualSize * 2;
	}

	SierpenskiTriangle(actualSize, drawingBoard, 0, 0, actualSize);

	for (row = 0; row < 128; ++row) {

		if (row == actualSize) {
			break;
		}

		for (col = 0; col < 128; ++col) {
			if (drawingBoard[row][col] == '\n') {
				cout << drawingBoard[row][col];
				break;
			}
			cout << drawingBoard[row][col];

		}
	}

	return 0;
}

void SierpenskiTriangle(int size, char arr[][128], int x, int y, int newLine) {
	int row;
	int col;
	int space;
	int i; // i is a space index to determine the number of spaces
	int newLineCondition;

	row = x;
	newLineCondition = newLine;

	for (i = 0; i < size; ++i) {

		col = y;
		for (space = 0; space < size - i - 1; ++space) {
			arr[row][col] = ' ';
			++col;
		} 

		arr[row][col] = '/';
			
		++col;


		for (space = 0; space < i * 2; ++space) {
			if (i == size - 1) {
				arr[row][col] = '_';
			}
			else {
				arr[row][col] = ' ';
			}
			++col;
		}
		
		arr[row][col] = '\\';

		++col;

		if (col > newLineCondition) {
			arr[row][col] = '\n';
		}
		++newLineCondition;
		++row;
	}
	
	if (size != 2) {
		SierpenskiTriangle(size / 2, arr, x, y + size / 2, newLineCondition); // top
		SierpenskiTriangle(size / 2, arr, x + size / 2, y, newLineCondition); // left
		SierpenskiTriangle(size / 2, arr, x + size / 2, y + size, newLineCondition); // right side
	}
}
	

