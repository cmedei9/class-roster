#include <iostream>
#include <iomanip>
#include <string>
#include "degree.h"
#include "roster.h"
#include "student.h"

using namespace std;

	const int numStudents = 5; // 5 Students
	const string studentData[] =
	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	  "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	  "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	  "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	  "A5,Corey,Medeiros,cmedei9@wgu.edu,26,20,30,40,SOFTWARE" };


Roster::Roster() {  // empty constructor
	this->capacity = 0;
	this->lastIndex = -1; // means 0
	this->classRosterArray = nullptr;
} 

Roster::Roster(int capacity) { //setting max capacity for roster
	this->capacity = capacity;
	this->lastIndex = -1;
	this->classRosterArray = new Student * [capacity];
}
	
void Roster::parseThenAdd(string datarow) {
	if (lastIndex < capacity) {
		++lastIndex;

		//Parsed data


		//Student ID
		int rhs = studentData[lastIndex].find(",");
		string sID = studentData[lastIndex].substr(0, rhs);

		//First Name
		int lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		string fName = studentData[lastIndex].substr(lhs, rhs - lhs);

		//Last Name
		lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		string lName = studentData[lastIndex].substr(lhs, rhs - lhs);

		//Email
		lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		string eAddress = studentData[lastIndex].substr(lhs, rhs - lhs);

		//Age
		lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		string sAge = studentData[lastIndex].substr(lhs, rhs - lhs);

		//Days in Course 1
		lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		int days1 = stoi(studentData[lastIndex].substr(lhs, rhs - lhs));

		//Days in Course 2
		lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		int days2 = stoi(studentData[lastIndex].substr(lhs, rhs - lhs));

		//Days in Course 3
		lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		int days3 = stoi(studentData[lastIndex].substr(lhs, rhs - lhs));

		//Degree Programs
		lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		DegreeProgram dProgram{};
		string s = studentData[lastIndex].substr(lhs, rhs - lhs);   //convert value to pass to add, convert string to degreeprogram
		
		if		(s == "SECURITY"){
			(dProgram = DegreeProgram::SECURITY);
	}
		else if (s == "NETWORK") {
			dProgram = DegreeProgram::NETWORK;
		}
		else if (s == "SOFTWARE") {
			dProgram = DegreeProgram::SOFTWARE;
		}
		
	add(sID, fName, lName, eAddress, sAge, days1, days2, days3, dProgram);
	}
		else {
			cerr << "Error! Roster has exceeded maximum capacity. Exiting..." << endl;
			exit(-1);
		} 

	}

		

void Roster::print_all() { //Prints roster
	for (int i = 0; i <= this->lastIndex; ++i) {
		this->classRosterArray[i]->print();
	}
}

bool Roster::remove(string ID) {
	bool found = false;
	for (int i = 0; i <= lastIndex; ++i) {
		if (this->classRosterArray[i]->getID() == ID) {   //Student found..
			found = true;
			delete this->classRosterArray[i]; // delete the student
			this->classRosterArray[i] = this->classRosterArray[lastIndex];
			--lastIndex;
		} 
		
	}
	if (!found) cout << "...student not found." << endl;
	return found;
}

void Roster::printAverageDaysInCourse(string studentID) {
	bool found = false;
	for (int i = 0; i <= lastIndex; ++i) {
		if (this->classRosterArray[i]->getID() == studentID) { // Student found..
			found = true;
			int* s = classRosterArray[i]->getCourseDays();
			cout << "Average days in course for Student ID " << studentID << " is: " << (s[0] + s[1] + s[2]) / 3 << endl;
		}
	}
	if (!found) cout << "Unable to locate student ID";
}

Student* Roster::cArrayLoop(int lastIndex){
	return classRosterArray[lastIndex];
}
	
void Roster::printInvalidEmails(){
	for (int i = 0; i <= lastIndex; ++i) {
		string studentEmail = classRosterArray[i]->getEmail(); // set new string studentEmail
		if (studentEmail.find("@") == string::npos || studentEmail.find(".") == string::npos || studentEmail.find(" ") != string::npos) //if email contains "@" "." and doesn't contain whitespace = PASS
			cout << studentEmail << endl; // else print invalid email
	}

}

void Roster::printByDegreeProgram(DegreeProgram dProgram) {
	cout << "Printing students pursuing a " << degreeProgramStr[dProgram] << " degree:" << endl;
	for (int i = 0; i <= lastIndex; ++i) {
		if (this->classRosterArray[i]->getDegreeProgram() == dProgram) this->classRosterArray[i]->print();
	}
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, string age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
{
	int darray[3] = {
	daysInCourse1, daysInCourse2, daysInCourse3
	};
	classRosterArray[lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, darray, degreeProgram);
}

Roster::~Roster() {
	cout << "Destructor called." << endl;
	for (int i = 0; i <= lastIndex; ++i) {
		delete classRosterArray[i];
	}
}