#pragma once
#include <iostream>
//#include <string>
using namespace std;

class Student
{
public:
	//std::string name;
	char name[50] = { '\0' };
	int group = 0;
	int marks[5] = { 0 };

	Student* next;

	Student();
	Student(const char*, int g, int m[]);
	Student(const Student& s);
	bool operator>(const Student& s);
	Student& operator=(const Student& s);
	bool operator<(const Student& s);

	bool markTwo();

	friend ostream& operator<<(ostream& os, const Student& s) {
		os << s.name << " " << s.group << " ";
		for (int i = 0; i < 5; i++)
			os << s.marks[i] << " ";
		return os;
	}
	friend istream& operator>>(istream& is, Student& s) {
		is >> s.name >> s.group;
		for (int i = 0; i < 5; i++)
			is >> s.marks[i];
		return is;
	}

	bool operator==(const Student& s)const;

	char* getName() const {
		return(char*)name;
	}
	static int compStudName(const void* a, const void* b) {
		Student* pa = (Student*)a;
		Student* pb = (Student*)b;
		return strcmp(pa->getName(), pb->getName());
	}

};