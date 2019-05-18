/*
 * Employee.cpp
 *
 *  Created on: Apr 24, 2019
 *      Author: amikh
 *
 * This program demonstrates members of the ShiftSupervisor and
 * ProductionWorker classes to calculate earnings of employees
 * of the day and night shift and whether or not the supervisor
 * earned a bonus.
 */

#include <iostream>
using namespace std;

class Employee
{
private:
	string employeeName;
	int employeeNumber;
	string hireDate;

public:

	// Default argumented constructor for Employee class.
	// Initializes variables to argument values.
	Employee(string name = "", int number = 0, string date = "")
	{
		this -> employeeName = name;
		this -> employeeNumber = number;
		this -> hireDate = date;
	}

	// Mutator functions for the employee's name,
	// employee number, and hiring date.
	void setName (string name)
	{
		this -> employeeName = name;
	}
	void setNumber (int number)
	{
		this -> employeeNumber = number;
	}
	void setDate (string date)
	{
		this -> hireDate = date;
	}

	// Accessor functions that return the value of
	// the private data stored in an Employee object.
	string getName()
	{
		return this -> employeeName;
	}
	int getNumber()
	{
		return this -> employeeNumber;
	}
	string getDate()
	{
		return this -> hireDate;
	}
};

// ProductionWorker class, publicly derived from the employee class.
class ProductionWorker: public Employee
{
private:
	int shift;
	double hourlyPayRate;
	double hoursWorked;

public:
	// Default argumented constructor. Includes arguments for variables inherited
	// by the Employee class.
	ProductionWorker(int shift = 0, double payRate = 0.0, double hoursWorked = 0.0,
			string name = "", int employeeNumber = 0, string date = "")
	{
		this -> shift = shift;
		this -> hourlyPayRate = payRate;
		this -> hoursWorked = hoursWorked;

		// Uses mutator functions to change the inherited data.
		setName(name);
		setNumber(employeeNumber);
		setDate(date);
	}

	// Mutator functions for ProductionWorker shift, pay rate, and hours.
	void setShift(int shift)
	{
		this -> shift = shift;
	}
	void setPayRate(double hourlyPayRate)
	{
		this -> hourlyPayRate = hourlyPayRate;
	}
	void work(double hours)
	{
		this -> hoursWorked = hours;
	}

	// Accessor functions to return the values of ProductionWorker's variables.
	int getShift()
	{
		return this -> shift;
	}
	double getPayRate()
	{
		return this -> hourlyPayRate;
	}
	double getHours()
	{
		return this -> hoursWorked;
	}
};

// ShiftSupervisor class, derived publicly from the Employee class.
class ShiftSupervisor: public Employee
{
private:
	int salary;
	int bonus;

public:
	// Default argumented constructor. Includes arguments for
	// variables inherited from the Employee class.
	ShiftSupervisor(int salary = 0, int bonus = 0, string name = "",
			int employeeNumber = 0, string date = "")
	{
		this -> salary = salary;
		this -> bonus = bonus;

		// Uses mutator functions to change inherited variables.
		setName(name);
		setNumber(employeeNumber);
		setDate(date);
	}

	// Mutator functions for ShiftSupervisor's salary and bonus.
	void setSalary(int salary)
	{
		this -> salary = salary;
	}
	void setBonus(int bonus)
	{
		this -> bonus = bonus;
	}

	// Accessor functions for ShiftSupervisor's salary and bonus.
	int getSalary()
	{
		return this -> salary;
	}
	int getBonus()
	{
		return this -> bonus;
	}
};

//Function prototypes to print worker earnings and to input the workers' hours.
void printEarnings(ProductionWorker worker1, ProductionWorker worker2,
		ProductionWorker worker3, ShiftSupervisor& supervisor, double productionQuota);

void getWorkHours(ProductionWorker& worker1, ProductionWorker& worker2,
		ProductionWorker& worker3);

const int DAY = 1;
const int NIGHT = 2;
const double HOURLY_PAY = 12.50;
const int SUPERVISOR_SALARY = 65000;
const int SUPERVISOR_BONUS = 2500;

int main()
{
	int productionQuota;

	// Create a day shift supervisor and initialize data.
	ShiftSupervisor anna(SUPERVISOR_SALARY, 0, "Anna Banana");

	// Get production quota from the user.
	cout << "During the day shift, " << anna.getName() << " supervises 3 production workers."
			<< endl << "Please enter the production quota for the year in hours: ";
	cin >> productionQuota;

	// Create production workers and initialize data.
	ProductionWorker jackson(DAY, HOURLY_PAY, 0.0, "Jackson Holmes");
	ProductionWorker amelia(DAY, HOURLY_PAY, 0.0, "Amelia Wilson");
	ProductionWorker matt(DAY, HOURLY_PAY, 0.0, "Matt Frank");

	getWorkHours(jackson, amelia, matt);

	cout << endl;
	printEarnings(jackson, amelia, matt, anna, productionQuota);

	// Create night shift supervisor and initialize data.
	ShiftSupervisor jasmine(SUPERVISOR_SALARY, 0, "Jasmine Larson");

	// Get night shift production quota from the user.
	cout << endl << endl << "During the night shift, " << jasmine.getName()
			<< " supervises 3 production workers." << endl
			<< "Please enter the production quota for the year in hours: ";
	cin >> productionQuota;

	// Create and initialize night shift workers.
	ProductionWorker xavier(NIGHT, HOURLY_PAY, 0.0, "Xavier Gaylen");
	ProductionWorker finn(NIGHT, HOURLY_PAY, 0.0, "Finn Shepherd");
	ProductionWorker brittney(NIGHT, HOURLY_PAY, 0.0, "Brittney Bridge");

	getWorkHours(xavier, finn, brittney);

	cout << endl;
	printEarnings(xavier, finn, brittney, jasmine, productionQuota);

	return 0;
}

// This function allows the user to input the work hours for three workers.
// It stores this data in the production worker objects passed by reference.
void getWorkHours(ProductionWorker& worker1, ProductionWorker& worker2,
		ProductionWorker& worker3)
{
	double hours;

	cout << "How much did " << worker1.getName() << " work this year? ";
	cin >> hours;
	worker1.work(hours);

	cout << "How much did " << worker2.getName() << " work this year? ";
	cin >> hours;
	worker2.work(hours);

	cout << "How much did " << worker3.getName() << " work this year? ";
	cin >> hours;
	worker3.work(hours);
}

// This function allows users to print out the earnings of three workers
// and their supervisor.
void printEarnings(ProductionWorker worker1, ProductionWorker worker2,
		ProductionWorker worker3, ShiftSupervisor& supervisor, double productionQuota)
{
	double totalHours = (worker1.getHours() + worker2.getHours() + worker3.getHours());

	cout << worker1.getName() << " earned $" << worker1.getHours() * worker1.getPayRate()
			<< endl << worker2.getName() << " earned $" << worker2.getHours() * worker2.getPayRate()
			<< endl << worker3.getName() << " earned $" << worker3.getHours() * worker3.getPayRate();

	// If the workers meet the given quota, the supervisor earns the bonus.
	if (totalHours >= productionQuota)
	{
		supervisor.setBonus(SUPERVISOR_BONUS);
		cout << endl << supervisor.getName() << " met production goals and has earned a $"
				<< supervisor.getBonus() << " bonus for the year.";
	}
	else
	{
		cout << endl << supervisor.getName() << " did not meet production goals and"
				<< " did not earn a bonus for the year.";
	}
}
