// usegolf.cpp

#include <iostream>
#include "golf.h"
using namespace std;

int main()
{
	golf g1, g2[5];

	cout << "Using setgolf() with entered value:\n";
	setgolf(g1, "I'm a people", 20);
	showgolf(g1);

	cout << "Using setgolf() with solicitation:\n";
	int n = 0;
	while (n < 5)
		if (setgolf(g2[n]))
			++n;
	        else
		        break;
		
	cout << "Using handicap() to revalue g2:\n";
	for (int i = 0; i < n; ++i)
		handicap(g2[i], 10 * i);

	cout << "Using showgolf() to show g2:\n";
	for (int i = 0; i < n; ++i)
		showgolf(g2[i]);

	return 0;
}
