#include "Zagolovok.h"
void WritePersonData(string& name, const string& height, const string& weight, const unsigned short* age, string salary)
{
	cout << "���: " << name << endl <<
		"����: " << height << endl <<
		"���: " << weight << endl <<
		"�������: " << *age << endl <<
		"���������� �����: " << salary << endl;
}