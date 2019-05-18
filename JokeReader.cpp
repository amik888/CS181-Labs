/*
 * JokeReader.cpp
 *
 *	Reads the joke from a text file, then reads the punchline from another file
 *
 *  Created on: Feb 12, 2019
 *      Author: amikh
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function declarations to read the two files.
void readJoke (ifstream& file);
void readPunchline(ifstream& file);

int main()
{
	ifstream fileReader;

	fileReader.open("Joke.txt");
	readJoke(fileReader);

	fileReader.close();

	fileReader.open("punchline.txt");
	readPunchline(fileReader);

	fileReader.close();

	return 0;
}


void readJoke(ifstream& file)
{
	//checks file opened and then reads and prints entire file
	if (!(file.is_open()))
	{
		// Checks for valid file, just in case of typos or if it doesn't exist!
		cout << "Error opening file.";
	}

	string line;

	while (file.is_open() && !(file.eof()))
	{
		// Reads and prints until end of file.
		getline(file, line);
		cout << line << endl;
	}
}


void readPunchline(ifstream& file)
{
	if (!(file.is_open()))
	{
		// Checks for valid file, just in case of typos or if it doesn't exist!
		cout << "Error opening file.";
	}

	// Checks file opened and then reads and prints only the last line.
	char endLine; // Used to store character values while looking for '\n'.

	file.seekg(-1L, file.end); // Puts pointer last character before end of file.
	file.get(endLine); // Reads last character

	while (!(endLine=='\n'))
	{
		// Looks for the beginning of the last line by finding '\n'.
		file.seekg(-2L, file.cur); // Moves back two characters then reads one.
		file.get(endLine); //Pointer ends up one character back from its starting place.
	}

	string line;

	getline(file, line);
	cout << line << endl;
}
