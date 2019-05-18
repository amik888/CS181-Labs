/*
 * EncryptionAndDecryption.cpp
 *
 *	This program takes input and encrypts it and then decrypts it.
 *
 *  Created on: Feb 12, 2019
 *      Author: amikh
 */

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// Function declarations for encryption and decryption
string encrypt(string input);
string decrypt(string encrypted);

int main()
{
	string input;
	string fileName;
	string writtenFileName;
	ifstream reader;
	ofstream writer;
	int choice;

	cout << "Please input the file name you would like to encrypt "
			<< "or decrypt and press enter: ";
	getline(cin, fileName);

	cout << "Would you like to encrypt or decrypt?" << endl
			<< "Please choose 1 for encryption or 2 for decryption: ";
	cin >> choice;
	cin.ignore();

	while (choice!=1 && choice!=2)
	{
		cout << "Invalid input, please try again: ";
		cin >> choice;
		cin.ignore();
	}

	if (choice==1)
	{
		reader.open(fileName);

		if(!reader) //checks if the file will open
		{
			cout << "File failed to open, Program exiting.";
			return 0;
		}

		cout << "What would you like to name the encrypted file? ";
		getline(cin, writtenFileName);

		writer.open(writtenFileName);
		if(!writer)
		{
			cout << "File failed to write, program exiting.";
			return 0;
		}

		while (!reader.eof())
		{
			//gets each line and writes the encrypted line until end of file.
			getline(reader,input);
			writer << encrypt(input) << endl;
		}

		cout << "Success. " << fileName << " was encrypted, and "
				<< writtenFileName << " was created.";
	}
	else if (choice==2)
	{
		reader.open(fileName);
		if(!reader) //checks if the file will open
		{
			cout << "File failed to open, Program exiting.";
			return 0;
		}

		cout << "What would you like to name the decrypted file? ";
		getline(cin, writtenFileName);

		writer.open(writtenFileName);
		if(!writer)
		{
			// checks if the file can be written, in case of short memory.
			cout << "File failed to write, program exiting.";
			return 0;
		}

		while (!reader.eof())
		{
			//gets each line and writes the decrypted line until end of file.
			getline(reader,input);
			writer << decrypt(input) << endl;
		}

		cout << "Success. " << fileName << " was decrypted, and "
						<< writtenFileName << " was created.";
	}

	reader.close();
	writer.close();

	return 0;
}

/*
 * This takes each character of a string and adds 7 to its ascii value
 * The changed character then replaces the encrypted string which is returned
 */
string encrypt (string input)
{
	char change;
	unsigned int stringPosition;

	// pulls the character at each position until end of string is reached
	while (stringPosition < input.length())
		{
			change = input.at (stringPosition);
			change = (change + 7);
			input.at (stringPosition) = change;
			stringPosition++;
		}

	return input;
}

/*
 * This takes each character of a string and subtracts 7 from its ascii value
 * The changed character then replaces the decrypted string which is returned
 */
string decrypt (string input)
{
	char change;
	unsigned int stringPosition = 0; // have to reset this to 0 from the encryption

	// pulls the character at each position until end of string is reached
	while (stringPosition < input.length())
			{
				change = input.at(stringPosition);
				change = (change - 7);
				input.at(stringPosition) = change;
				stringPosition++;
			}

	return input;
}
