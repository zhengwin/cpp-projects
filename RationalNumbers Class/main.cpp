// ******************************
// Student Name: Jackson Zheng
// Student Number: 20672834
//
// SYDE 121 Lab: 009 Assignment: 002
//
// Filename: Lab0902.dev
// Date submitted: 2017-11-20
//
// I hereby declare that this code, submitted
// for crdit for the course SYDE121, is a product
// of my own efforts. This coded solution has
// not been plagiarized from other sources
// as not been knowingly plagiarzed by others.
// *******************************

#include "rational.h"
using namespace std;

int main ()
{
	int num1 = 7;
	int den1 = -4;
	int num2 = 3;
	int den2 = 7;
	cout << "Rational Numbers\n";

	Rational c( num1, den1 );
	Rational d( num2, den2 );
	// store result of calculation in object x
	Rational x;

	// print default object
	cout << "By default, x is: ";
    x.printRational();
    cout << endl << endl;

    c.printRational();
	cout << " + ";
	d.printRational();
	x = c.addition( d );
	cout << " = ";
	x.printRational();
	cout << '\n';
	x.printRational();
	cout << " = ";
	x.printRationalAsFloating();
	cout << "\nExplicit addition result: "
		<< ( ( double(num1)/den1 ) + ( double(num2)/den2 ) )
        << endl << endl;

	c.printRational();
	cout << " - ";
	d.printRational();
	x = c.subtraction( d );
	cout << " = ";
	x.printRational();
	cout << '\n';
	x.printRational();
	cout << " = ";
	x.printRationalAsFloating();
	cout << "\nExplicit subtraction result: "
        << ( ( double(num1)/den1 ) - ( double(num2)/den2 ) )
        << endl << endl;

  c.printRational();
	cout << " x ";
	d.printRational();
	x = c.multiplication( d );
	cout << " = ";
	x.printRational();
	cout << '\n';
	x.printRational();
	cout << " = ";
	x.printRationalAsFloating();
	cout << "\nExplicit multiplication result: "
        << ( ( double(num1)/den1 ) * ( double(num2)/den2 ) )
        << endl << endl;

    c.printRational();
	cout << " / ";
	d.printRational();
	x = c.division( d );
	cout << " = ";
	x.printRational();
	cout << '\n';
	x.printRational();
	cout << " = ";
	x.printRationalAsFloating();
	cout << "\nExplicit division result: "
        << ( ( double(num1)/den1 ) / ( double(num2)/den2 ) )
        << endl << endl;

    return 0;
}
