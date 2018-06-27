#include <iostream>

#ifndef SUM_TWO_NUMS_H
#define SUM_TWO_NUMS_H

void get_input( char char_num[], const int MAX_DIGITS, int &digits, int &count_leading_zeros );

void convert_and_reverse( char char_num[], int int_num[], int &digits, int count_leading_zeros );

void display_numbers( int int_num1[], int int_num2[], int &digits1, int &digits2 );

//void display_numbers( int int_num[], int &digits );

void sum_two_nums( int int_num1[], int int_num2[], int sum[], int digits1, int digits2, int &digits_sum );

void display_sum( int sum[], int digits_sum );

#endif
