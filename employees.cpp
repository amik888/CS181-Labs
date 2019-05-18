/*
 * 2.cpp
 *
 *  Created on: Mar 10, 2019
 *      Author: amikh
 *
 *	This program prints out employee information.
 */



#include <iostream>
using namespace std;

class Employee
{
private:
	string name;
	int idNumber;
	string department;
	string position;

public:
	Employee(string name, int idNumber, string department, string position)
	{
		// Argumented constructor that takes input for all 4 variables.
		this -> name = name;
		this -> idNumber = idNumber;
		this -> department = department;
		this -> position = position;
	}
	Employee(string name, int idNumber)
	{
		// Argumented constructor that only takes name and ID number.
		this -> name = name;
		this -> idNumber = idNumber;
	}
	Employee()
	{
		// Default constructor.
	}

	void setName(string name)
	{
		// Assigns user-input string to object's name.
		this -> name = name;
	}
	void setIdNumber(int idNumber)
	{
		// Assigns user-input integer to object's ID number.
		this -> idNumber = idNumber;
	}
	void setDepartment(string department)
	{
		// Assigns user-input string to object's department.
		this -> department = department;
	}
	void setPosition(string position)
	{
		// Assigns user-input string to object's position.
		this -> position = position;
	}

	// Accessor functions that return the value stored in the object's memory.
	string getName()
	{
		return this -> name;
	}
	int getIdNumber()
	{
		return this -> idNumber;
	}
	string getDepartment()
	{
		return this -> department;
	}
	string getPosition()
	{
		return this -> position;
	}
};

void printInfo(Employee member);

int main ()
{
	// Initializes data for the three employees specified.
	Employee susan("Susan Meyers", 47899, "Accounting", "Vice President");
	Employee mark("Mark Jones", 39119, "IT", "Programmer");
	Employee joy("Joy Rogers", 81774, "Manufacturing", "Engineer");

	// Prints out each employee's information.
	printInfo(susan);
	cout << endl;
	printInfo(mark);
	cout << endl;
	printInfo(joy);

	return 0;
}

void printInfo(Employee member)
{
	// Prints the information of the employees using the accessor functions.
	cout << "Name: " << member.getName() << endl
			<< "ID Number: " << member.getIdNumber() << endl
			<< "Department: " << member.getDepartment() << endl
			<< "Position: " << member.getPosition() << endl;
}
