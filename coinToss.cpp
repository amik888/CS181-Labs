/*
 * coinToss.cpp
 *
 *  Created on: Mar 15, 2019
 *      Author: amikh
 *
 *	This program simulates a coin toss. The coin randomly shows up heads or tails.
 */


#include <iostream>
#include <cstdlib>		// For rand and srand
#include <ctime>		// For time
using namespace std;

class Coin
{
private:
	string sideUp;
public:
	Coin()
	{
		// Gets the system time
		unsigned seed = time(0);

		// Seeds the random number generator
		srand(seed);

		// Perform an initial toss.
		toss();
	}
	string getSideUp()
	{
		return this -> sideUp;
	}
	void toss()
	{
		// Tosses the coin.

		// Generates random value of either 0 or 1.
		if((rand() % 2) == 1)
		{
			// 1 means heads.
			this -> sideUp = "heads";
		}
		else
		{
			// 0 means tails.
			this -> sideUp = "tails";
		}

	}
};

int main()
{
	const int MAX_TOSSES = 20;
	Coin dime;

	//Gets initial side up.
	cout << "Initial side up: " << dime.getSideUp() << endl;

	cout << "Tossing the coin " << MAX_TOSSES << " times.";

	int headsCount = 0;
	int tailsCount = 0;
	for( int count = 0; count < MAX_TOSSES; count++)
	{
		// Tosses the coin 20 times.
		cout << endl;
		dime.toss();
		cout << dime.getSideUp(); // Display coin side.

		//counts the number of heads in the 20 flips.
		if (dime.getSideUp() == "heads")
		{
			headsCount++;
		}
		//counts the number of tails in the 20 flips.
		if (dime.getSideUp() == "tails")
		{
			tailsCount++;
		}
	}

	cout << endl << "Number of heads: " << headsCount;
	cout << endl << "Number of tails: " << tailsCount;

	return 0;
}

