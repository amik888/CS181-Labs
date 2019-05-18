/*
 * RecordManagement.cpp
 *
 *	A program to read, write, and modify records.
 *
 *  Created on: Feb 16, 2019
 *      Author: amikh
 */

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Record
{
	string divisionName;
	int divisionID;
	double sales;
	int year;
};


int main()
{
	Record company; // To store structure data when handling records.
	fstream file;
	string fileName;
	char userResponse;

	cout << "Please enter the name of your record file: ";
	getline(cin, fileName);

	cout << "How would you like to manage your records?"
			<< endl << "Please enter R for read, W for write, or M for modify: ";

	cin >> userResponse;
	userResponse = toupper(userResponse);

	while (!((userResponse == 'R') || (userResponse == 'W')
			|| (userResponse == 'M')))
	{
		cin.ignore(); // Skip over the remaining newline.
		cin.clear(); // Clears any bad input.
		cout << "Invalid input, please try again: ";
		cin >> userResponse;
		userResponse = toupper(userResponse);
	}

	cin.ignore(); // Skip over the remaining newline.
	cin.clear(); //clears any bad input.

	if(userResponse == 'R')
	{
		//This section was taken/adapted from pr12-16.cpp
		file.open(fileName, ios::in | ios::binary);
		if (!file)
		{
			//Checks for a valid file name - see if the file exists.
			cout << "Error opening file. Program aborting.";
			return 0;
		}

		cout << "\nHere are the records from the file: \n\n";

		// Read the first record from the file.
		file.read(reinterpret_cast<char *>(&company), sizeof(company));

		// While not at the end of the file,
		// display the records.
		while (!file.eof())
		{
			// Display the record.
			cout << "Division Name: ";
			cout << company.divisionName << endl;
			cout << "Division ID: ";
			cout <<  company.divisionID << endl;
			cout << "Sales: ";
			cout << company.sales << endl;
			cout << "Year: ";
			cout << company.year << endl;

			// Wait for the user to press the Enter key.
			cout << "\nPress the Enter key to see the next record.\n";
			cin.get();

			// Read the next record from the file.
			file.read(reinterpret_cast<char *>(&company), sizeof(company));
		}

		cout << "End of file reached.\n" << "Program ending.";
		file.close();
	}

	else if(userResponse == 'W')
	{
		file.open(fileName, ios::out | ios::binary);

		if (!file)
		{
			// Checks to see if there's space to write the file.
			cout << "Error opening file. Program aborting.";
			return 0;
		}

		do
		{
		// This section was taken/adapted from pr12-15.cpp
		// Get data about a company
		cout << "Enter the following data about your record:\n";
		cout << "Division Name: ";
		getline(cin, company.divisionName);
		cout << "Division ID: ";
		cin >> company.divisionID;

		while (company.divisionID<0)
		{
			// Checks that division ID is not negative.
			cin.ignore(); // Ignores newline at the end.
			cin.clear(); // In case of bad input, clears it.
			cout << "Invalid Division ID, please try again: ";
			cin >> company.divisionID;
		}

		cout << "Sales: ";
		cin >> company.sales;
		cout << "Year: ";
		cin >> company.year;

		while (company.year<0)
		{
			// Checks that year is not negative.
			cin.ignore(); // Ignores newline at the end.
			cin.clear(); // In case of bad input, clears it.
			cout << "Invalid year, please try again: ";
			cin >> company.divisionID;
		}

		// Write the contents of the company structure to the file.
		file.write(reinterpret_cast<char *>(&company), sizeof(company));

		// Determine whether the user wants to write another record.
		cout << "Do you want to enter another record? ";
		cin >> userResponse;
		cin.ignore(); // Skip over the remaining newline.

		} while (userResponse == 'y' || userResponse == 'Y');

	file.close();
	}

	else if(userResponse == 'M')
	{
		long recordNumber; // To hold the number of records.
		// Open the file in binary mode for input and output.
		file.open(fileName, ios::in | ios::out | ios::binary);

		// Get the record number of the desired record.
			cout << "Which record do you want to edit? ";
			cin >> recordNumber;

			// Move to the record and read it.
			file.seekg(recordNumber * sizeof(company), ios::beg);
			file.read(reinterpret_cast<char *>(&company), sizeof(company));

			// Display the record contents.
			cout << "Division Name: ";
			cout << company.divisionName << endl;
			cout << "Division ID: ";
			cout << company.divisionID << endl;
			cout << "Sales: ";
			cout << company.sales << endl;
			cout << "Year: ";
			cout << company.year << endl;

			// Get the new record data.
			cout << "\nEnter the new data:\n";
			cout << "Division Name: ";
			cin.ignore();
			getline(cin, company.divisionName);
			cout << "Division ID: ";
			cin >> company.divisionID;
			cout << "Sales: ";
			cin >> company.sales;
			cout << "Year: ";
			cin >> company.year;

			// Move back to the beginning of the this record's position.
			file.seekp(recordNumber * sizeof(company), ios::beg);

			// Write the new record over the current record.
			file.write(reinterpret_cast<char *>(&company), sizeof(company));
			file.close();
	}

	return 0;
}
