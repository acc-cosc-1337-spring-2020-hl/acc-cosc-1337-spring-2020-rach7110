//bank_account.h
#include<string>

using std::string;

class BankAccount 
{
	private:
		int balance{ 0 };
		const int min_balance_to_open{ 25 };

	public:
		BankAccount() {};
		// BankAccount() = default;  //Another way to create default constructor
		BankAccount(int b) : balance{ b } {};
		// explicit BankAccount(int b) : balance{ b } {};
		int get_balance()const { return balance; }

		void deposit(int amount);
		void withdraw(int amount);
		void open(int amount);
};

class InvalidAmount
{
	public:
		InvalidAmount(string msg) : message{ msg } {}
		string get_message()const { return message; };

	private:
		string message;
};

