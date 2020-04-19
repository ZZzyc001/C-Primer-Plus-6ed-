// sales.cpp
#include <iostream>
#include "sales.h"

void SALES::setSales(Sales& s, const double ar[], int n)
{
	s.sales[0] = s.average = s.max = s.min = ar[0];
	for (int i = 1; i < QUARTERS; ++i)
	{
		if (i <= n)
			s.sales[i] = ar[i];
		else
			s.sales[i] = 0.0;
		s.average += s.sales[i];
		if (s.sales[i] > s.max)
			s.max = s.sales[i];
		if (s.sales[i] < s.min)
			s.min = s.sales[i];
	}

	s.average /= 4.0;
}

void SALES::setSales(Sales& s)
{
    using namespace std;
    cout << "Enter sales:\n";
	cout << "sales[" << 1 << "]: ";
	cin >> s.sales[0];
	s.average = s.max = s.min = s.sales[0];
	for (int i = 1; i < QUARTERS; ++i)
    {
        cout << "sales[" << i + 1 << "]: ";
        cin >> s.sales[i];
		s.average += s.sales[i];
		if (s.sales[i] > s.max)
			s.max = s.sales[i];
		if (s.sales[i] < s.min)
			s.min = s.sales[i];
	}
	s.average /= 4.0;
}

void SALES::showSales(const Sales& s)
{
	using namespace std;
	cout << "sales: ";
	for (int i = 0; i < QUARTERS; ++i)
		cout << s.sales[i] << " ";
	cout << endl;

	cout << "average: " << s.average << endl;

	cout << "max: " << s.max << endl;
	cout << "min: " << s.min << endl;
}
