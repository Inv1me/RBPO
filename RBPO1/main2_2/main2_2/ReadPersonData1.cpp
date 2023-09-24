#include "Zagolovok.h"
void ReadPersonData(string& name, unsigned short& age, double& salary)
{
	name = ReadPersonName(name);
	age = ReadPersonAge(age);
	ReadPersonSalary(&salary);
}