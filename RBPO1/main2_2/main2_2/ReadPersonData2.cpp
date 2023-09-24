#include "Zagolovok.h"
void ReadPersonData(string& name, unsigned short& age, unsigned short& weight, unsigned short& height)
{
	name = ReadPersonName(name);
	age = ReadPersonAge(age);
	ReadPersonHeight();
	ReadPersonWeight(weight);
}