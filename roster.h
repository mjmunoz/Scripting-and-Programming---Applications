#pragma once
#include "degree.h"
#include "student.h"

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cstring>

using namespace std;

const string studentData[] =
{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Mark,Munoz,mmuno20@mail.wgu.edu,30,14,15,17,SOFTWARE"
};

class Roster
{
private:
	vector<Student> classRosterArray;

public:
	// Constructor & Destructor.
	Roster();
	~Roster();

	const int MAXROSTER = 5;

	// Member Methods.
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degree);
	void remove(string studentID);

	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);
};