/*Author: Francisco Bumanglag
Project: Lo Shu Magic Square
Assignment: Module 12 Project9
Course: C++ Santa Ana College
Class: CMPR120 Dr. Tahir Aziz
Date: May 5, 2024*/


#include <iostream>		//standard input/output operations
#include <iomanip>		//input/output manipulation
#include <string>		//string handling capabilities 
#include <fstream>		//file stream operations

using namespace std;	//access standard library symbols directly

const int SIZE = 3;		//fixed sized integer constant

bool LoShuMagicSquare(int grid[SIZE][SIZE]);	//function check the grid
void printGrid(int grid[SIZE][SIZE]);			//function print grid

int main() {

	//read data from file grid array using nested loops
	int grid[SIZE][SIZE];

	ifstream inputFile("C:\\Users\\franc\\OneDrive\\Desktop\\data.txt");

	if (inputFile.is_open()) {
	for (int i = 0; i < SIZE; i++){
		for (int j = 0; j < SIZE; j++){
			inputFile >> grid[i][j];
		}
	}
	inputFile.close();

		//display import message if successful
		cout << "Grid read from file: " << endl;
		printGrid(grid);

		//determine is grid is Lo Shu Magic Square or Not
		if (LoShuMagicSquare(grid)) {
			cout << "The grid is a Lo Shu Magic Square." << endl;
		}
		else {
			cout << "The grid is not a Lo Shu Magic Square." << endl;
		}
}
		else {
			cerr << "Unable to open file." << endl;  //no file found

			}

			return 0;

}
//check if grid forms magic square with given sum
bool LoShuMagicSquare(int grid[SIZE][SIZE]) {
	int sum = 15;

	for (int i = 0; i < SIZE; i++) {
		int rowSum = 0, colSum = 0;
		for (int j = 0; j < SIZE; j++) {
			rowSum += grid[i][j];
			colSum += grid[j][i];
		}
		if (rowSum != sum || colSum != sum)
			return false;
	}
	//calculate diagnal sums and check if they match
	int diagSum1 = 0, diagSum2 = 0;
	for (int i = 0; i < SIZE; i++) {
		diagSum1 += grid[i][i];
		diagSum2 += grid[i][SIZE - i - 1];
	}
	if (diagSum1 != sum || diagSum2 != sum)
		return false;

	return true;

}
//print the grid in tabular format
void printGrid (int grid[SIZE][SIZE]){
	for (int i=0; i<SIZE; i++){
		for (int j = 0; j < SIZE; j++) {
			cout << grid[i][j] << "\t";
		}
		cout << endl; 

		}
	}


