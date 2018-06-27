#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
#include <cmath>
using namespace std;

class Rational
{
public:
	Rational();
	
	Rational( const int n, const int d );
	
	//Print rational in the form a/b to the screen
	void printRational() const;
	
	//Adds two rationals together
	Rational addition( const Rational &d );
	
	//print rational in floating point form
	void printRationalAsFloating();
	
	//Subtract two rationals 
	Rational subtraction( const Rational &d );
	
	//Multiply two rationals
	Rational multiplication( const Rational &d );
	
	//Divide two rationals
	Rational division( const Rational &d );
	
private:
	int num;
	int den;
	
	void reduction();
};

#endif
