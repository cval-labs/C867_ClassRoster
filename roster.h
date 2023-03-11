#pragma once
#include "student.h"

class Roster
{
private:
	int lastIndex = -1;// -1 means no students in roster
	const static int numStudents = 5;
public:
	Student* classRosterArray[numStudents]; // declared non-dynamically
	void parse(string row);
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
	void printAll();
	void remove(string studentID);
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);

	~Roster();
};
