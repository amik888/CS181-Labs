/*
 * Preferredcustomer.cpp
 *
 *  Created on: Apr 24, 2019
 *      Author: amikh
 *
 *  This program simulates a preferred customer shopping
 *  and returns the discount level as well as the amount
 *  saved on two shopping trips.
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
	// Default argumented constructor to initialize data to
	// given values.
	PersonData(string lastName = "", string firstName = "",
			string address = "", string city = "", string state = "",
			int zip = 0, int phone = 0)
	{
		this -> lastName = lastName;
		this -> firstName = firstName;
		this -> address = address;
		this -> city = city;
		this -> state = state;
		this -> zip = zip;
		this -> phone = phone;
	}

	// Mutator functions for data in PersonData class.
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

	// Accessor functions for data in PersonData class.
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

// CustomerData class publicly derived from the PersonData class.
class CustomerData: public PersonData
{
private:
	int customerNumber;
	bool mailingList;

public:
	// Default argumented constructor to initialize CustomerData variables.
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

	// Mutator functions for CustomerData variables.
	void setCustomerNumber(int customerNumber)
	{
		this -> customerNumber = customerNumber;
	}
	void setMailingList(bool mailingList)
	{
		this -> mailingList = mailingList;
	}

	// Accessor functions for CustomerData variables.
	int getCustomerNumber()
	{
		return this -> customerNumber;
	}
	bool getMailingList()
	{
		return this -> mailingList;
	}
};

// PreferredCustomer class derived from CustomerData class.
class PreferredCustomer: public CustomerData
{
private:
	double purchasesAmount;
	double discountLevel;

	const double TIER_1 = 500.00;
	const double TIER_2 = 1000.00;
	const double TIER_3 = 1500.00;
	const double TIER_4 = 2000.00;

	const int DISCOUNT_0 = 0;
	const int DISCOUNT_1 = 5;
	const int DISCOUNT_2 = 6;
	const int DISCOUNT_3 = 7;
	const int DISCOUNT_4 = 10;

public:
	// Default argumented constructor to initialize
	// PreferredCustomer's data, including inherited data.
	PreferredCustomer(double purchases = 0.0, int customerNumber = 0,
			bool mailingList = false, string lastName = "",
			string firstName = "", string address = "", string city = "",
			string state = "", string zip = "", string phone = "")
	{
		if(purchases >= 0.0)
		{
			this -> purchasesAmount = purchasesAmount;
			calculateDiscount();
		}
		else
		{
			cout << "Invalid purchase amount.";
		}

		// Use mutator functions to initialize inherited data.
		setCustomerNumber(customerNumber);
		setMailingList(mailingList);
		setLastName(lastName);
		setFirstName(firstName);
		setAddress(address);
		setCity(city);
		setState(state);
		setZip(zip);
		setPhone(phone);
	}

	// This function increases purchaseAmount by adding the cost of a purchase
	// to the previous purchaseAmount.
	void purchase(double purchases)
	{
		if(purchases < 0)
		{
			cout << "Amount of purchases cannot be negative.";
		}
		else
		{
			this -> purchasesAmount = (this -> purchasesAmount + purchases);
		}
	}

	// This function calculates the discount a customer is qualified for
	// based on their purchases amount.
	void calculateDiscount()
	{
		if(this -> purchasesAmount < TIER_1)
			this -> discountLevel = DISCOUNT_0;

		if(this -> purchasesAmount >= TIER_1 && this -> purchasesAmount < TIER_2)
			this -> discountLevel = DISCOUNT_1;

		if(this -> purchasesAmount >= TIER_2 && this -> purchasesAmount < TIER_3)
			this -> discountLevel = DISCOUNT_2;

		if(this -> purchasesAmount >= TIER_3 && this -> purchasesAmount < TIER_4)
			this -> discountLevel = DISCOUNT_3;

		if(this -> purchasesAmount >= TIER_4)
			this -> discountLevel = DISCOUNT_4;
	}


	// Accessor functions to return the purchases amount or discount level.
	double getPurchases()
	{
		return this -> purchasesAmount;
	}
	double getDiscountLevel()
	{
		return this -> discountLevel;
	}
};

void choosePurchase(PreferredCustomer& customer);

const double TV_COST = 2999.99;
const double PHONE_COST = 999.99;
const double HEADPHONES_COST = 49.99;

const int TV_ID = 1;
const int PHONE_ID = 2;
const int HEADPHONES_ID = 3;

int main()
{
	PreferredCustomer jon(0.0, 24, true, "Hopkins", "Jon");

	cout << jon.getFirstName() << ", the preferred customer, is going shopping at "
			<< "the electronics store for the first time."
			<< endl << "What should he buy? "
			<< "(1 for a TV, 2 for a phone, 3 for headphones)"
			<< endl;

	choosePurchase(jon);

	cout << endl << jon.getFirstName()
			<< " returns to the electronics store later. "
			<< endl << "What should he buy this time? "
			<< "(1 for a TV, 2 for a phone, 3 for headphones)"
			<< endl;

	choosePurchase(jon);

	return 0;
}

// This function prompts the user to choose what the customer buys.
// The discount (if any) is applied and subtracted from his purchase.
// It then prints out the amount saved and the discount the customer
// is eligible for.
void choosePurchase(PreferredCustomer& customer)
{
	double amountSaved;
	const double PERCENT_CONVERSION = .01;
	int idChoice = 0;

	while(idChoice != TV_ID && idChoice != PHONE_ID && idChoice != HEADPHONES_ID)
	{
		cin >> idChoice;
		if(idChoice == TV_ID)
		{
			amountSaved = (TV_COST * customer.getDiscountLevel() * PERCENT_CONVERSION);
			customer.purchase(TV_COST - amountSaved);
		}
		else if(idChoice == PHONE_ID)
		{
			amountSaved = (PHONE_COST * customer.getDiscountLevel() * PERCENT_CONVERSION);
			customer.purchase(PHONE_COST - amountSaved);
		}
		else if(idChoice == HEADPHONES_ID)
		{
			amountSaved = (HEADPHONES_COST * customer.getDiscountLevel() * PERCENT_CONVERSION);
			customer.purchase(HEADPHONES_COST);
		}
		else
		{
			cout << "Invalid input, try again: ";
		}
	}

	customer.calculateDiscount();

	cout << customer.getFirstName() << " saved $" << amountSaved
			<< " on this purchase. " << endl
			<< "He is eligible for a " << customer.getDiscountLevel()
			<< "% discount on his next purchase." << endl;
}
