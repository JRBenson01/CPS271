#pragma once


class Account
{
protected:
	double balance = 0.0;
public:
	Account(double bal = 0.0);
	double getBalance();
	void printBalance(char act);
	bool credit(double amt);
	bool debit(double amt);
};

class SavingsAccount : public Account
{
public:
	const double interestRate = 0.01 * 0.01;
	SavingsAccount(double bal = 0.0);
	double calcInterest();
	void credit(double amt);
	void debit(double amt);
};

class CheckingAccount : public Account
{
public:
	const double feeRate = 0.02;
	CheckingAccount(double bal = 0.0);
	double calcFees(double amt);
	void credit(double amt);
	void debit(double amt);
};