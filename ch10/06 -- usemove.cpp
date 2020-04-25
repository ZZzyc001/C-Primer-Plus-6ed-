// usemove.cpp
#include <iostream>
#include "move.h"
using namespace std;

int main()
{
	Move m1(1.3, 2.4);
	Move m2(2.6, 4.8);
	m1.showmove();
	m2.showmove();
	m1 = m1.add(m2);
	m1.showmove();
	m1.reset(5.2, 12.0);
	m1.showmove();
	return 0;
}
