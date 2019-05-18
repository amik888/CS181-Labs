/*
 * parkingTicket.cpp
 *
 *  Created on: Apr 5, 2019
 *      Author: amikh
 *
 *  This program simulates an officer checking a parked car and it's
 *  parking meter. If the car's park time is over the time purchased,
 *  the officer writes a ticket which gets displayed.
 */

#include <iostream>
#include <string>
#include <math.h>
using namespace std;

// ParkedCar represents a parked car's data with accessors and mutators.
class ParkedCar
{
private:
	string make;
	string model;
	string color;
	string licensePlate;
	int minParked;

public:
	ParkedCar(string make = "", string model = "", string color = "",
			string licensePlate = "", int minParked = 0)
	{
		this -> make = make;
		this -> model = model;
		this -> color = color;
		this -> licensePlate = licensePlate;
		this -> minParked = minParked;
	}
	// Accessor functions for car's data.
	string getMake()
	{
		return this -> make;
	}

	string getModel()
	{
		return this -> model;
	}

	string getColor()
	{
		return this -> color;
	}

	string getLicensePlate()
	{
		return this -> licensePlate;
	}

	int getMinParked()
	{
		return this -> minParked;
	}

	// Mutator functions for car's data.
	void setMake(string make)
	{
		this -> make = make;
	}

	void setModel(string model)
	{
		this -> model = model;
	}

	void setColor(string color)
	{
		this -> color = color;
	}

	void setLicensePlate(string licensePlate)
	{
		this -> licensePlate = licensePlate;
	}

	void setMinParked(int minParked)
	{
		this -> minParked = minParked;
	}
};

// ParkingMeter class keeps track of the minutes of parking purchased.
class ParkingMeter
{
private:
	int minPurchased;

public:
	ParkingMeter(int minPurchased = 0)
	{
		this -> minPurchased = minPurchased;
	}

	// Accessor and mutator functions for the number of minutes purchased.
	int getMinPurchased()
	{
		return this -> minPurchased;
	}
	void setMinPurchased(int minutes)
	{
		this -> minPurchased = minutes;
	}

};

// ParkingTicket class represents a parking ticket created by an officer
// to list an illegally parked car's information and the fine owed.
class ParkingTicket
{
private:
	int hoursIllegallyParked;
	int fine;
public:
	// Argumented constructor, takes the car and meter as arguments
	// and uses the time parked and the time purchased to calculate a fine
	// based on the number of hours illegally parked.
	ParkingTicket(ParkedCar car, ParkingMeter meter)
{
		this -> hoursIllegallyParked = ceil((car.getMinParked()
				- meter.getMinPurchased()) / 60.0);
		// Rounds up the partial hours that have been parked using ceil.

		this -> fine = (25 + (hoursIllegallyParked - 1) * 10);
}

	// Accessor function that returns the parking ticket fine.
	int getFine()
	{
		return this -> fine;
	}

	// Accessor function that returns the hours illegally parked.
	int getHoursIllegallyParked()
	{
		return this -> hoursIllegallyParked;
	}

};

class PoliceOfficer
{
private:
	string name;
	int badgeNumber;
public:
	PoliceOfficer(string name = "", int badgeNumber = 0)
	{
		this -> name = name;
		this -> badgeNumber = badgeNumber;
	}

	// Checks a car and a meter to see if the car is illegally
	// parked. The officer writes a ticket if it is.
	void checkCar(ParkedCar car, ParkingMeter meter)
	{
		if(car.getMinParked() > meter.getMinPurchased())
		{
			writeTicket(car, meter);
		}
	}

	// Creates an object of the ParkingTicket class using
	// dynamic memory, prints it, then deletes the memory.
	void writeTicket(ParkedCar car, ParkingMeter meter)
	{
		ParkingTicket * ptr = new ParkingTicket(car, meter);
		printTicket(car, *ptr);
		delete ptr;
		ptr = NULL;
	}

	// This function prints out the car's information, the fine,
	// and the officer's information.
	void printTicket(ParkedCar car, ParkingTicket ticket)
	{
		cout << "Make: " << car.getMake() << endl
				<< "Model: " << car.getModel() << endl
				<< "Color: " << car.getColor() << endl
				<< "License Plate: " << car.getLicensePlate() << endl
				<< "Fine: $" << ticket.getFine() << endl
				<< "Officer Name: " << this -> name << endl
				<< "Officer Badge Number: " << this -> badgeNumber ; //use cout?
	}

	// Accessor function for the officer's name.
	string getName()
	{
		return this -> name;
	}

	// Accessor function for the officer's badge number.
	int getBadgeNumber()
	{
		return this -> badgeNumber;
	}

	// Mutator function for the officer's name.
	void setName(string name)
	{
		this -> name = name;
	}

	// mutator function for the officer's badge number.
	void setBadgeNumber(int badgeNumber)
	{
		this -> badgeNumber = badgeNumber;
	}

};




int main()
{
	PoliceOfficer jimmy("James Rochester", 33212);
	ParkedCar car1("Acura", "TL", "Silver", "AXL230", 91);
	ParkingMeter meter1(30);
	jimmy.checkCar(car1, meter1);
	ParkingTicket test (car1, meter1);
}
