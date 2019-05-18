/*
 * DayOfYear.cpp
 *
 *  Created on: Apr 3, 2019
 *      Author: amikh
 *
 *  This program converts an integer 1-365 that represents
 *  a day of the year into month/day form.
 */


#include <iostream>
using namespace std;

//Constant integers to represent the first day of each month out of 365
const int FEB = 32;
const int MAR = 60;
const int APR = 91;
const int MAY = 121;
const int JUN = 152;
const int JUL = 182;
const int AUG = 213;
const int SEP = 244;
const int OCT = 274;
const int NOV = 305;
const int DEC = 335;

// The error is used to initialize the dayOfYear variable when
// the input month/day are invalid.
const int ERROR = 0;

class DayOfYear
{
private:
	int dayOfYear;

public:
	DayOfYear(int dayOfYear = 1)
{
		// Checks for valid input
		if(dayOfYear > 0 && dayOfYear < 366)
		{
			this -> dayOfYear = dayOfYear;
		}
		else
		{
			// If the input is invalid, the program closes.
			this -> dayOfYear = ERROR;
			cout << "Invalid input, program exiting.";
			exit(0);
		}
}
	// Mutator function to modify dayOfYear
	void setDayOfYear(int dayOfYear)
	{
		this -> dayOfYear = dayOfYear;
	}

	// Accessor function to return dayOfYear
	int getDayOfYear()
	{
		return this-> dayOfYear;
	}

	// Print function uses the first day of each month to print out
	// the day and month values of the dayOfYear
	void print()
	{
		/*
		 * Each if statement checks to see if the input is less than
		 * the following month and greater than or equal to the current
		 * current month. Then the number of days until the first of that
		 * month are subtracted (first of month plus 1) from the input.
		 */
		if (this -> dayOfYear < FEB)
		{
			cout << "January " << this -> dayOfYear; //use cout??
		}
		if ((this -> dayOfYear < MAR) && (this -> dayOfYear >= FEB))
		{
			cout << "February " << this -> dayOfYear - FEB + 1;
		}
		if ((this -> dayOfYear < APR) && (this -> dayOfYear >= MAR))
		{
			cout << "March " << this -> dayOfYear - MAR + 1;
		}
		if ((this -> dayOfYear < MAY) && (this -> dayOfYear >= APR))
		{
			cout << "April " << this -> dayOfYear - APR + 1;
		}
		if ((this -> dayOfYear < JUN) && (this -> dayOfYear >= MAY))
		{
			cout << "May " << this -> dayOfYear - MAY + 1;
		}
		if ((this -> dayOfYear < JUL) && (this -> dayOfYear >= JUN))
		{
			cout << "June " << this -> dayOfYear - JUN + 1;
		}
		if ((this -> dayOfYear < AUG) && (this -> dayOfYear >= JUL))
		{
			cout << "July " << this -> dayOfYear - JUL + 1;
		}
		if ((this -> dayOfYear < SEP) && (this -> dayOfYear >= AUG))
		{
			cout << "August " << this -> dayOfYear - AUG + 1;
		}
		if ((this -> dayOfYear < OCT) && (this -> dayOfYear >= SEP))
		{
			cout << "September " << this -> dayOfYear - SEP + 1;
		}
		if ((this -> dayOfYear < NOV) && (this -> dayOfYear >= OCT))
		{
			cout << "October " << this -> dayOfYear - OCT + 1;
		}
		if ((this -> dayOfYear < DEC) && (this -> dayOfYear >= NOV))
		{
			cout << "November " << this -> dayOfYear - NOV + 1;
		}
		if (this -> dayOfYear >= DEC)
		{
			cout << "December " << this -> dayOfYear - DEC + 1;
		}
	}

};

int main()
{
	int input;

	cout << "Please input an integer 1 to 365 representing a day of the year: ";
	cin >> input;

	// Take user input and initialize an object with it.
	DayOfYear test1(input);
	test1.print();

	return 0;
}

