#pragma once
#include "degree.h"
#include <iostream>
#include <string>

using namespace std;


class Student
{
private:
	// Member Fields.
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;

	int age;
	int numberOfDaysToCompleteEachCourse[3];

	DegreeProgram degreeProgram;

public:
	// Constructor & Destructor.
	Student();
	Student (string studentID, string firstName, string lastName, string emailAddress, int age, int arrayOfDaysToCompleteEachCourse[], DegreeProgram degree);

	~Student();

	// Getter Members Methods.
	string	getStudentID();
	string	getFirstName();
	string	getLastName();
	string	getEmailAddress();
	int		getAge();
	int		*getDateToComplete();
	DegreeProgram	getDegree();

	void print();

	// Setter Members Methods.
	void	setStudentID(string studentID);
	void	setFirstName(string firstName);
	void	setLastName(string lastName);
	void	setEmailAddress(string emailAddress);
	void	setAge (int age);
	void	setDateToComplete(int DaysToCompleteEachCourse[]);
	void	setDegree (DegreeProgram degree);
};