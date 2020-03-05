//bank_account.c
#include "bank_account.h"

using std::cout;

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

double BankAccount::rate = init_rate();  // compiler knows you're in the scope of a class.

void display_balance(const BankAccount & b)
{
	cout << b.balance << "\n";
}

std::ostream & operator<< (std::ostream& out, const BankAccount& b)
{
	out << "\nBalance is : " << b.balance << "\n";

	return out;
}

std::istream & operator>>(std::istream & in, BankAccount & b)
{
	int amount;
	std::cout << "Enter amount to deposit: ";
	in >> amount;
	b.deposit(amount);

	return in;
}
