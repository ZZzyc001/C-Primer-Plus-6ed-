// golf.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "golf.h"
using namespace std;

Golf::Golf(const char* name, int hc)
{
	strcpy((*this).fullname, name);
	(*this).handicap = hc;
}

int Golf::setgolf()
{
	cout << "Please enter the name: ";
	char name[Len];
	cin.get(name, Len);

	if (!name[0])
		return 0;
	cout << "Please enter the handicap: ";
	int hc;
	cin >> hc;
	cin.get();
	(*this) = Golf(name, hc);
	return 1;
}

void Golf::sethandicap(int hc)
{
	(*this).handicap = hc;
}

void Golf::showgolf() const
{
	cout << "Fullname: " << (*this).fullname << endl;
	cout << "Handicap: " << (*this).handicap << endl;
}
