/*
 * FileReading.cpp
 *
 *	This program reads and outputs the first ten lines of a file
 *	Alternatively, if the file is less than ten lines, it reads to the end.
 *
 *  Created on: Feb 12, 2019
 *      Author: amikh
 */

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const int LINES = 10; // To set limit of lines read to 10.

int main()
{
	string fileName;
	ifstream file;

	// Gets name of file from user.
	cout << "Please enter the file name: ";
	getline (cin, fileName);
	file.open (fileName);
	cout << endl;

	while (!(file.is_open()))
	{
		// Checks for invalid input and tries again.
		cout << "Could not open " << fileName << ", please try another file: ";
		getline (cin, fileName);
		file.open (fileName);
	}

	unsigned int counter;
	string line;

	while (!(file.eof() || counter >= LINES))
	{
		// Reads until end of file or line limit is reached.
		getline(file, line, '\n');
		cout << line << endl;
		counter++;
		if (file.eof())
		{
			cout << "\nEnd of file has been reached." << endl;
		}
	}

	file.close();
	return 0;
}


