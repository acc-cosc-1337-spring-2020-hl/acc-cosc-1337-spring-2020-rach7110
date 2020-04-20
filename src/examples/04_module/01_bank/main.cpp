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
    // Raw pointers (Legacy C++):
//    BankAccount *b = new SavingsAccount(1000);
//    cout << (*b).get_balance();
//    cout << b->get_balance(); // Structure pointer operator. Equivalent to line above, but eaiser to read.
//
//    delete b;
//    b = nullptr;
    
    // Unique Pointers:
    unique_ptr<BankAccount> s = make_unique<SavingsAccount>(90);  // heap variable
    unique_ptr<BankAccount> c = make_unique<CheckingAccount>(100);
    
    std::vector<unique_ptr<BankAccount> > accounts;
//    accounts.push_back(s);  // Errors because s can only have one owner.
    accounts.push_back(std::move(s));  // Fixes error in line above.
    accounts.push_back(std::move(c));
    
    for (auto &account : accounts)
    {
        cout << account.get()->get_balance() << "\n";
        cout << account->get_balance() << "\n"; // Works as line above.
    }
    

// Inheritence & Reference Wrapper:
//    SavingsAccount s(100);
//    CheckingAccount c(100);

    //  Reference wrapper tells c++ to go to the memory of the child class and work with its methods.
//	vector<reference_wrapper<BankAccount>> accounts  {s, c};

//	for (auto account_ref : accounts) {
//		cout << account_ref.get().get_balance() << "\n";
//	}

	return 0;
}
