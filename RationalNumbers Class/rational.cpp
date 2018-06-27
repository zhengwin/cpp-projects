#include "rational.h"
using namespace std;

Rational::Rational()
: num( 0 ), den( 1 )
{
}

Rational::Rational( const int n, const int d ) 
: num( n ), den( d ) 
{	
	if ( den == 0 ) {
		cout << "Denominator 0 ERROR. EXITTING" << endl;
		exit(1);
	}
	reduction();
}

void Rational::reduction()
{
	int hcf = 0; //highest common factor
	
	for ( int i = 1; i <= abs( num ) && i <= abs( den ); i++ ) 
	{
		if ( abs( num ) % i == 0 && abs( den ) % i == 0 )
			hcf = i;
	}
	
	num /= hcf;
	den /= hcf;
}

void Rational::printRational( ) const
{
	cout << num << "/" << den;
}

void Rational::printRationalAsFloating() 
{
	cout << static_cast<float>( num ) / den;
}

Rational Rational::addition( const Rational &d )
{
	Rational temp;
	temp.num = num * d.den + d.num * den;
	temp.den = den * d.den;
	
	temp.reduction();
	
	return temp; 
}

Rational Rational::subtraction( const Rational &d )
{
	Rational temp;
	temp.num = num * d.den - d.num * den;
	temp.den = den * d.den;
	
	temp.reduction();
	
	return temp;
}

Rational Rational::multiplication( const Rational &d )
{
	Rational temp;
	temp.num = num * d.num;
	temp.den = den * d.den;
	
	temp.reduction();
	
	return temp;
}

Rational Rational::division( const Rational &d )
{
	Rational temp;
	temp.num = num * d.den;
	temp.den = den * d.num;
	
	temp.reduction();
	
	return temp;
}
