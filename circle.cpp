/*
 * circle.cpp
 *
 *  Created on: Mar 5, 2019
 *      Author: amikh
 *
 *	This program demonstrates both default and argumented constructors
 *	using Circle objects. It also demonstrates arrays of objects being
 *	initialized with either the default or argumented constructors.
 */

class Circle
{
private:
	double radius;
	constexpr static double PI = 3.14;
public:

	Circle() //Default constructor
	{

	}
	Circle(double radius) //Argumented constructor, initializes radius
	{
		this -> radius = radius;
	}
	double getRadius() //Returns radius
	{
		return radius;
	}
	void setRadius(double radius) //Mutates/changes radius
	{
		this -> radius = radius;
	}
	double getArea() //Calculates area of the circle
	{
		return (this -> radius * this -> radius * PI);
	}
};

#include <iostream>
using namespace std;

int main()
{
	double radius;

	cout << "Please enter a radius: ";
	cin >> radius;
	// Has user input a radius for the argumented constructor circle.

	Circle defConstr;
	cout << "Default constructor circle area: "
			<< defConstr.getArea() << endl;

	Circle argConstr(radius); // Initializes circle object with user input.
	cout << "Argumented constructor circle area: "
			<< argConstr.getArea() << endl;

	const int MAX_OBJECTS = 5;

	//Creates 5 circle objects with default constructor
	Circle defCollection[MAX_OBJECTS];

	//Creates 5 circle objects with argumented constructor
	Circle argCollection[MAX_OBJECTS] = { 12, 7, 9, 14, 18 };

	for (int index = 0; index < MAX_OBJECTS; index++)
	{
		// Prints out the area of the objects in the circle arrays.
		cout << endl << "Default constructor circle " << index + 1
				<< " area: " << defCollection[index].getArea() << endl;
		cout << "Argumented constructor circle " << index + 1
				<< " area: " << argCollection[index].getArea();
	}

	return 0;
}
