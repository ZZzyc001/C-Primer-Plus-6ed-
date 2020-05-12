#include "winec.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

Wine::Wine(const char* l, int y, const int yr[], const int bot[])
	: std::string(l), num(y)
{
	PairArray::first() = std::valarray<int>(y);
	PairArray::second() = std::valarray<int>(y);
	for (int i = 0; i < y; ++i)
		PairArray::first()[i] = yr[i];
	for (int i = 0; i < y; ++i)
		PairArray::second()[i] = bot[i];
}

Wine::Wine(const char* l, int y)
	: std::string(l), num(y)
{
	PairArray::first() = std::valarray<int>(y);
	PairArray::second() = std::valarray<int>(y);
}

void Wine::GetBottles()
{
	cout << "Enter " << (const std::string&)(*this) << " data for " << num << " year(s):\n";
	for (int i = 0; i < num; ++i)
	{
		cout << "Enter year: ";
		cin >> PairArray::first()[i];
		cout << "Enter bottles for that year: ";
		cin >> PairArray::second()[i];
	}
}

const std::string& Wine::Lable() const
{
	return (const std::string&)(*this);
}

int Wine::sum() const
{
	return PairArray::second().sum();
}

void Wine::Show() const
{
	cout << "Wine: " << (const std::string&)(*this) << endl;
	cout << "        Year    Bottles\n";
	for (int i = 0; i < num; ++i)
		cout << "        " << PairArray::first()[i]
		<< "    " << PairArray::second()[i] << endl;
}
