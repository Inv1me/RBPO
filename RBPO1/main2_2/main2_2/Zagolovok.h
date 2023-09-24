#pragma once 
#include <iostream>
#include <string>

using namespace std;

extern unsigned short height;

int ReadPersonAge(unsigned short);
string ReadPersonName(string);
void ReadPersonHeight();
void ReadPersonWeight(unsigned short&);
void ReadPersonSalary(double*);
void ReadPersonData(string&, unsigned short&, double&);
void ReadPersonData(string&, unsigned short&, unsigned short&, unsigned short&);
void WritePersonData(string&, const string&, const string&, const unsigned short*, string);