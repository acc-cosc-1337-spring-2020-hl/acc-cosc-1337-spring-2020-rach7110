//bank_account.h
#ifndef BANK_ACCOUNT_H  // header guards
#define BANK_ACCOUNT_H

#include<iostream>
#include<string>

using std::string;

class BankAccount 
{
	public:
		BankAccount() {};
		// BankAccount() = default;  //Another way to create default constructor
		BankAccount(int b) : balance{ b } {};
		// explicit BankAccount(int b) : balance{ b } {}
        virtual int get_balance()const = 0; // Pure virtual - makes the base class Abstract (cannot instantiate)
        // virtual int get_balance()const { return balance; }  // virutal means the derived overwritten function will be run. Polymorphism. So it doesn't default to the base class.
		void deposit(int amount);
		void withdraw(int amount);
		void open(int amount);
		double get_rate()const { return rate; };
		friend void display_balance(const BankAccount& b); 
		friend std::ostream& operator<<(std::ostream& out, const BankAccount& b);  // operator overloading
		friend std::istream& operator>>(std::istream& in, BankAccount& b);
	
	protected:
		int balance{ 0 };
	
	private:
		const int min_balance_to_open{ 25 };
		static double rate;
		static double init_rate() { return 0.025; };
};

class InvalidAmount
{
	public:
		InvalidAmount(string msg) : message{ msg } {}
		string get_message()const { return message; };

	private:
		string message;
};


#endif
