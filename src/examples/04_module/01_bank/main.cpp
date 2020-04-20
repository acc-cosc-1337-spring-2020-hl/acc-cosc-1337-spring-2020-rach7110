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

    // wrapper tells c++ to go to the memory of the child class and work with its methods.
	vector<reference_wrapper<BankAccount>> accounts  {s, c};

	for (auto account_ref : accounts) {
		cout << account_ref.get().get_balance() << "\n";
	}

	return 0;
}
