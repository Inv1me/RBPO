#include "Zagolovok.h"
void WritePersonData(string& name, const string& height, const string& weight, const unsigned short* age, string salary)
{
	cout << "Имя: " << name << endl <<
		"Рост: " << height << endl <<
		"Вес: " << weight << endl <<
		"Возраст: " << *age << endl <<
		"Заработная плата: " << salary << endl;
}