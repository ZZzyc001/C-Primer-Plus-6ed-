// bank.h
#ifndef BANK_H_
#define BANK_H_

class BankAccount
{
private:
	char name[40];
	char acctnum[25];
	double balance;
public:
	BankAccount(const char* client, const char* num, double bal = 0.0);
	void show() const;
	void deposite(double cash);
	void withdraw(double cash);
};
#endif
