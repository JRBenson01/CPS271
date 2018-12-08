#include "Account.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	cout << fixed << setprecision(2);

	CheckingAccount CA(500.0);
	SavingsAccount SA(1000.0);

	CA.debit(230.0);
	SA.debit(100.85);

	CA.credit(400.25);
	CA.credit(250.0);

	SA.credit(500.0);

	CA.debit(2000.0);
	SA.debit(1000.0);
	SA.debit(1500.0);

	SA.credit(-500.0);

	return 0;
}
/*
Checking Starting Balance	500.00
Savings Starting Balance	1000.00
Withdraw from Checking	230.00
Withdraw from Savings	100.85
Deposit into Checking	400.25
Deposit into Checking	250.00
Deposit into Savings	500.00
Withdraw from Checking	2000.00
Withdraw from Savings	1000.00
Withdraw from Savings	1500.00
Deposit into Savings   -500.00
*/