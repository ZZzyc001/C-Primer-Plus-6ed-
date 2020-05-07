#define _CRT_SECURE_NO_WARNINGS
#include "port.h"
#include <cstring>

Port::Port(const char* br, const char* st, int b)
{
	brand = new char[std::strlen(br) + 1];
	std::strcpy(brand, br);
	std::strncpy(style, st, 19);
	style[19] = '\0';
	bottles = b;
}

Port::Port(const Port& p)
{
	brand = new char[std::strlen(p.brand) + 1];
	std::strcpy(brand, p.brand);
	std::strcpy(style, p.style);
	bottles = p.bottles;
}

Port& Port::operator=(const Port& p)
{
	if (this == &p)
		return *this;
	delete[] brand;
	brand = new char[std::strlen(p.brand) + 1];
	std::strcpy(brand, p.brand);
	std::strcpy(style, p.style);
	bottles = p.bottles;
	return *this;
}

Port& Port::operator+=(int b)
{
	bottles += b;
	return *this;
}

Port& Port::operator-=(int b)
{
	bottles -= b;
	return *this;
}

void Port::Show() const
{
	std::cout << "Brand: " << brand << std::endl;
	std::cout << "Kind: " << style << std::endl;
	std::cout << "Bottles: " << bottles << std::endl;
}

ostream& operator<<(ostream& os, const Port& p)
{
	os << p.brand << ", " << p.style << ", " << p.bottles;
	return os;
}

ostream& operator<<(ostream& os, const VintagePort& vp)
{
	os << (const Port&)vp;
	os << ", " << vp.nickname << ", " << vp.year;
	return os;
}

VintagePort::VintagePort() : Port()
{
	nickname = new char[1];
	nickname[0] = '\0';
	year = 0;
}

VintagePort::VintagePort(const char* br, int b, const char* nn, int y)
	: Port(br, "vintage", b)
{
	nickname = new char[std::strlen(nn) + 1];
	std::strcpy(nickname, nn);
	year = y;
}

VintagePort::VintagePort(const VintagePort& vp)
	: Port(vp)
{
	nickname = new char[std::strlen(vp.nickname) + 1];
	std::strcpy(nickname, vp.nickname);
	year = vp.year;
}

VintagePort& VintagePort::operator=(const VintagePort& vp)
{
	if (this == &vp)
		return *this;
	Port::operator=(vp);
	delete[] nickname;
	nickname = new char[std::strlen(vp.nickname) + 1];
	std::strcpy(nickname, vp.nickname);
	year = vp.year;
}

void VintagePort::Show() const
{
	Port::Show();
	cout << "Nick Name: " << nickname << endl;
	cout << "Year: " << year << endl;
}
