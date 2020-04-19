// usesales.cpp
#include <iostream>
#include "sales.h"

int main()
{
	using namespace std;
	SALES::Sales s1, s2;

	SALES::setSales(s1);
	SALES::showSales(s1);
	SALES::setSales(s2, s1.sales, SALES::QUARTERS);
	SALES::showSales(s2);
	return 0;
}
