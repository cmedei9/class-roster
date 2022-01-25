#include <iostream>
#include <vector>
#include <string>
#include "roster.h"
#include "student.h"
#include "degree.h"
using namespace std;


const int numStudents = 5; // 5 Students
const string studentData[] =
{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
  "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
  "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
  "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
  "A5,Corey,Medeiros,cmedei9@wgu.edu,26,20,30,40,SOFTWARE" }; 


int main() {
	cout << "C867: Scripting and Applications PA in C++" << endl;
	cout << "By: Corey Medeiros (Student ID: 001314947) " << endl << endl;
	
	
	// parsing and adding to roster -- working
	Roster* roster = new Roster(numStudents);
	cout << "Parsing student roster..." << endl << endl;
	for (int i = 0; i < numStudents; ++i) {
		roster->parseThenAdd(studentData[i]);		
	}
		
	
		//print full roster
		cout << "Active Student Roster:" << endl; // -- working!!
		roster->print_all();



		//print invalid emails --- working
		cout << endl;
		cout << "Invalid student emails:" << endl;
		roster->printInvalidEmails();
		cout << endl;
		


		// loop through class roster array to get average days in course for each student ... -- working
		for (int i = 0; i < numStudents; ++i) {
			roster->printAverageDaysInCourse
			(roster->cArrayLoop(i)->getID());
		}
		cout << endl;


		roster->printByDegreeProgram(DegreeProgram::SECURITY); //working!!
		roster->printByDegreeProgram(DegreeProgram::NETWORK);
		roster->printByDegreeProgram(DegreeProgram::SOFTWARE);
		


		// removal of student a3 from the roster -- working
		cout << endl;
		cout << "Removing student A3..." << endl; 
		roster->remove("A3");
		


		
		//printing after removing a3 -- working
		roster->print_all();
		cout << endl;

		

		// second removal of a3 - should state student was not found
		cout << endl;
		cout << "Removing student A3..." << endl;
		roster->remove("A3");


		



		

}




	
	


