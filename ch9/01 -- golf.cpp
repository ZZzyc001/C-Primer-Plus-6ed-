// golf.cpp

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "golf.h"
using namespace std;

void setgolf(golf& g, const char* name, int hc)
{
	strcpy(g.fullname, name);
	g.handicap = hc;
}

int setgolf(golf& g)
{
	cout << "Please enter the name: ";
	cin.get(g.fullname, Len);

	if (!g.fullname[0])
		return 0;
	cout << "Please enter the handicap: ";
	cin >> g.handicap;
	cin.get();
	return 1;
}

void handicap(golf& g, int hc)
{
	g.handicap = hc;
}

void showgolf(const golf& g)
{
	cout << "Fullname: " << g.fullname << endl;
	cout << "Handicap: " << g.handicap << endl;
}
