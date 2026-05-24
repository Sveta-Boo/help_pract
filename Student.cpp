#include "Student.h"
#include <iostream>
#include <fstream>


Student::Student()
{
	//strcpy_s(name, 50, "");
	//group = 0;
	//for (int i = 0; i < 5; i++)
	//	marks[i] = 0;
}

Student::Student(const char* n, int g, int m[])
{
	strcpy_s(name, n);
	group = g;
	for (int i = 0; i < 5; i++)
		marks[i] = m[i];
}

bool Student::operator>(const Student& s){
	return group > s.group;
}
//strcmp(name, s.name) > 0;
Student& Student::operator=(const Student& s) {
	strcpy_s(name, 50, s.name);
	group = s.group;
	for (int i = 0; i < 5; i++)
		marks[i] = s.marks[i];
		return *this;
}
bool Student::operator<(const Student& s) {
	return group < s.group;
}
Student::Student(const Student & s) {
	strcpy_s(name, 50, s.name);
	group = s.group;
	for (int i = 0; i < 5; i++)
		marks[i] = s.marks[i];
}
bool Student::markTwo()
{
	for (int i = 0; i < 5; i++)
	{
		if (marks[i] == 2)
			return true;
	}
	return false;
}

//bool Student::operator==(const Student& s)
//{
//	return strcmp(this->name, s.name) == 0;
//}

bool Student::operator==(const Student& s) const
{
	return strcmp(name, s.name) == 0 && group == s.group;
}
