// ******************************
// Student Name: Jackson Zheng
// Student Number: 20672834
//
// SYDE 121 Lab: 005 Assignment: 003
//
// Filename: Lab0503.cpp
// Date submitted: 2017-10-16
//
// I hereby declare that this code, submitted
// for crdit for the course SYDE121, is a product
// of my own efforts. This coded solution has
// not been plagiarized from other sources
// as not been knowingly plagiarzed by others.
// *******************************

// This program takes in a tolerance value between 0.0 and 0.1
// Display a table with the nth step of the series along with approximation of pi
// The stopping criterion for the series is when the tolerance value is less than or equal to the user tolerance value

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main ( ) {

	int n = 0;
	double denom = 1.0;
	double pi = 0;
	double previous_term = 0;
	double tolerance = 1;
	double user_tolerance = 0;

	cout.setf(ios::fixed);

	do {
		cout << "Enter a value between 0.0 and 0.1 for the Tolerance of Pi\n\n";
		cin >> user_tolerance;

	} while ( user_tolerance <= 0 || user_tolerance >= 0.1 );

	// Column header for table
	cout << endl << setw(13) << "Nth-Term" << setw(13) << " " << setw(13) << "Pi" << endl;
	cout << "----------------------------------------------" << endl;

	for ( n = 1; tolerance > user_tolerance; n++ ) {
		previous_term = pi;

		// Subtract if nth term is even. Add if nth term is odd.
		if ( n % 2 == 0) {
			pi -= 4 / denom;
		} else {
			pi += 4 / denom;
		}

		tolerance = fabs( pi - previous_term );

		// Rows for the table. Displays the nth step along with approximation of pi
		cout << setw(13) << n << setw(12) << " ";
		cout << setw(13) << setprecision(12) << pi << endl;

		denom += 2; // the denominator of a term in the series increases by 2 each time. e.g. 1st term: 4/1, 2nd term 4/3

	}


}
