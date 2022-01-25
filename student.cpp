#include <iostream>
#include <iomanip>
#include <string>
#include "student.h"
#include "degree.h"
using namespace std;


Student::Student(string ID, string first, string last, string email, string age, int daysInCourse[], DegreeProgram degreeProgram) {
	this->studentID = ID;
	this->firstName = first;
	this->lastName = last;
	this->emailAddress = email;
	this->age = age;
	for (int i = 0; i < classRosterArray; ++i) {
		this->daysInCourse[i] = daysInCourse[i];
	}
	this->degreeProgram = degreeProgram;
}

//getters

string Student::getID() {
	return studentID;
}

string Student::getFirst() {
	return firstName;
}

string Student::getLast() {
	return lastName;
}

string Student::getEmail() {
	return emailAddress;
}

string Student::getAge() {
	return age;
}

int* Student::getCourseDays() {
	return daysInCourse;
}

DegreeProgram Student::getDegreeProgram() {
	return degreeProgram;
}

//setters

void Student::setID(string ID) {
	this->studentID = ID;
}

void Student::setFirst(string first) {
	this->firstName = first;
}

void Student::setLast(string last) {
	this->lastName = last;
}

void Student::setAge(string age) {
	this->age = age;
}

void Student::setEmail(string email) {
	this->emailAddress = email;
}

void Student::setCourseDays(int daysInCourse[]) {
	for (int i = 0; i < 3; ++i)
		this->daysInCourse[i] = daysInCourse[i];
}

void Student::setDegreeProgram(DegreeProgram degreeProgram) {
	this->degreeProgram = degreeProgram;
}

void Student::print() { // Printing method
	cout << left << setw(4) << studentID;
	cout << left << setw(8) << firstName;
	cout << left << setw(16) << lastName;
	cout << left << setw(8) << age;
	cout << left << setw(24) << emailAddress;
	cout << left << "\t" << daysInCourse[0]; //daysInCourse does not like setw()....not sure why
	cout << left << "\t" << daysInCourse[1];
	cout << left << "\t" << daysInCourse[2];
	cout << left << "\t" << degreeProgramStr[degreeProgram] << endl;
}

Student::~Student() {
}  //destructor
		

