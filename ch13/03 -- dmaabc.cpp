// dma.cpp

#define _CRT_SECURE_NO_WARNINGS
#include "dmaabc.h"
#include <cstring>

ABC::ABC(const char* l, int r)
{
	label = new char[std::strlen(l) + 1];
	std::strcpy(label, l);
	rating = r;
}

ABC::ABC(const ABC& rs)
{
	label = new char[std::strlen(rs.label) + 1];
	std::strcpy(label, rs.label);
	rating = rs.rating;
}

ABC::~ABC()
{
	delete[] label;
}

void ABC::View() const
{
	std::cout << "Label: " << label << std::endl;
	std::cout << "Rating: " << rating << std::endl;
}

ABC& ABC::operator=(const ABC& rs)
{
	if (this == &rs)
		return *this;
	delete[] label;
	label = new char[std::strlen(rs.label) + 1];
	std::strcpy(label, rs.label);
	rating = rs.rating;
	return *this;
}

lacksDMA::lacksDMA(const char* c, const char* l, int r)
	: ABC(l, r)
{
	std::strncpy(color, c, 39);
	color[39] = '\0';
}


lacksDMA::lacksDMA(const char* c, const ABC& a)
	: ABC(a)
{
	std::strncpy(color, c, 39);
	color[39] = '\0';
}

void lacksDMA::View() const
{
	ABC::View();
	std::cout << "Color: " << color << std::endl;
}


hasDMA::hasDMA(const char* s, const char* l, int r)
	: ABC(l, r)
{
	style = new char[std::strlen(s) + 1];
	std::strcpy(style, s);
}

hasDMA::hasDMA(const char* s, const ABC& c)
	: ABC(c)
{
	style = new char[std::strlen(s) + 1];
	std::strcpy(style, s);
}

hasDMA::hasDMA(const hasDMA& hs)
	: ABC(hs)
{
	style = new char[std::strlen(hs.style) + 1];
	std::strcpy(style, hs.style);
}

hasDMA::~hasDMA()
{
	delete[] style;
}

void hasDMA::View() const
{
	ABC::View();
	std::cout << "Style: " << style << std::endl;
}

hasDMA& hasDMA::operator=(const hasDMA& rs)
{
	if (this == &rs)
		return *this;
	ABC::operator=(rs);
	delete[] style;
	style = new char[std::strlen(rs.style) + 1];
	std::strcpy(style, rs.style);
	return *this;
}

