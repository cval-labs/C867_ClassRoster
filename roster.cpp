#include "roster.h"

void Roster::parse(string row)
{
	size_t rhs = row.find(","); // rhs stands for right hand side
	string studentID = row.substr(0, rhs); // Starts at index 0, extracts just before comma

	size_t lhs = rhs + 1; // lhs stands for left hand side. Moves past comma

	rhs = row.find(",", lhs); // finds first name
	string fName = row.substr(lhs, rhs - lhs);

	lhs = rhs + 1;

	rhs = row.find(",", lhs);// finds last name
	string lName = row.substr(lhs, rhs - lhs);

	lhs = rhs + 1;

	rhs = row.find(",", lhs);
	string email = row.substr(lhs, rhs - lhs);

	lhs = rhs + 1;

	rhs = row.find(",", lhs);
	int age = stoi(row.substr(lhs, rhs - lhs)); // converts string to int

	int days[3] = {};

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	days[0] = stoi(row.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	days[1] = stoi(row.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	days[2] = stoi(row.substr(lhs, rhs - lhs));

	DegreeProgram degree = SECURITY; // sets a default value to degree
	if (row.back() == 'K') degree = NETWORK;
	else if (row.back() == 'E') degree = SOFTWARE;

	add(studentID, fName, lName, email, age, days[0], days[1], days[2], degree); // adds each student object to classRosterArray
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degree)
{
	int daysArray[3] = { daysInCourse1,daysInCourse2,daysInCourse3 }; // puts days into array
	classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, daysArray, degree); // puts student in roster
}

void Roster::printAll() // loops through all the students and calls the print() function for each student
{
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		classRosterArray[i]->print();
	}
}

void Roster::remove(string studentID) // removes students from roster
{
	bool found = false; // no students found
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (classRosterArray[i]->getStudentID() == studentID)
		{
			found = true;
			if (i < numStudents - 1)
			{
				// swaps i-th student with last student in roster
				Student *temp = classRosterArray[i]; 
				classRosterArray[i] = classRosterArray[numStudents - 1];
				classRosterArray[numStudents - 1] = temp;				
			}
			Roster::lastIndex--; // removed student is hidden, not destroyed
		}
	}

	if (found)
	{
		cout << "Student " << studentID << " removed." << endl;
		this->printAll();
	}
	else
	{
		cout << "Student with ID: " << studentID << " was not found." << endl;
	}
}



void Roster::printAverageDaysInCourse(string studentID)
{
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (classRosterArray[i]->getStudentID() == studentID) 
		{
			cout << "Student ID: " << studentID << ", average days in course is: ";
			cout << (classRosterArray[i]->getDaysInCourse()[0] +
				classRosterArray[i]->getDaysInCourse()[1] +
				classRosterArray[i]->getDaysInCourse()[2]) / 3 << endl;
		}		
	}
}

void Roster::printInvalidEmails() // A valid email should include an at sign ('@') and period ('.') and should not include a space (' ').
{
	bool invalid = false; // no invalid emails

	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		invalid = true; // email is invalid
		string email = classRosterArray[i]->getEmailAddress();
		if (email.find(' ') != string::npos || email.find('@') == string::npos || email.find('.') == string::npos)
		{
			cout << email << " - is invalid." << endl;
		}
	}

	if (!invalid) cout << "No invalid emails." << endl;
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (Roster::classRosterArray[i]->getDegreeProgram() == degreeProgram) classRosterArray[i]->print();
	}
	cout << endl;
}

Roster::~Roster() // Destructor
{
	for (int i = 0; i < numStudents; i++)
	{
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
}