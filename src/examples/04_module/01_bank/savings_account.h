//savings_account.h
#include<iostream>
#include "bank_account.h"

using std::cout;

class SavingsAccount : public BankAccount
{
public:
	SavingsAccount() = default;
	SavingsAccount(int b) : BankAccount(b) {};
	int get_balance() const {
        cout << "Derived class method called.";
        
        return balance + (1 / 12 * 1.025);}
};
