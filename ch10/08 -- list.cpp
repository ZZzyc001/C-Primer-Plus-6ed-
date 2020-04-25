// list.cpp
#include <iostream>
#include "list.h"

List::List()
{
	count = 0;
}

bool List::isfull()
{
	return count == Max;
}

bool List::isempty()
{
	return !count;
}

int List::num()
{
	return count;
}

bool List::additem(const Item& it)
{
	if (count == Max)
	{
		std::cout << "Already full!\n";
		return false;
	}
	items[count++] = it;
	return true;
}

void List::visit(void(*pf)(Item&))
{
	for (int i = 0; i < count; ++i)
		pf(items[i]);
}
