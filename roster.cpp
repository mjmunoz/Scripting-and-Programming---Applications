#include"roster.h"

Roster::Roster()
{
	// Parse the studentData string into the classRosterArray.
	for (int i = 0; i < MAXROSTER; i++)
	{
		string stringToExtract = studentData[i];
		vector <string> tokenizedString;
		stringstream stringProcessingStream(stringToExtract);

		// Process String up to the ',' until end of the parent String.
		while (stringProcessingStream.good())
		{
			string tempString;
			getline(stringProcessingStream, tempString, ',');
			tokenizedString.push_back(tempString);
		}

		DegreeProgram tempDegree;
		if (tokenizedString[8] == "UNDEFINED")
			tempDegree = UNDEFINED;
		else if (tokenizedString[8] == "SECURITY")
			tempDegree = SECURITY;
		else if (tokenizedString[8] == "NETWORK")
			tempDegree = NETWORK;
		else if (tokenizedString[8] == "SOFTWARE")
			tempDegree = SOFTWARE;
	
		add(tokenizedString[0],			// Student ID
			tokenizedString[1],			// First Name
			tokenizedString[2],			// Last Name
			tokenizedString[3],			// Email
			stoi(tokenizedString[4]),	// Age
			stoi(tokenizedString[5]),	// Days to Complete Course #1
			stoi(tokenizedString[6]),	//         Complete	Course #2 
			stoi(tokenizedString[7]),   //         Complete Course #3
			tempDegree);				// Degree Program 

		stringProcessingStream.clear();
	}
}

Roster::~Roster()
{
	classRosterArray.clear();	
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degree)
{
	int ArrayOfDaysInCourse[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };

	classRosterArray.push_back( Student(studentID, firstName, lastName, emailAddress, age, ArrayOfDaysInCourse, degree) );
}

void Roster::remove(string studentID)
{
	for (int i = 0; i < classRosterArray.size(); i++)
	{
		if (!classRosterArray[i].getStudentID().find(studentID))
		{
			classRosterArray.erase(classRosterArray.begin() + i);
			break;
		}
		if (i == (classRosterArray.size()-1) && classRosterArray[i].getStudentID().find(studentID) > 0)
			cout << "EXPECTED: " << studentID << ", but the student with that ID could not be found!" << endl;
	}	
}

void Roster::printAll()
{
	cout << endl;

	for (int i = 0; i < classRosterArray.size(); i++)
		classRosterArray[i].print();
		
	cout << endl;
}

void Roster::printAverageDaysInCourse(string studentID)
{
	for (int i = 0; i < classRosterArray.size(); i++)
		if (studentID == classRosterArray[i].getStudentID())
		{
			int sum = 0;
			for (int temp = 0; temp < 3; temp++)
				sum += classRosterArray[i].getDateToComplete()[temp];

			cout << "Student: " + classRosterArray[i].getStudentID() +
				" completd 3 Classes in these averaged number of days: "  " : " << (sum / 3) << endl;
		}
}

void Roster::printInvalidEmails()
{
	cout << "Invalid Email Addresses: " << endl;

	for (int i = 0; i < classRosterArray.size(); i++)
	{
		string tempString = classRosterArray[i].getEmailAddress();
		const char *tempCharArray = tempString.c_str();
		int sizeTempCharArray = strlen(tempCharArray);

		if (tempString.find('@') == string::npos || tempString.find('.') == string::npos)
			cout << "\t" << tempString << endl;
		
		for (int temp = 0 ; temp < sizeTempCharArray ; temp++)
			if (isspace(tempCharArray[temp]))
				cout << "\t" << tempString << endl;
	}
	cout << endl;
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
	for (int i = 0; i < classRosterArray.size(); i++)
		if (degreeProgram == classRosterArray[i].getDegree())
			classRosterArray[i].print();	
	
	cout << endl;
}