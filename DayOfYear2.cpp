/*
 * DayOfYear2.cpp
 *
 *  Created on: Apr 3, 2019
 *      Author: amikh
 *
 *   This is a modified version of Day of Year which can take month and
 *   day of month as arguments of the constructor. It also has overloaded
 *   prefix and postfix ++ and -- operators.
 */

#include <iostream>
#include <string>
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
		// This checks for valid input.
		if(dayOfYear > 0 && dayOfYear < 366)
		{
			this -> dayOfYear = dayOfYear;
		}
		else
		{
			// If the input is invalid, the program closes.
			this -> dayOfYear = ERROR;
			cout << "Invalid input. Program exiting.";
			exit (0);
		}
}
	DayOfYear(string month = "", int dayOfMonth = 1)
	{
		// Checks number of days in month for valid input.
		if(dayOfMonth > 31 || dayOfMonth < 1)
		{
			this -> dayOfYear = ERROR;
		}
		else
		{
			/* Every if/else if statement checks the number of days
			 * (if the number of days in each month is not 31), and
			 * assigns the dayOfYear based on the value of the first
			 * day of each month (out of 365).
			 */
			if (month == "January")
			{
				this -> dayOfYear = dayOfMonth;
			}
			else if (month == "February")
			{
				if (dayOfMonth > 28)
				{
					this -> dayOfYear = ERROR;
				}
				else
				{
					this -> dayOfYear = (dayOfMonth + FEB - 1);
				}
			}
			else if (month == "March")
			{
				this -> dayOfYear = (dayOfMonth + MAR - 1);
			}
			else if (month == "April")
			{
				if (dayOfMonth > 30)
				{
					this -> dayOfYear = ERROR;
				}
				else
				{
					this -> dayOfYear = (dayOfMonth + APR - 1);
				}
			}
			else if (month == "May")
			{
				this -> dayOfYear = (dayOfMonth + MAY - 1);
			}
			else if (month == "June")
			{
				if (dayOfMonth > 30)
				{
					this -> dayOfYear = ERROR;
				}
				else
				{
					this -> dayOfYear = (dayOfMonth + JUN - 1);
				}
			}
			else if(month == "July")
			{
				this -> dayOfYear = (dayOfMonth + JUL - 1);
			}
			else if (month == "August")
			{
				this -> dayOfYear = (dayOfMonth + AUG - 1);
			}
			else if (month == "September")
			{
				if (dayOfMonth > 30)
				{
					this -> dayOfYear = ERROR;
				}
				else
				{
					this -> dayOfYear = (dayOfMonth + SEP - 1);
				}
			}
			else if (month == "October")
			{
				this -> dayOfYear = (dayOfMonth + OCT - 1);
			}
			else if (month == "November")
			{
				if (dayOfMonth > 30)
				{
					this -> dayOfYear = ERROR;
				}
				else
				{
					this -> dayOfYear = (dayOfMonth + NOV - 1);
				}
			}
			else if (month == "December")
			{
				this -> dayOfYear = (dayOfMonth + DEC - 1);
			}
			else
			{
				this -> dayOfYear = ERROR;
			}
		}

		if (this -> dayOfYear == ERROR)
		{
			/* At the end of initializing data, if the dayOfYear
			 * was initialized to be an error, then the program exits.
			 */
			cout << "Input error, day or month are invalid arguments. "
					<< "Program exiting.";
			exit(0);
		}
	}

	// Overloaded prefix and postfix ++, increments
	// dayOfYear unless it's the last day of the year
	// in which case it sets it to the first of the year.
	const DayOfYear operator++()
		{
		if(dayOfYear == 365)
			this -> dayOfYear = 1;
		else
			this -> dayOfYear += 1;
		return DayOfYear(this -> dayOfYear);
		}

	const DayOfYear operator++(int)
		{
		DayOfYear temp(this -> dayOfYear);
		if(dayOfYear == 365)
			this -> dayOfYear = 1;
		else
			this -> dayOfYear += 1;
		return temp;
		}

	// Overloaded prefix and postfix --, decrements
	// dayOfYEar unless it's the first day of the year,
	// in which case it sets it to the last of the year.
	const DayOfYear operator--()
		{
		if(dayOfYear == 1)
			this -> dayOfYear = 365;
		else
			this -> dayOfYear -= 1;

		return DayOfYear(this -> dayOfYear);
		}

	const DayOfYear operator--(int)
		{
		DayOfYear temp(this -> dayOfYear);
		if(dayOfYear == 1)
			this -> dayOfYear = 365;
		else
			this -> dayOfYear -= 1;
		return temp;
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
			cout << "January " << this -> dayOfYear;
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
	cout << "First day of the year: ";
	DayOfYear first("January", 1);
	first.print();

	cout << endl << "First day decremented: ";
	first--;
	first.print();

	cout << endl << "Last day of the year: ";
	DayOfYear last(365);
	last.print();

	cout << endl << "Last day incremented: ";
	last++;
	last.print();

	return 0;
}
