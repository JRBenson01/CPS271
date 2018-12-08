#pragma once
#include "Account.h"
#include <iostream>

using namespace std;

Account::Account(double bal) : balance(bal)
{
	cout << "Account Opened with a starting balance of $" << bal << endl;
}

double Account::getBalance()
{
	return balance;
}

void Account::printBalance(char act)
{
	if (act == 's')
		cout << "Savings ";
	else if (act == 'c')
		cout << "Checking ";
	cout << "Account Balance: $" << balance << endl << endl;
}

bool Account::credit(double amt)
{
	if (amt < 0.0)
	{
		cout << "ERROR: Credit transaction amount was negative." << endl;
		return false;
	}
	balance += amt;
	return true;
}

bool Account::debit(double amt)
{
	if (amt < 0.0)
	{
		cout << "ERROR: Debit transaction amount was negative." << endl;
		return false;
	}
	if (balance > amt)
	{
		balance -= amt;
		return true;
	}
	return false;
}


SavingsAccount::SavingsAccount(double bal) : Account(bal)
{
	
}

double SavingsAccount::calcInterest()
{
	return balance * interestRate;
}

void SavingsAccount::credit(double amt)
{
	if (Account::credit(amt))
	{
		balance += calcInterest();
		cout << "$" << amt << " added to Savings Account." << endl;
	}
	else
	{
		cout << "ERROR: Transaction in Savings Account didn't go through." << endl;
	}
	printBalance('s');
}

void SavingsAccount::debit(double amt)
{
	if (Account::debit(amt))
	{
		cout << "$" << amt << " withdrawn from Savings Account." << endl;
	}
	else
	{
		cout << "ERROR: Debit amount exceeded account balance." << endl;
	}
	printBalance('s');
}


CheckingAccount::CheckingAccount(double bal) : Account(bal)
{
	
}

double CheckingAccount::calcFees(double amt)
{
	return amt * feeRate;
}

void CheckingAccount::credit(double amt)
{
	if (Account::credit(amt))
	{
		balance -= calcFees(amt);
		cout << "$" << amt << " added to Checking account. Transaction fee: $" << calcFees(amt) << endl;
	}
	else
	{
		cout << "ERROR: Transaction in Checking Account did not go through." << endl;
	}
	printBalance('c');
}

void CheckingAccount:: debit(double amt)
{
	if (Account::debit(amt))
	{
		if (balance > calcFees(amt))
		{
			balance -= calcFees(amt);
			cout << "$" << amt << " withdrawn from Checking account. Transaction fee: $" << calcFees(amt) << endl;
		}
		else
		{
			balance += amt;
			cout << "ERROR: Additional fees exceed account balance in Savings Account." << endl;
		}
	}
	else
	{
		cout << "ERROR: Withdraw amount exceeds Checking Account balance." << endl;
	}
	printBalance('c');
}