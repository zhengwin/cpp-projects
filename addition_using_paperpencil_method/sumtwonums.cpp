#include <iostream>
#include "sumtwonums.h"
using namespace std;


//This function takes in a positive integer of 20 or less digits. This is stored in a char array
//Only char integers between 0-9 are accepted. 
//Leading zeros e.g. "000123" is treated as "123"
//Multiple zeros e.g. "0000" is stored as just "0"
void get_input( char char_num[], const int MAX_DIGITS, int &digits, int &count_leading_zeros ) {
	int i = 0;
	bool valid_characters = true;
	bool leading_zeros = false;
	
	do {
		valid_characters = true;
		leading_zeros = false;
		count_leading_zeros = 0;
		digits = 0;
		
		cout << "Enter a positive integer\n";
		cin.get(char_num, MAX_DIGITS);
		cin.ignore();
		cout << "you entered: " << char_num << endl << endl;
		
		if ( char_num[0] == 'e' || char_num[0] == 'E' ) {
			cout << "Exiting...\n\n";
			exit(1);
		}
		
		if ( char_num[0] == '0' )
			leading_zeros = true;

		// iterates through char array. '\0' signifies endpoint
		for ( i = 0; char_num[i] != '\0'; i++ ) { 
			
			//converts char to int. Checks for invalid characters.
			if ( ( char_num[i] - '0' ) < 0 || ( char_num[i] - '0' ) > 9 ) { 
				valid_characters = false;
				cout << char_num[i] << endl;
			}
			
			//Count # of leading zeros
			if ( leading_zeros == true && char_num[i] == '0' ) { 
				count_leading_zeros++;
			} else {
				leading_zeros = false;
			}
			
			digits++;
		}
		
		if ( valid_characters == false || digits > 20 ) 
			cout << "That was an invalid input. Try Again.\n\n";
		
	} while( valid_characters == false || digits > 20 );
	
}

//This function converts the char array into an int array while reversing the digits
void convert_and_reverse( char char_num[], int int_num[], int &digits, int count_leading_zeros ) {
	int i = 0;
	int n = 0;
	
	if ( count_leading_zeros == digits ) { // Multiple 0s are stored as a single 0
		digits = 1;
	} else {
		// Convert to int array and reverse it to aid in addition function later
		for ( i = digits - 1, n = 0; i >= count_leading_zeros; i--, n++ ) {
			int_num[n] = char_num[i] - '0';
		}
		
		digits -= count_leading_zeros; // The true number of digits is total digits - # of leading zeros
	}

}

// This function will display the two numbers the user entered
void display_numbers( int int_num1[], int int_num2[], int &digits1, int &digits2 ) {
	int i = 0;
	
	cout << "Number 1: ";
	for ( i = digits1 - 1; i >= 0; i-- ) {
		cout << int_num1[i];
	}
	cout << endl;
	
	cout << "Number 2: ";
	for ( i = digits2 - 1; i >= 0; i-- ) {
		cout << int_num2[i];
	}
	cout << endl << endl;
	
}

//This function adds the two numbers using the paper and pencil method. Sum is stored in an int array
void sum_two_nums( int int_num1[], int int_num2[], int sum[], int digits1, int digits2, int &digits_sum ) {
	int n = 0;
	int columns = 0;
	int column_sum = 0; // sum of two numbers in a column
	int first_digit = 0; //1st digit of the column sum
	int second_digit = 0; //2nd digit of the column sum
	digits_sum = 0;
	
	//# of Number of columns the addition will have. E.g. "329 + 99" will have 3 columns since the largest number is 329
	if ( digits1 >= digits2 ) {
		columns = digits1;
	} else {
		columns = digits2;
	}
	
	//Addition using paper and pencil method
	for ( n = 0; n <= columns; n++ ) {
		column_sum = int_num1[n] + int_num2[n];
		
		if ( column_sum > 9 ) { // If column sum is two digits, carry the 1st digit to subsequent column
			second_digit = column_sum % 10;
			
			//Grab the first digit of the column sum
			first_digit = column_sum;
			while( first_digit >= 10 ) {
				first_digit /= 10;
			}
			
			//Write down the 2nd digit and the 1st digit will be carried to the following column
			sum[n] = second_digit;
			int_num1[n + 1] = int_num1[n + 1] + first_digit;
		} else {
			sum[n] = column_sum;
		}
		
		digits_sum++;
	}
	
	cout << endl;
	
}

//This function will reverse the digits of the sum, and display it using commas
void display_sum( int sum[], int digits_sum ) {
	int n = 0;
	int i = 0;
	int temp = 0;
	int triples = 0;
	int counter = 0;
	int first_comma = 0;
	
	if ( sum[digits_sum - 1] == 0 ) // If the sum has an extra 0 at the end, digits--
		digits_sum--;
	
	if ( digits_sum > 20 ){
		cout << "SUMMATION OVERFLOW ERROR" << endl << endl;
		return;
	}
	
	for ( i = 0, counter = 1; i < digits_sum; i++, counter++ ) {
		if ( counter % 3 == 0 ) {
			triples++;
		}
	}
	
	//Reverse the digits of the sum
	for ( i = 0, n = digits_sum - 1; i <= (digits_sum / 2) - 1; i++, n-- ) {
		temp = sum[n]; 
		sum[n] = sum[i];
		sum[i] = temp;
	} 
	
	cout << "SUM: ";
	
	if ( digits_sum % 3 == 0 ) {
		for ( i = 0, counter = 1; i < digits_sum; i++, counter++ ) {
			cout << sum[i];
			if ( counter % 3 == 0 && i != digits_sum - 1 )
				cout << ",";
		}
		
	} else if ( sum[0] == 0) {
		cout << sum[0];
		
	} else {
		first_comma = digits_sum - triples * 3;
		for ( i = 0; i < first_comma ; i++ ) {
			cout << sum[i];
			if ( i == first_comma - 1 ) {
				cout << ",";
			}
		}
		
		if ( first_comma == 2 ) {
			temp = digits_sum - first_comma + 1;
		} else {
			temp = digits_sum - first_comma;
		}
		
		for ( i = first_comma, counter = 1; i <= temp; i++, counter++ ) {
			cout << sum[i];
			if ( counter % 3 == 0 && i < temp )
				cout << ",";
		}
	}
	
	cout << endl << endl;
}

