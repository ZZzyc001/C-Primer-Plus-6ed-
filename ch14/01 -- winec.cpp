#include "winec.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

Wine::Wine(const char* l, int y, const int yr[], const int bot[])
	: s(l), num(y)
{
	ar.first() = std::valarray<int>(y);
	ar.second() = std::valarray<int>(y);
	for (int i = 0; i < y; ++i)
		ar.first()[i] = yr[i];
	for (int i = 0; i < y; ++i)
		ar.second()[i] = bot[i];
}

Wine::Wine(const char* l, int y)
	: s(l), num(y)
{
	ar.first() = std::valarray<int>(y);
	ar.second() = std::valarray<int>(y);
}

void Wine::GetBottles()
{
	cout << "Enter " << s << " data for " << num << " year(s):\n";
	for (int i = 0; i < num; ++i)
	{
		cout << "Enter year: ";
		cin >> ar.first()[i];
		cout << "Enter bottles for that year: ";
		cin >> ar.second()[i];
	}
}

const std::string& Wine::Lable() const
{
	return s;
}

int Wine::sum() const
{
	return ar.second().sum();
}

void Wine::Show() const
{
	cout << "Wine: " << s << endl;
	cout << "        Year    Bottles\n";
	for (int i = 0; i < num; ++i)
		cout << "        " << ar.first()[i] << "    " << ar.second()[i] << endl;
}
