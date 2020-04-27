// stone.cpp
#include <iostream>
using std::cout;
#include "stonewt.h"
int main()
{
	Stonewt ar[6] = { 275, 287.5, Stonewt(21, 8) };
	
	double tep;
	cout << "Enter the last three items: ";
	for (int i = 4; i <= 6; ++i)
	{
		cout << "The " << i - 1 << ": ";
		std::cin >> tep;
		ar[i - 1] = tep;
	}

	Stonewt max = ar[0], min = ar[0], cmp = 11;
	int num = 0;
	if (ar[0] >= cmp) ++num;
	for (int i = 1; i < 6; ++i)
	{
		if (ar[i] > max) max = ar[i];
		if (ar[i] < min) min = ar[i];
		if (ar[i] >= cmp) ++num;
	}

	cout << "The max item: ";
	max.show_lbs();
	cout << "The minimum item: ";
	min.show_lbs();
	cout << "The num not less than 11 pounds: ";
	cout << num << std::endl;

	return 0;
}
