#ifndef ROSTER_H
#define ROSTER_H
#pragma once
#include "student.h"
#include "degree.h"
#include <string>
using namespace std;

class Roster {
	public:

	int lastIndex; //last student in roster
	int capacity; // max size of roster
	Student** classRosterArray; 
	Roster(); // empty constructor
	Roster(int capacity); // empty constructor but takes max size
	void parseThenAdd(string datarow); // parses strings
	void print_all(); // prints all books using print()
	bool remove(string studentID); // removes student based on StudentID
	void printAverageDaysInCourse(string studentID); // prints avg of 3 days in course
	void printInvalidEmails(); // prints emails that do not contain @ or . or have whitespace
	Student* cArrayLoop(int lastIndex);
	void printByDegreeProgram(DegreeProgram dProgram); // prints students in a specific degree program
	void add(string studentID, string firstName, string lastName, string emailAddress, string age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
	~Roster(); // Destructor

};


#endif
