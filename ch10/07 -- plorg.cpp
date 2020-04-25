// plorg.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "plorg.h"

Plorg::Plorg(const char* ar, int c)
{
	strcpy(name, ar);
	CI = c;
}

void Plorg::setCI(int c)
{
	CI = c;
}

void Plorg::show() const
{
	using std::cout;
	using std::endl;
	cout << "Name: " << name << endl;
	cout << "CI: " << CI << endl;
}
