#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "classic.h"

Cd::Cd(const char* s1, const char* s2, int n, double x)
{
	std::strcpy(performers, s1);
	std::strcpy(label, s2);
	selections = n;
	playtime = x;
}

Cd::Cd()
{
	performers[0] = '\0';
	label[0] = '\0';
	selections = 0;
	playtime = 0;
}

void Cd::Report() const
{
	std::cout << "Performers: " << performers << std::endl;
	std::cout << "     Label: " << label << std::endl;
	std::cout << "Selections: " << selections << std::endl;
	std::cout << "  Playtime: " << playtime << std::endl;
}

Classic::Classic(const char* s, const char* s1,
	const char* s2, int n, double x)
	: Cd(s1, s2, n, x)
{
	std::strcpy(mainlabel, s);
}

Classic::Classic()
{
	mainlabel[0] = '\0';
}

void Classic::Report() const
{
	Cd::Report();
	std::cout << " Mainlabel: " << mainlabel << std::endl;
}
