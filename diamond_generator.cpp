// ******************************
// Student Name: Jackson Zheng
// Student Number: 20672834
//
// SYDE 121 Lab: 005 Assignment: 001
//
// Filename: Lab0501.cpp
// Date submitted: 2017-10-16
//
// I hereby declare that this code, submitted
// for crdit for the course SYDE121, is a product
// of my own efforts. This coded solution has
// not been plagiarized from other sources
// as not been knowingly plagiarzed by others.
// *******************************

// This program takes in an odd integer value between 1 and 20
// The output will be a diamond shape with the number of rows equal to the integer input

#include <iostream>
using namespace std;

int main ( ) {

	int size = 0;
	int row = 0;
	int col = 0;
	int mid_point = 0;
	int min = 0;
	int max = 0;

	do {
		cout << "Enter the size of the diamond.";
		cout << " The size must be an odd number, and between 1 and 20." << endl;
		cin >> size;
		cout << "you entered: " << size << endl << endl;

	} while ( size % 2 == 0 || size < 1 || size > 19 );

	// min and max variables will be used to determine when to print a '*'
	mid_point = size / 2 + 1;
	min = mid_point;
	max = mid_point;

	for ( row = 1; row <= size; row++ ) {  // counting rows

		for ( col = 1; col <= size; col++ ) {  // counting coljumns
			if ( col >= min && col <= max ) {  // print a "*" if the column number is equal to or between the min and max
				cout << "*";

			} else {
				cout << " ";
			}
		}

		cout << endl;

		if ( row >= mid_point ) {  // min and max variable for bottom half of diamond
			min++;
			max--;

		} else { // min and max variable for top half of diamond
			min--;
			max++;
		}
	}

}
