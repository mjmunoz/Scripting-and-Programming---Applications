#include "student.h"
#include "degree.h"
#include "roster.h"


int main(void)
{
	cout << "Course Title: C867 - Programming & Scripting Applications\nLanguage: C++ \tStudentID: 688971\tName: Mark Munoz\n" << endl;
	for (int i = 0; i < 80; i++)  // To create a seperator from the Title.
		cout << "*";
	cout << endl;

	Roster classRoster;
	classRoster.printAll();
	classRoster.printInvalidEmails();

	for (int i = 0; i < classRoster.MAXROSTER + 1; i++)
	{
		string tempIntToStr = to_string(i);
		string tempStr = "A" + tempIntToStr;
		
		classRoster.printAverageDaysInCourse(tempStr);
	}
	cout << endl;

	classRoster.printByDegreeProgram(SOFTWARE);

	classRoster.remove("A3");
	classRoster.printAll();
	classRoster.remove("A3");
}