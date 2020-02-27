//bank_account.h
#include<string>

using std::string;

class BankAccount 
{
	private:
		int balance;

	public:
		BankAccount(int b) : balance{ b } {};
		int get_balance()const { return balance; }

		void deposit(int amount);
		void withdraw(int amount);
};

class InvalidAmount
{
	public:
		InvalidAmount(string msg) : message{ msg } {}
		string get_message()const { return message; };

	private:
		string message;
};

