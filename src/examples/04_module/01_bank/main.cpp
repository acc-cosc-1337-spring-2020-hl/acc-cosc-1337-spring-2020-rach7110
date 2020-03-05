#include "bank_account.h"
#include<iostream>
#include<vector>

using std::vector;

using std::cout;


int main()
{	

	// weird that the compiler knows to use the constructor with one parameter.
	BankAccount account_a = 60;
	BankAccount account_b(50);
	// use 'explicit before the constructor to stop this beahvior.
	std::cout << account_a.get_balance();

	BankAccount a;
	display_balance(a);

	std::cout << a; // operator overloading
	std::cin >> a;


	vector<BankAccount> accounts{ BankAccount(100),
		BankAccount(200), BankAccount(300) };

		for (auto act : accounts)
		{
			cout << act.get_balance() << "\n";
		}
	
	BankAccount account(500);
	int balance = account.get_balance();

	cout << "\nBalance: " << balance;

	try 
	{
		account.deposit(-10);
	}
	catch (InvalidAmount e)
	{
		cout << e.get_message();
	}

	return 0;
}