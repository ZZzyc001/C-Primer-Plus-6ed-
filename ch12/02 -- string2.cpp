// strng1.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <cctype>
#include "string2.h"
using std::cin;
using std::cout;

int String::num_strings = 0;

int String::Howmany()
{
	return num_strings;
}

String::String(const char* s)
{
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	num_strings++;
}

String::String()
{
	len = 4;
	str = new char[4];
	str[0] = '\0';
	num_strings++;
}

String::String(const String& st)
{
	num_strings++;
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
}

String::~String()
{
	--num_strings;
	delete[] str;
}

void String::stringlow()
{
	for (int i = 0; i < len; ++i)
		str[i] = std::tolower(str[i]);
}

void String::stringup()
{
	for (int i = 0; i < len; ++i)
		str[i] = std::toupper(str[i]);
}

int String::has(char ch) const
{
	int ans = 0;
	for (int i = 0; i < len; ++i)
		if (str[i] == ch)
			++ans;
	return ans;
}

String& String::operator=(const String& st)
{
	if (this == &st)
		return *this;
	delete[] str;
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
	return *this;
}

String& String::operator=(const char* s)
{
	delete[] str;
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	return *this;
}

String String::operator+(const String& s) const
{
	int lent = len + s.len;
	char* temp = new char[lent + 1];
	std::strcpy(temp, str);
	std::strcat(temp, s.str);
	String ts = temp;
	delete[] temp;
	return ts;
}

String String::operator+(const char* ar) const
{
	int lent = len + std::strlen(ar);
	char* temp = new char[lent + 1];
	std::strcpy(temp, str);
	std::strcat(temp, ar);
	String ts = temp;
	delete[] temp;
	return ts;
}

char& String::operator[](int i)
{
	return str[i];
}

const char& String::operator[](int i) const
{
	return str[i];
}


String operator+(const char* ar, const String& st)
{
	int lent = st.len + std::strlen(ar);
	char* temp = new char[lent + 1];
	std::strcpy(temp, ar);
	std::strcat(temp, st.str);
	String ts = temp;
	delete[] temp;
	return ts;
}

bool operator<(const String& st1, const String& st2)
{
	return (std::strcmp(st1.str, st2.str) < 0);
}

bool operator>(const String& st1, const String& st2)
{
	return st2 < st1;
}

bool operator==(const String& st1, const String& st2)
{
	return (std::strcmp(st1.str, st2.str) == 0);
}

ostream& operator<<(ostream& os, const String& st)
{
	os << st.str;
	return os;
}

istream& operator>>(istream& is, String& st)
{
	char temp[String::CINLIM];
	is.get(temp, String::CINLIM);
	if (is)
		st = temp;
	while (is && is.get() != '\n')
		continue;
	return is;
}
