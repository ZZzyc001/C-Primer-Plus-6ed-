// list.h
#ifndef LIST_H_
#define LIST_H_
#include <string>
const int Max = 40;
struct people
{
	std::string name;
	int age;
};

typedef people Item;

class List
{
private:
	Item items[Max];
	int count;
public:
	List();
	bool isfull();
	bool isempty();
	int num();
	bool additem(const Item& it);
	void visit(void (*pf) (Item&));
};
#endif
