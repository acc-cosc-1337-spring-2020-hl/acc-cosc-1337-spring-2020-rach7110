#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "bank_account.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test BankAcount class") {
	BankAccount account(100);
	REQUIRE_THROWS_AS(account.withdraw(101), InvalidAmount);
}

TEST_CASE("TEST DEFAULT CONSTRUCTOR FOR BALANCE EQUALS 0") {
	BankAccount account;

	REQUIRE(account.get_balance() == 0);
}

TEST_CASE("Test default constructor open account") {
	BankAccount account;
	REQUIRE(account.get_balance() == 0);

	account.open(25);
	REQUIRE(account.get_balance() == 25);
}

TEST_CASE("Test default constructor account already open") {
	BankAccount account(50);

	REQUIRE_THROWS_AS(account.open(25), InvalidAmount);
}

TEST_CASE("Test default constructor open account with less than 25.") {
	BankAccount account;

	REQUIRE_THROWS_AS(account.open(20), InvalidAmount);
}

TEST_CASE("Test bank account get_rate") {
	BankAccount account;

	REQUIRE(account.get_rate() == 0.025);
}

