// ******************************
// Student Name: Jackson Zheng
// Student Number: 20672834
//
// SYDE 121 Lab: 005 Assignment: 002
//
// Filename: Lab0502.cpp
// Date submitted: 2017-10-16
//
// I hereby declare that this code, submitted
// for credit for the course SYDE121, is a product
// of my own efforts. This coded solution has
// not been plagiarized from other sources
// as not been knowingly plagiarzed by others.
// *******************************

// This program allows the user to calculate the weekly salary for each employee
// Types of employees: Managers, Hourly Workers, Commission Workers, and Pieceworkers
// Salary of manager: weekly salary
// Salary of hourly workers: hourly wage for first 40 hours, + 1.5 x hourly wage x overtime hours worked
// salary of comission workers: $250 + 5.7% of weekly sales
// Salary of pieceworkers: Fixed amount of money for each item they produce
// Output the total number of employees and total salary for each type of employee
// Output Overrall totals

#include <iostream>
#include <iomanip>
using namespace std;

int main ( ) {

	char input = ' ';
	double individual_pay = 0;

	double managers = 0;
	double manager_count = 0;

	double hourly_workers = 0;
	double hourly_workers_count = 0;
	double hourly_wage = 0;
	double hours_worked = 0;

	double commission = 0;
	double weekly_sales = 0;
	double commission_count = 0;

	double pieceworkers = 0;
	double pieceworkers_count = 0;

	double fixed_amount = 0;
	double num_items = 0;

	double total_employees = 0;
	double total_salary = 0;

	cout.setf(ios::fixed);
	cout.precision(2);

	cout << "*** Weekly Salary Calculator ***" << endl << endl;

	cout << "Enter the corresponding letter of the type of employee" << endl << endl;

	while ( input != 'E' && input != 'e') { // User presses 'E' or 'e' when they are finished adding employees
		cout << "M - Managers\nH - Hourly workers\nC - Commission\nP - Pieceworkers\n\n";
		cout << "Enter \'E\' when you are finished adding employees " << endl << endl;
		cout << "_____________________________________________________________" << endl << endl;

		cin >> input;
		cout << "you entered: " << input << endl << endl;

		switch ( input ) {
			case 'M':
			case 'm':
				// Weekly salary for managers

				manager_count += 1;

				cout << endl << "Manager #" << manager_count << endl << endl;
				cout << "Enter the weekly salary" << endl;
				cin >> individual_pay;
				cout << "you entered: " << individual_pay << endl << endl;

				managers += individual_pay; // Total salary for managers

				cout << "Weekly salary of Manager #" << manager_count << " : " << individual_pay << endl;
				cout << "Weekly salary of all managers: " << managers << endl;
				break;

			case 'H':
			case 'h':
				// Weekly salary for hourly workers

				hourly_workers_count += 1;

				cout << endl << "Hourly Worker #" << hourly_workers_count << endl << endl;
				cout << "Enter the hourly wage" << endl;
				cin >> hourly_wage;
				cout << "you entered: " << hourly_wage << endl << endl;

				cout << "Enter the number of hours worked" << endl;
				cin >> hours_worked;

				if ( hours_worked > 40 ) {
					individual_pay = hourly_wage * 40 + 1.5 * hourly_wage * ( hours_worked - 40 );
				} else {
					individual_pay = hourly_wage * hours_worked;
				}

				hourly_workers += individual_pay; // total salary for hourly workers

				cout << "Weekly salary of Hourly Worker #" << hourly_workers_count << " : " << individual_pay << endl;
				cout << "Weekly salary of all Hourly Workers: " << hourly_workers << endl;
				break;

			case 'C':
			case 'c':
				// Weekly salary for commission workers

				commission_count += 1;

				cout << endl << "Commission Worker #" << commission_count << endl << endl;
				cout << "Enter the amount for gross weekly sales" << endl;
				cin >> weekly_sales;
				cout << "You entered: " << weekly_sales << endl << endl;

				individual_pay = 250 + 0.057 * weekly_sales;
				commission += individual_pay; // total salary for commission workers

				cout << "Weekly salary of Commission Worker #" << commission_count << " : " << individual_pay << endl;
				cout << "Weekly salary of all Hourly Workers: " << commission << endl;
				break;

			case 'P':
			case 'p':
				// Weekly salary for pieceworkers

				pieceworkers_count += 1;

				cout << endl << "Pieceworker #" << pieceworkers_count << endl << endl;
				cout << "Enter the fixed amount of money per item" << endl;
				cin >> fixed_amount;
				cout << "you entered: " << fixed_amount << endl << endl;

				cout << "Enter the amount of items produced" << endl;
				cin >> num_items;
				cout << "you entered: " << num_items << endl << endl;

				individual_pay = fixed_amount * num_items;
				pieceworkers += individual_pay; // total salary for pieceworkers

				cout << "Weekly salary of PieceWorker #" << pieceworkers_count << " : " << individual_pay << endl;
				cout << "Weekly salary of all Hourly Workers: " << pieceworkers << endl;
				break;

			case 'E':
			case 'e':
				cout << "Calculating Totals.." << endl;
				break;

			default:
				cout << "That is not a valid input. Try Again." << endl << endl;;

				break;
		}

		cout << endl << "*****************************************************************" << endl << endl;

		if ( input != 'e' && input != 'E' )
			cout << "Add another employee" << endl << endl;
	}

	// calculate the overall total # of employees, and overall total of salaries from all employees
	total_employees = manager_count + hourly_workers_count + commission_count + pieceworkers_count;
	total_salary = managers + hourly_workers + commission + pieceworkers;

	// Table
	// display the total # of employees, and total salary for each type of employee.

	cout << "                  " << setw(10) << "Employees" << "    " << setw(10) << "Salary " << endl;
	cout << "------------------------------------------" << endl;
	cout << setw(15) << "Managers" << setw(10) << manager_count << "    "
		 << setw(10) << managers << endl;
	cout << setw(15) << "Hourly Workers" << setw(10) << hourly_workers_count << "    "
		 << setw(10) << hourly_workers << endl;
	cout << setw(15) << "Commission" << setw(10) << commission_count << "    "
	     << setw(10) << commission << endl;
	cout << setw(15) << "Pieceworkers" << setw(10) << pieceworkers_count << "    "
	     << setw(10) << pieceworkers << endl;
	cout << "------------------------------------------" << endl;
	cout << setw(15) << "Overall Totals" << setw(10) << total_employees << "    "
	     << setw(10) << total_salary << endl;
}
