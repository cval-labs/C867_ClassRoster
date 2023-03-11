#include "student.h"

Student::Student() //Setting default values in parameterless constructor
{
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	for (int i = 0; i < daysArraySize; i++) this->daysInCourse[i] = 0;
	this->degreeProgram = DegreeProgram::SECURITY;
}

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], DegreeProgram degreeProgram) // Full Constructor
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i < daysArraySize; i++) this->daysInCourse[i] = daysInCourse[i];
	this->degreeProgram = degreeProgram;
}

Student::~Student() {} //Deconstructor

//Accessors (getters)
string Student::getStudentID() { return this->studentID; }
string Student::getFirstName() { return this->firstName; }
string Student::getLastName() { return this->lastName; }
string Student::getEmailAddress() { return this->emailAddress; }
int Student::getAge() { return this->age; }
int* Student::getDaysInCourse() { return this->daysInCourse; }
DegreeProgram Student::getDegreeProgram() { return this->degreeProgram; }

//Mutators (setters)
void Student::setStudentID(string studentID) { this->studentID = studentID; }
void Student::setFirstName(string firstName) { this->firstName = firstName; }
void Student::setLastName(string lastName) { this->lastName = lastName; }
void Student::setEmailAddress(string emailAddress) { this->emailAddress = emailAddress; }
void Student::setAge(int age) { this->age = age; }

void Student::setDaysInCourse(int daysInCourse[])
{
	for (int i = 0; i < daysArraySize; i++) this->daysInCourse[i] = daysInCourse[i];
}

void Student::setDegreeProgram(DegreeProgram degreeProgram) { this->degreeProgram = degreeProgram; }

void Student::print() // emails are not printed in table
{
	cout << std::left << std::setw(10) << this->studentID;
	cout << std::setw(15) << this->firstName;
	cout << std::setw(10) << this->lastName;
	cout << std::setw(10) << this->age;
	cout << "{" << this->daysInCourse[0] << ",";
	cout << this->daysInCourse[1] << ",";
	cout << this->daysInCourse[2] << std::setw(8) << "}";
	cout << degreeProgramStrings[this->getDegreeProgram()];
	cout << endl;
}