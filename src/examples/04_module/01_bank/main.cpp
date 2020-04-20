#include "checking_account.h"
#include "savings_account.h"
#include<iostream>
#include<vector>
#include<functional>
#include<memory>

using std::vector;
using std::cout;
using std::reference_wrapper;
using std::unique_ptr;
using std::make_unique;

int main()
{	
    SavingsAccount sa(200);
    cout << "Savings Account balance: " << sa.get_balance();
    unique_ptr<BankAccount> s = make_unique<SavingsAccount>(90);
    
    cout << s->get_balance();
    

// Inheritence & Reference Wrapper
//    SavingsAccount s(100);
//    CheckingAccount c(100);

    //  Reference wrapper tells c++ to go to the memory of the child class and work with its methods.
//	vector<reference_wrapper<BankAccount>> accounts  {s, c};

//	for (auto account_ref : accounts) {
//		cout << account_ref.get().get_balance() << "\n";
//	}

	return 0;
}
