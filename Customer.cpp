/*
 * Customer.cpp
 *
 *  Created on: Apr 27, 2019
 *      Author: amikh
 *
 *  This program shows an example customer's data and then allows
 *  the user to input a new customer's data and prints it out.
 */




#include <iostream>
using namespace std;

class PersonData
{
private:
	string lastName;
	string firstName;
	string address;
	string city;
	string state;
	string zip;
	string phone;

public:
	// Default argumented constructor to take arguments and
	// initialize the class's data with them.
	PersonData(string lastName = "", string firstName = "",
			string address = "", string city = "", string state = "",
			string zip = "", string phone = "")
	{
		this -> lastName = lastName;
		this -> firstName = firstName;
		this -> address = address;
		this -> city = city;
		this -> state = state;
		this -> zip = zip;
		this -> phone = phone;
	}

	// Mutator functions to change a person's last name,
	// first name, address, city, state, zip, and phone number.
	void setLastName(string name)
	{
		this -> lastName = name;
	}
	void setFirstName(string name)
	{
		this -> firstName = name;
	}
	void setAddress(string address)
	{
		this -> address = address;
	}
	void setCity(string city)
	{
		this -> city = city;
	}
	void setState(string state)
	{
		this -> state = state;
	}
	void setZip(string zip)
	{
		this -> zip = zip;
	}
	void setPhone(string phone)
	{
		this -> phone = phone;
	}

	// Accessor functions to return the stored value
	// of the object's variables.
	string getLastName()
	{
		return this -> lastName;
	}
	string getFirstName()
	{
		return this -> firstName;
	}
	string getAddress()
	{
		return this -> address;
	}
	string getCity()
	{
		return this -> city;
	}
	string getState()
	{
		return this -> state;
	}
	string getZip()
	{
		return this -> zip;
	}
	string getPhone()
	{
		return this -> phone;
	}

};

// CustomerData class publicly inherited from the PersonData class.
class CustomerData: public PersonData
{
private:
	int customerNumber;
	bool mailingList;

public:
	// Default argumented constructor to initialize data with arguments.
	// Includes arguments for data derived from PersonData.
	CustomerData(int customerNumber = 0, bool mailingList = false,
			string lastName = "", string firstName = "",
			string address = "", string city = "", string state = "",
			string zip = "", string phone = "")
	{
		this -> customerNumber = customerNumber;
		this -> mailingList = mailingList;

		// Uses mutator functions to initialize inherited data.
		setLastName(lastName);
		setFirstName(firstName);
		setAddress(address);
		setCity(city);
		setState(state);
		setZip(zip);
		setPhone(phone);
	}

	// Mutator functions for CustomerData's variables.
	void setCustomerNumber(int customerNumber)
	{
		this -> customerNumber = customerNumber;
	}
	void setMailingList(bool mailingList)
	{
		this -> mailingList = mailingList;
	}

	// Accessor functions for CustomerData's variables.
	int getCustomerNumber()
	{
		return this -> customerNumber;
	}
	bool getMailingList()
	{
		return this -> mailingList;
	}
};

// Function prototypes to get and print out a customer's data.
void getData(CustomerData& customer, int customerCount);
void printData(CustomerData customer);

int main()
{
	int customerCount = 1;
	CustomerData customer1(customerCount, true, "Watkins", "Amelia",
			"1234 Holmes", "Kansas City", "Missouri", "64138", "816-555-2212");

	printData(customer1);

	customerCount++;

	cout << endl << "Please enter the following information for the next customer.";

	CustomerData customer2;
	getData(customer2, customerCount);

	cout << endl;
	printData(customer2);

	return 0;

}

// This function prompts the user to give different inputs
// to modify an existing CustomerData object using the mutator functions.
void getData(CustomerData& customer, int customerCount)
{
	string firstName;
	string lastName;
	string address;
	string city;
	string state;
	string zip;
	string phone;
	char mailingList;


	// Asks user for name, address, city, etc.
	cout << endl << "First name: ";
	getline(cin, firstName);
	customer.setFirstName(firstName);

	cout << "Last name: ";
	getline(cin, lastName);
	customer.setLastName(lastName);

	cout << "Address: ";
	getline(cin, address);
	customer.setAddress(address);

	cout << "City: ";
	getline(cin, city);
	customer.setCity(city);

	cout << "State: ";
	getline(cin, state);
	customer.setState(state);

	cout << "Zip code: ";
	getline(cin, zip);
	customer.setZip(zip);

	cout << "Phone number: ";
	getline(cin, phone);
	customer.setPhone(phone);

	customer.setCustomerNumber(customerCount);

	// Asks if the customer wants to join the mailing list
	// and sets the appropriate bool value.
	cout << "Would you like to join the mailing list? (Y/N): ";
	cin >> mailingList;
	if(toupper(mailingList) == 'Y')
	{
		customer.setMailingList(true);
		cout << customer.getFirstName() << " " << customer.getLastName()
				<< " (Customer number: " << customer.getCustomerNumber()
				<< ") was signed up for the mailing list." << endl;
	}
	else if (toupper(mailingList) == 'N')
	{
		customer.setMailingList(false);
		cout << customer.getFirstName() << " " << customer.getLastName()
				<< " (Customer number: " << customer.getCustomerNumber()
				<< ") was not signed up for the mailing list." << endl;
	}
	// Input validation.
	else
	{
		cout << "Invalid input. "<< customer.getFirstName() << " " << customer.getLastName()
				<< " (Customer number: " << customer.getCustomerNumber()
				<< ") was not signed up for the mailing list." << endl;
	}
}

// This function prints the data by using the accessor functions of the object.
void printData(CustomerData customer)
{
	cout << "Customer number " << customer.getCustomerNumber() << endl;
	cout << "Name: " << customer.getFirstName() << " " << customer.getLastName() << endl;
	cout << "Address: " << customer.getAddress() << endl;
	cout << customer.getCity() << ", " << customer.getState() << ", " << customer.getZip();
	cout << endl << "Phone number: " << customer.getPhone() << endl;
}
