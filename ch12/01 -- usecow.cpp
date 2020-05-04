// usecow.cpp
#include <iostream>
#include "cow.h"
using namespace std;

int main()
{
	Cow c1("No name", "No hobby", 10.0);
	c1.ShowCow();
	Cow c2(c1);
	c2.ShowCow();
	Cow c3;
	c3 = c2;
	c3.ShowCow();
	return 0;
}
