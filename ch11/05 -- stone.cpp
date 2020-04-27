// stone.cpp
#include "stonewt.h"
using std::cout;
int main()
{
	Stonewt incognito = 275;
	Stonewt wolfe(287.5);
	Stonewt taft(21, 8);

	cout << "The celebrity weighed ";
	incognito.STNmode();
	cout << incognito << std::endl;
	cout << "The detective weighed ";
	wolfe.STNmode();
	cout << wolfe << std::endl;
	cout << "The President weighed ";
	cout << taft << std::endl;
	cout << "The celebrity and the detective weighed ";
	cout << incognito + wolfe << std::endl;
	cout << "The celebrity is heavier than the detective ";
	cout << incognito - wolfe << std::endl;
	cout << "When celebrity become twice heavy ";
	cout << 2 * incognito << std::endl;
	cout << "It's as same as ";
	cout << incognito * 2 << std::endl;
	return 0;
}
