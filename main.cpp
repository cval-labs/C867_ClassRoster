#include "roster.h"

int main()
{
    cout << "C867-Scripting & Programming: Applications" << endl;
    cout << "Language: C++" << endl;
    cout << "Student ID: 010193832" << endl;
    cout << "Name: Cristina Valerio" << endl;
    cout << endl;

    const string studentData[] = 
    {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Cristina,Valerio,cval137@wgu.edu,27,18,25,60,SOFTWARE"
    }; // strings for parsing

    const int numStudents = 5;

    Roster classRoster;

    for (int i = 0; i < numStudents; i++)
    {
        classRoster.parse(studentData[i]);
    }


    cout << "Displaying all students:" << endl;
    classRoster.printAll();

    cout << endl;

    cout << "Displaying invalid emails:" << endl;
    classRoster.printInvalidEmails();

    cout << endl;

    for (int i = 0; i < numStudents; i++) 
    {
        classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());// displays each student's average days in 3 courses
    }
        

    cout << endl;

    cout << "Showing students in degree program: " << degreeProgramStrings[2] << endl;
    classRoster.printByDegreeProgram(SOFTWARE);

    cout << endl;

    cout << "Removing A3:" << endl;
    classRoster.remove("A3");

    cout << endl;

    cout << "Removing A3 again" << endl << endl;
    classRoster.remove("A3");

    cout << "DONE." << endl;


    return 0;

}