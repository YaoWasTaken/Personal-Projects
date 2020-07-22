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
	cout << "Enter the number of recursions 0 - 4\n"; 
	cin >> size;

	for (i = 0; i <= size; ++i) {
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

void SierpenskiTriangle(int size, char arr[][96], int x, int y, int newLine) {
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
			++newLineCondition;
		}

		++row;
	}
	
	if (size != 2) {
		SierpenskiTriangle(size / 2, arr, x, y + size / 2, newLine); // top
		SierpenskiTriangle(size / 2, arr, x + size / 2, y, newLine + newLine); // left
		SierpenskiTriangle(size / 2, arr, x + size / 2, y + size, newLine); // right side
	}

	//ERROR FOUND: wrong number of columns
}
	

