/*
 * FeetInches.cpp
 *
 *  Created on: Apr 9, 2019
 *      Author: amikh
 *
 *   A program which demonstrates the FeetInches class by
 *   using comparisons of an input height to Ami's height
 *   and the sum of both heights compared to an elephant's.
 */


#include <cstdlib>  // Needed for abs()

#include <iostream>
using namespace std;

class FeetInches;	// Forward Declaration

// The FeetInches class holds distances or measurements
// expressed in feet and inches.

class FeetInches
{
private:
   int feet;        // To hold a number of feet
   int inches;      // To hold a number of inches

   //************************************************************
   // Definition of member function simplify. This function     *
   // checks for values in the inches member greater than       *
   // twelve or less than zero. If such a value is found,       *
   // the numbers in feet and inches are adjusted to conform    *
   // to a standard feet & inches expression. For example,      *
   // 3 feet 14 inches would be adjusted to 4 feet 2 inches and *
   // 5 feet -2 inches would be adjusted to 4 feet 10 inches.   *
   //************************************************************
   void simplify()
   {
	   if (this -> inches >= 12)
	   {
		   this -> feet += (this -> inches / 12);
		   this -> inches = (this -> inches % 12);
	   }
	   else if (this -> inches < 0)
	   {
		   this -> feet -= ((abs(this -> inches) / 12) + 1);
		   this -> inches = 12 - (abs(this -> inches) % 12);
	   }
   }

public:
   // Constructor
	FeetInches(int f = 0, int i = 0)
		{
		this -> feet = f;
		this -> inches = i;
		simplify();
		}

	// Copy constructor
	FeetInches(FeetInches &other)
	{
		this -> feet = other.feet;
		this -> inches = other.inches;
	}

   // Mutator functions
	void setFeet(int f)
		{
		this -> feet = f;
		}

	void setInches(int i)
		{
		this -> inches = i;
		  simplify();
		}

   // Accessor functions
	int getFeet() const
		{
		return this -> feet;
		}

	int getInches() const
		{
		return this -> inches;
		}

   // Overloaded operator functions

	//**********************************************
	// Overloaded binary + operator.               *
	//**********************************************

	FeetInches operator + (const FeetInches &right)
	{
		FeetInches temp;

		temp.feet = this -> feet + right.feet;
		temp.inches = this -> inches + right.inches;
		temp.simplify();
		return temp;
	}

	//**********************************************
	// Overloaded binary - operator.               *
	//**********************************************

	FeetInches operator - (const FeetInches &right)
	{
		FeetInches temp;

		temp.inches = this -> inches - right.inches;
		temp.feet = this -> feet - right.feet;
		temp.simplify();
		return temp;
	}

	//*************************************************************
	// Overloaded prefix ++ operator. Causes the inches member to *
	// be incremented. Returns the incremented object.            *
	//*************************************************************

	FeetInches operator ++ ()
	{
		++inches;
		simplify();
		return *this;
	}

	//***************************************************************
	// Overloaded postfix ++ operator. Causes the inches member to  *
	// be incremented. Returns the value of the object before the   *
	// increment.                                                   *
	//***************************************************************

	FeetInches operator ++ (int)
	{
		FeetInches temp(this -> feet, this -> inches);

		this -> inches++;
		simplify();
		return temp;
	}

	/* Overloaded * operator, allows two objects to be multiplied
	 * together. Returns an object of FeetInches.
	 */
	FeetInches operator * (FeetInches & other)
	{
		FeetInches product;
		product.feet = this -> feet * other.feet;
		product.inches = this -> inches * other.inches;
		return product;
	}

	//************************************************************
	// Overloaded > operator. Returns true if the current object *
	// is set to a value greater than that of right.             *
	//************************************************************

	bool operator > (const FeetInches &right)
	{
		bool status;

		if (this -> feet > right.feet)
			status = true;
		else if (this -> feet == right.feet && this -> inches > right.inches)
			status = true;
		else
			status = false;

		return status;
	}

	//************************************************************
	// Overloaded < operator. Returns true if the current object *
	// is set to a value less than that of right.                *
	//************************************************************

	bool operator < (const FeetInches &right)
	{
		bool status;

		if (this -> feet < right.feet)
			status = true;
		else if (this -> feet == right.feet && this -> inches < right.inches)
			status = true;
		else
			status = false;

		return status;
	}

	//*************************************************************
	// Overloaded == operator. Returns true if the current object *
	// is set to a value equal to that of right.                  *
	//*************************************************************

	bool operator == (const FeetInches &right)
	{
		bool status;

		if (this -> feet == right.feet && this -> inches == right.inches)
			status = true;
		else
			status = false;

		return status;
	}

	//*************************************************************
	// Overloaded <= operator. Returns true if the current object *
	// is set to a value less than or equal to that of right.     *
	//*************************************************************

	bool operator <= (const FeetInches &right)
	{
		bool status;

		if (this -> feet <= right.feet && this -> inches <= right.inches)
			status = true;
		else
			status = false;

		return status;
	}

	//*************************************************************
	// Overloaded >= operator. Returns true if the current object *
	// is set to a value greater than or equal to that of right.  *
	//*************************************************************

	bool operator >= (const FeetInches &right)
	{
		bool status;

		if (this -> feet <= right.feet && this -> inches <= right.inches)
			status = true;
		else
			status = false;

		return status;
	}

	//*************************************************************
	// Overloaded != operator. Returns true if the current object *
	// is not set to a value equal to that of right.			  *
	//*************************************************************
	bool operator != (const FeetInches &right)
	{
		bool status;

		if (this -> feet == right.feet && this -> inches == right.inches)
			status = false;
		else
			status = true;

		return status;
	}

	// Conversion functions
	//*************************************************************
	// Conversion function to convert a FeetInches object         *
	// to a double.                                               *
	//*************************************************************

	operator double()
	{
		double temp = this -> feet;

		temp += (this -> inches / 12.0);
		return temp;
	}

	//*************************************************************
	// Conversion function to convert a FeetInches object         *
	// to an int.                                                 *
	//*************************************************************

	operator int()
	{
		return this -> feet;
	}

   // Friends

	//********************************************************
	// Overloaded << operator. Gives cout the ability to     *
	// directly display FeetInches objects.                  *
	//********************************************************
	friend ostream &operator << (ostream &strm, const FeetInches &obj)
	{
		strm << obj.feet << " feet, " << obj.inches << " inches";
		return strm;
	}

	//********************************************************
	// Overloaded >> operator. Gives cin the ability to      *
	// store user input directly into FeetInches objects.    *
	//********************************************************
	friend istream &operator >> (istream &strm, FeetInches &obj)
	{
		// Prompt the user for the feet.
		cout << "Feet: ";
		strm >> obj.feet;

		// Prompt the user for the inches.
		cout << "Inches: ";
		strm >> obj.inches;

		// Normalize the values.
		obj.simplify();

		return strm;
	}
};




//ostream &operator<<(ostream &strm, const FeetInches &obj)

//istream &operator >> (istream &strm, FeetInches &obj)


int main()
{
	cout << "Please enter your height: " << endl;
	FeetInches inputHeight;
	FeetInches amiHeight (5, 2);

	cin >> inputHeight;

	FeetInches difference;

	// Compares the input height with Ami's height.
	if (inputHeight > amiHeight)
	{
		FeetInches amiHeightCopy = amiHeight;
		while (inputHeight != amiHeightCopy)
		{
			++amiHeightCopy;
			++difference;
		}
		cout << "You are " << difference << " taller than Ami." << endl;
	}
	if (inputHeight == amiHeight)
	{
		cout << "You are the same height as Ami!" << endl;
	}
	if (inputHeight < amiHeight)
	{
		FeetInches inputHeightCopy = inputHeight;
		while (inputHeightCopy != amiHeight)
		{
			++inputHeightCopy;
			++difference;
		}
		cout << "You are " << difference << " shorter than Ami!" << endl;
	}

	FeetInches bothHeights;
	bothHeights = inputHeight + amiHeight;
	FeetInches elephantHeight (11, 0);

	// Compares the sum of the heights to an elephant's height and prints
	// the appropriate message.
	if (bothHeights > elephantHeight)
	{
		cout << "Together, you two are taller than an average elephant!" << endl;
	}
	if (bothHeights == elephantHeight)
	{
		cout << "Together, you two are the same height as an average elephant!" << endl;
	}
	if (bothHeights < elephantHeight)
	{
		cout << "Together, you two are still shorter than an average elephant." << endl;
	}

	return 0;
}
