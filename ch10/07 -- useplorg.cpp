// useplorg.cpp
#include <iostream>
#include "plorg.h"
using namespace std;

int main()
{
	Plorg p;
	p.show();
	Plorg p1("no name", 30);
	p1.show();
	p.setCI(60);
	p.show();
	return 0;
}
