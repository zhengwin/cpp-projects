#include <iostream>
#include "sumtwonums.h"
using namespace std;

const int MAX_DIGITS = 200;

int main ( ) {
	int i = 0;
	char input = '0';
	char char_num1[MAX_DIGITS];
	char char_num2[MAX_DIGITS];
	int count_leading_zeros1 = 0;
	int count_leading_zeros2 = 0;
	int int_num1[MAX_DIGITS];
	int int_num2[MAX_DIGITS];
	int sum[MAX_DIGITS];
	int digits1 = 0;
	int digits2 = 0;
	int digits_sum = 0;
	
	while ( input != 'e' && input != 'E' ) {
		
		for ( i = 0; i < MAX_DIGITS; i++ ) { // initialize the int arrays
			char_num1[i] = '0';
			char_num2[i] = '0';
			int_num1[i] = 0;
			int_num2[i] = 0;
			sum[i] = 0;
		}
		
		cout << "Enter E to exit anytime\n\n";
		
		cout << "--Enter the first number--\n";
		get_input( char_num1, MAX_DIGITS, digits1, count_leading_zeros1 );
		cout << "--Enter the second number--\n";
		get_input( char_num2, MAX_DIGITS, digits2, count_leading_zeros2 );
		
		convert_and_reverse( char_num1, int_num1, digits1, count_leading_zeros1 );
		convert_and_reverse( char_num2, int_num2, digits2, count_leading_zeros2 );
		
		display_numbers( int_num1, int_num2, digits1, digits2 );
	
		sum_two_nums( int_num1, int_num2, sum, digits1, digits2, digits_sum );
		
		display_sum( sum, digits_sum );
		
		cout << "Enter any character to continue. Type E to Exit.\n";
		
		cin >> input;
		cin.ignore();
		cout << "you entered: " << input << endl << endl;
		
	} 
	
	return 0;
}
