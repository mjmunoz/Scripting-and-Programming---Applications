#include "student.h"

using namespace std;

Student::Student()
{
	setStudentID(" ");
	setFirstName(" ");
	setLastName(" ");
	setAge(0);
	setEmailAddress(" ");
	int temp[3] = { 0,0,0 };
	setDateToComplete(temp);
	setDegree(UNDEFINED);
}

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int arrayOfNumberOfdaysToCompleteEachCourse[], DegreeProgram degree)
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;

	setDateToComplete(arrayOfNumberOfdaysToCompleteEachCourse);

	degreeProgram = degree;
}

Student::~Student()
{
	// No dynamically allocated memory to free.
}

string Student::getStudentID()
{
	return studentID;
}

string Student::getFirstName()
{
	return firstName;
}

string Student::getLastName()
{
	return lastName;
}

string Student::getEmailAddress()
{
	return emailAddress;
}

int Student::getAge()
{
	return age;
}

int* Student::getDateToComplete()
{
	return numberOfDaysToCompleteEachCourse;
}

DegreeProgram Student::getDegree()
{
	return degreeProgram;
}


// Setter Methods
void Student::setStudentID(string studentID)
{
	this->studentID = studentID;
}

void Student::setFirstName(string firstName)
{
	this->firstName = firstName;
}

void Student::setLastName(string lastName)
{
	this->lastName = lastName;
}

void Student::setEmailAddress(string emailAddress)
{
	this->emailAddress = emailAddress;
}

void Student::setAge(int age)
{
	this->age = age;
}

void Student::setDateToComplete(int DaysToEachCourse[])
{
	for (int temp = 0; temp < 3; temp++)
		numberOfDaysToCompleteEachCourse[temp] = DaysToEachCourse[temp];
}

void Student::setDegree(DegreeProgram degree)
{
	this->degreeProgram = degree;
}

void Student::print()
{
	cout << getStudentID() << " \t"
		<< "First Name: " << getFirstName() << " \t"
		<< "Last Name: " << getLastName() << " \t"
		<< "Email: " << getEmailAddress() << " \t"
		<< "Age :" << getAge() << " \t"
		<< "daysInCourse: {";
	for (int j = 0; j < 3; j++)
	{
		cout << getDateToComplete()[j];
		if (j < 2)
			cout << ", ";
	}
	cout << "}  " << "Degree Program: ";
	switch (getDegree())
	{
	case SECURITY:
		cout << "SECURITY";
		break;
	case NETWORK:
		cout << "NETWORK";
		break;
	case SOFTWARE:
		cout << "SOFTWARE";
		break;
	}
	cout << endl;
}