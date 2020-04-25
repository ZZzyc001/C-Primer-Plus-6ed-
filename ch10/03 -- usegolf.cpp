// usegolf.cpp

#include <iostream>
#include "golf.h"
using namespace std;

int main()
{
	Golf g1, g2[5];

	cout << "Using setgolf() with entered value:\n";
	g1 = Golf("I'm a people", 20);
	g1.showgolf();

	cout << "Using setgolf() with solicitation:\n";
	int n = 0;
	while (n < 5)
		if (g2[n].setgolf())
			++n;
		else
			break;

	cout << "Using handicap() to revalue g2:\n";
	for (int i = 0; i < n; ++i)
		g2[i].sethandicap(10 * i);

	cout << "Using showgolf() to show g2:\n";
	for (int i = 0; i < n; ++i)
		g2[i].showgolf();

	return 0;
}
