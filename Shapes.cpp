/*
 * Shapes.cpp
 *
 *  Created on: Apr 25, 2019
 *      Author: amikh
 */




#include <iostream>
using namespace std;

const double PI = 3.14159;

// Pure virtual/abstract class BasicShape.
class BasicShape
{
private:
	double area;

public:
	// Accessor function for area.
	double getArea()
	{
		return this -> area;
	}

	// Mutator function for area.
	void setArea(double area)
	{
		this -> area = area;
	}

	// Virtual function.
	virtual void calcArea() = 0;
};

// Circle class derived from BasicShape.
class Circle: public BasicShape
{
private:
	long int centerX;
	long int centerY;
	double radius;

public:
	// Default argumented constructor to initialize values.
	Circle(long int centerX = 0, long int centerY = 0, double radius = 0.0)
	{
		this -> centerX = centerX;
		this -> centerY = centerY;
		this -> radius = radius;
		calcArea();
	}

	//Accessor functions to return x and y coordinates of the center.
	long int getCenterX()
	{
		return this -> centerX;
	}

	long int getCenterY()
	{
		return this -> centerY;
	}

	// Overriden function to calculate area and change the stored value.
	void calcArea()
	{
		double area = (PI * this -> radius * this -> radius);
		BasicShape::setArea(area);
	}

};

// Rectangle class derived from BasicShape.
class Rectangle: public BasicShape
{
private:
	long int width;
	long int length;

public:
	// Default argumented constructor to initialize values.
	Rectangle(long int width = 0, long int length = 0)
	{
		this -> width = width;
		this -> length = length;
		calcArea();
	}

	// Accessor functions for width and length.
	long int getWidth()
	{
		return this -> width;
	}

	long int getLength()
	{
		return this -> length;
	}

	// Overridden function to calculate area and change the stored value.
	void calcArea()
	{
		double area = (this -> length * this -> width);
		BasicShape::setArea(area);
	}

};

int main()
{
	long int xCoordinate, yCoordinate;
	double radius;

	// Take user input for the circle values.
	cout << "Enter the x-coordinate for the center of a circle: ";
	cin >> xCoordinate;
	cout << "Enter the y-coordinate for the center of a circle: ";
	cin >> yCoordinate;
	cout << "Enter the radius of a circle: ";
	cin >> radius;

	// Create circle object based on user input.
	Circle circle(xCoordinate, yCoordinate, radius);

	// Print area of the circle object.
	cout << endl << "Area of the circle: " << circle.getArea() << endl
			<< endl;

	// Take user input for the rectangle values.
	long int length, width;
	cout << "Enter the length of a rectangle: ";
	cin >> length;
	cout << "Enter the width of a rectangle: ";
	cin >> width;

	// Create rectangle object based on user input.
	Rectangle rectangle(length, width);

	// Print area of the rectangle object.
	cout << endl << "Area of the rectangle: " << rectangle.getArea() << endl;

	return 0;
}
