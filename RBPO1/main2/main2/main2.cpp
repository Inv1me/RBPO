#include <iostream>
#include <string>

using namespace std;

unsigned short height;

int ReadPersonAge(unsigned short age)
{
	cout << "Введите возраст человека: ";
	cin >> age;
	return age;
}

string ReadPersonName(string name)
{
	cout << "Введите имя человека: ";
	cin >> name;
	return name;
}

void ReadPersonHeight()
{
	cout << "Введите рост человека: ";
	cin >> height;
}

void ReadPersonWeight(unsigned short& weight)
{
	cout << "Введите вес человека: ";
	cin >> weight;
}

void ReadPersonSalary(double* salary)
{
	cout << "Введите заработную плату человека: ";
	cin >> *salary;
}

void ReadPersonData(string& name, unsigned short& age, double& salary)
{
	name = ReadPersonName(name);
	age = ReadPersonAge(age);
	ReadPersonSalary(&salary);
}

void ReadPersonData(string& name, unsigned short& age, unsigned short& weight, unsigned short& height)
{
	name = ReadPersonName(name);
	age = ReadPersonAge(age);
	ReadPersonHeight();
	ReadPersonWeight(weight);
}

void WritePersonData(string& name, const string& height, const string& weight, const unsigned short* age, string salary)
{
	cout << "Имя: " << name << endl <<
		"Рост: " << height << endl <<
		"Вес: " << weight << endl <<
		"Возраст: " << *age << endl <<
		"Заработная плата: " << salary << endl;
}

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