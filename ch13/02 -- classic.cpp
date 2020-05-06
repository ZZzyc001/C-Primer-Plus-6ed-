#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "classic.h"

Cd::Cd(const char* s1, const char* s2, int n, double x)
{
	performers = new char[std::strlen(s1) + 1];
	label = new char[std::strlen(s2) + 1];
	std::strcpy(performers, s1);
	std::strcpy(label, s2);
	selections = n;
	playtime = x;
}

Cd::Cd(const Cd& d)
{
	performers = new char[std::strlen(d.performers) + 1];
	label = new char[std::strlen(d.label) + 1];
	std::strcpy(performers, d.performers);
	std::strcpy(label, d.label);
	selections = d.selections;
	playtime = d.playtime;
}

Cd::Cd()
{
	performers = nullptr;
	label = nullptr;
	selections = 0;
	playtime = 0;
}

Cd::~Cd()
{
	delete[] performers;
	delete[] label;
}

void Cd::Report() const
{
	std::cout << "Performers: " << performers << std::endl;
	std::cout << "     Label: " << label << std::endl;
	std::cout << "Selections: " << selections << std::endl;
	std::cout << "  Playtime: " << playtime << std::endl;
}

Cd& Cd::operator=(const Cd& d)
{
	if (this == &d)
		return *this;
	delete[] performers;
	delete[] label;
	performers = new char[std::strlen(d.performers) + 1];
	label = new char[std::strlen(d.label) + 1];
	std::strcpy(performers, d.performers);
	std::strcpy(label, d.label);
	selections = d.selections;
	playtime = d.playtime;
}

Classic::Classic(const char* s, const char* s1,
	const char* s2, int n, double x)
	: Cd(s1, s2, n, x)
{
	mainlabel = new char[std::strlen(s) + 1];
	std::strcpy(mainlabel, s);
}

Classic::Classic(const char* s, const Cd& d)
	: Cd(d)
{
	std::strcpy(mainlabel, s);
}

Classic::Classic(const Classic& c) : Cd(c)
{
	mainlabel = new char[std::strlen(c.mainlabel) + 1];
	std::strcpy(mainlabel, c.mainlabel);
}

Classic::Classic()
{
	mainlabel = nullptr;
}

Classic::~Classic()
{
	delete[] mainlabel;
}

void Classic::Report() const
{
	Cd::Report();
	std::cout << " Mainlabel: " << mainlabel << std::endl;
}

Classic& Classic::operator=(const Classic& c)
{
	if (this == &c)
		return *this;
	Cd::operator=(c);
	delete[] mainlabel;
	mainlabel = new char[std::strlen(c.mainlabel) + 1];
	std::strcpy(mainlabel, c.mainlabel);
}
