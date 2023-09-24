#include "Zagolovok.h"

unsigned short height;

int main()
{
	setlocale(LC_ALL, "Rus");
	unsigned short age = 0;
	string name;
	unsigned short weight = 0;
	double salary;

	age = ReadPersonAge(0);
	name = ReadPersonName("");
	ReadPersonHeight();
	ReadPersonWeight(weight);
	ReadPersonSalary(&salary);
	ReadPersonData(name, age, salary);
	ReadPersonData(name, age, weight, height);
	WritePersonData(name, to_string(height), to_string(weight), &age, to_string(salary));
}