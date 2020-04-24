// usebank.cpp
#include <iostream>
#include <cstring>
#include "bank.h"
using namespace std;

int main()
{
	cout << "Initial an account with no name:\n";
	BankAccount ba("No Name", "123456", 20);
	ba.show();
	cout << "Deposite $50.0:\n";
	ba.deposite(50.0);
	ba.show();
	cout << "Withdraw $40.0:\n";
	ba.withdraw(40.0);
	ba.show();
	return 0;
}
