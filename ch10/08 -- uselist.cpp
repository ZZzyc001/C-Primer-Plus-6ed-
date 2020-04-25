// uselist.cpp
#include <iostream>
#include "list.h"

void addage(Item& it);

int main()
{
	List l;
	Item it{ "No name", 20 };
	l.additem(it);
	std::cout << l.num() << " items in the list\n";
	l.visit(addage);
	return 0;
}

void addage(Item& it)
{
	it.age++;
}
