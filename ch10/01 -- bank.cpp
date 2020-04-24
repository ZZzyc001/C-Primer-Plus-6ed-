// bank.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include "bank.h"

BankAccount::BankAccount(const char* client, const char* num, double bal)
{
	strncpy(name, client, 39);
	name[39] = '\0';
	strncpy(acctnum, num, 24);
	acctnum[24] = '\0';
	balance = bal;
}

void BankAccount::show() const
{
	std::cout << "Name: " << name << std::endl;
	std::cout << "Acctnum: " << acctnum << std::endl;
	std::cout << "Balance: " << balance << std::endl;
}

void BankAccount::deposite(double cash)
{
	balance += cash;
}

void BankAccount::withdraw(double cash)
{
	balance -= cash;
}
