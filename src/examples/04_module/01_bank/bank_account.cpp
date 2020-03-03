//bank_account.c
#include "bank_account.h"

void BankAccount::deposit(int amount)
{
	if (balance > 0) {
		balance += amount;
	}
	else
	{
		throw InvalidAmount("Balance is negative.");
	}
}

void BankAccount::withdraw(int amount)
{
	if (amount <= 0)
	{
		throw InvalidAmount("Withdraw amount must be greater than zero.");
	}
	else if ( balance - amount < 0 )
	{
		throw InvalidAmount("Not enough money to withdraw tht amount.");
	}
	else
	{
		balance -= amount;
	}
}

void BankAccount::open(int amount)
{ 
	if (balance > 0)
	{
		throw InvalidAmount("Account is already open.");
	}

	if ( amount >= min_balance_to_open)
	{
		balance += amount;
	}
	else
	{
		throw InvalidAmount("A deposit of 25 dollars is required to open.");
	}
}
