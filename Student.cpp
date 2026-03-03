#include "Student.h"
#include <iostream>

Student::Student()
{
	strcpy_s(name, 50, "");
	group = 0;
	for (int i = 0; i < 5; i++)
		marks[i] = 0;
}

Student::Student(const char* n, int g, int m[])
{
	strcpy_s(name, 50, n);
	group = g;
	for (int i = 0; i < 5; i++)
		marks[i] = m[i];
}

void Student::print()
{
	std::cout << name << " " << group << "\n";
	for (int i = 0; i < 5; i++)
		std::cout << marks[i] << "\n";
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

