#pragma once
class Student
{
public:
	char name[50];
	int group;
	int marks[5];
	Student();
	Student(const char*, int, int[]);
	void print();
	bool markTwo();
	friend std::ostream& operator<<(std::ostream& out, const Student& s);
};

