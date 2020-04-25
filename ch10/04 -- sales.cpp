// sales.cpp
#include <iostream>
#include "sales.h"

SALES::Sales::Sales(const double ar[], int n)
{
	sales[0] = average = max = min = ar[0];
	for (int i = 1; i < QUARTERS; ++i)
	{
		if (i <= n)
			sales[i] = ar[i];
		else
			sales[i] = 0.0;
		average += sales[i];
		if (sales[i] > max)
			max = sales[i];
		if (sales[i] < min)
			min = sales[i];
	}

	average /= 4.0;
}

void SALES::Sales::setSales()
{
	using namespace std;
	double ar[QUARTERS];
	int n = 1;
	cout << "Enter sales:\n";
	cout << "sales[" << 1 << "]: ";
	cin >> ar[0];
	for (int i = 1; i < QUARTERS; ++i)
	{
		cout << "sales[" << i + 1 << "]: ";
		if (cin >> ar[i])
			++n;
		else 
			break;
	}
	(*this) = Sales(ar, n);
}

void SALES::Sales::showSales()
{
	using namespace std;
	cout << "sales: ";
	for (int i = 0; i < QUARTERS; ++i)
		cout << sales[i] << " ";
	cout << endl;

	cout << "average: " << average << endl;

	cout << "max: " << max << endl;
	cout << "min: " << min << endl;
}
