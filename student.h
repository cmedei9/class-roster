#ifndef STUDENT_H
#define STUDENT_H
#pragma once
#include <string>
#include <iostream>
#include "degree.h"
using namespace::std;

class Student { // Student Class
	private:
		string studentID;
		string firstName;
		string lastName;
		string emailAddress;
		string age;
		int daysInCourse[3]; // # days in courses
		DegreeProgram degreeProgram; //enum of the 3 degree programs

	public:
		const static int classRosterArray = 3;
		//Student(); //empty constructor
		Student(string ID, string first, string last, string email, string age, int daysInCourse[], DegreeProgram degreeProgram); //student constructor w parameters

		//getters
		string getID();
		string getFirst();
		string getLast();
		string getEmail();
		string getAge();
		int* getCourseDays();
		DegreeProgram getDegreeProgram();

		//setters
		void setID(string ID);
		void setFirst(string first);
		void setLast(string last);
		void setEmail(string email);
		void setAge(string age);
		void setCourseDays(int daysInCourse[]);
		void setDegreeProgram(DegreeProgram dProgram);
		void print(); //no parameter needed

		
		~Student(); // Destructor

		

};






#endif
