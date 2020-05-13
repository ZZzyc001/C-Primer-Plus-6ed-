// person.cpp
#include <iostream>
#include <string>
#include "person.h"

using std::cin;
using std::cout;
using std::endl;

Person::~Person() {}

void Person::Data() const
{
	cout << "First name: " << firstname << endl;
	cout << "Last name: " << lastname << endl;
}

void Person::Get()
{
	cout << "Enter first name: ";
	getline(cin, firstname);
	cout << "Enter last name: ";
	getline(cin, lastname);
}

void Gunslinger::Data() const
{
	cout << "Draw: " << draw << endl;
	cout << "Marks: " << mark << endl;
}

void Gunslinger::Get()
{
	cout << "Enter the Draw: ";
	cin >> draw;
	cout << "Enter the number of marks: ";
	cin >> mark;
}

void Gunslinger::Show() const
{
	cout << "This is a Gunslinger\n";
	Person::Data();
	Data();
}

void Gunslinger::Set()
{
	cout << "This is a Gunslinger\n";
	Person::Get();
	Get();
}

void PokerPlayer::Data() const
{
	cout << "Card: " << num << endl;
}

void PokerPlayer::Get()
{
	num = rand() % 52 + 1;
}

void PokerPlayer::Set()
{
	cout << "This is a poker player\n";
	Person::Get();
	Get();
}

void PokerPlayer::Show() const
{
	cout << "This is a poker player\n";
	Person::Data();
	Data();
}

void BadDude::Data() const
{
	Gunslinger::Data();
	PokerPlayer::Data();
}

void BadDude::Get()
{
	Gunslinger::Get();
	PokerPlayer::Get();
}

void BadDude::Set()
{
	cout << "This is a bad dude\n";
	Person::Get();
	Get();
}

void BadDude::Show() const
{
	cout << "This is a bad dude\n";
	Person::Data();
	Data();
}
