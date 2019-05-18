/*
 * Temperature.cpp
 *
 *  Created on: Mar 11, 2019
 *      Author: amikh
 *
 *  This program tells the user whether ethyl, water, or
 *  oxygen will boil or freeze at any input temperature.
 */

#include <iostream>
using namespace std;

class FreezingOrBoiling
{
private:
	double temperature;
public:
	FreezingOrBoiling(double temperature)
{
		// An argumented default constructor.
		this -> temperature = 0.0;
		this -> temperature = temperature;
}

	void setTemperature(double temperature)
	{
		// Changes temperature.
		this -> temperature = temperature;
	}
	double getTemperature()
	{
		// Returns temperature.
		return this -> temperature;
	}

	/*
	 * The bool functions check to see if the temperature is above/below
	 * the boiling/freezing points and return appropriate true/false values.
	 */
	bool isEthylFreezing()
	{
		if ((this -> temperature) > -173)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	bool isEthylBoiling()
	{
		if ((this -> temperature) < 172)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	bool isOxygenFreezing()
	{
		if ((this -> temperature) > -362)
		{
			return false;
		}
		else
		{
			return true;
		}

	}
	bool isOxygenBoiling()
	{
		if ((this -> temperature) < -306)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	bool isWaterFreezing()
	{
		if ((this -> temperature) > 32)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	bool isWaterBoiling()
	{
		if ((this -> temperature) < 212)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
};

void printInfo(FreezingOrBoiling input);

int main()
{
	double temperature;
	cout << "Please enter a temperature: ";
	cin >> temperature;

	FreezingOrBoiling instance(temperature);
	// Creates an object with the default value of the user input temperature

	cout << "At " << temperature << " degrees, " << endl;

	printInfo(instance);

	return 0;
}

void printInfo(FreezingOrBoiling input)
{
	/*
	 * This function takes user input temperature object and
	 * runs all the bool functions. Then, it prints out the
	 * appropriate information to the user.
	 */
	if (input.isEthylFreezing() == true)
	{
		cout << "Ethyl will freeze." << endl;
	}
	if (input.isEthylBoiling() == true)
	{
		cout << "Ethyl will boil." << endl;
	}
	if (input.isOxygenFreezing() == true)
	{
		cout << "Oxygen will freeze." << endl;
	}
	if (input.isOxygenBoiling() == true)
	{
		cout << "Oxygen will boil." << endl;
	}
	if (input.isWaterFreezing() == true)
	{
		cout << "Water will freeze." << endl;
	}
	if (input.isWaterBoiling() == true)
	{
		cout << "Water will boil." << endl;
	}
}

