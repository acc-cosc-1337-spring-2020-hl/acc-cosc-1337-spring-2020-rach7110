#include "checking_account.h"
#include "savings_account.h"
#include<iostream>
#include<vector>
#include<functional>

using std::vector;
using std::cout;
using std::reference_wrapper;


int main()
{	
	SavingsAccount s(100);
	CheckingAccount c(100); 

	vector<reference_wrapper<BankAccount>> accounts  {s, c}; // wrapper tells c++ to go to the memory of the child class and work with its methods.

	for (auto account_ref : accounts) {
		cout << account_ref.get().get_balance() << "\n";
	}

	// ****************************

	CheckingAccount a(50), b(10);

	// weird that the compiler knows to use the constructor with one parameter.
	BankAccount account_a = 60;
	BankAccount account_b(50);
	// use 'explicit before the constructor to stop this beahvior.
	std::cout << account_a.get_balance();

	BankAccount account_c;
	display_balance(account_c);

	// std::cout << a; // operator overloading
	// std::cin >> a;


	vector<BankAccount> accts { BankAccount(100),
		BankAccount(200), BankAccount(300) };

		for (auto act : accts)
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