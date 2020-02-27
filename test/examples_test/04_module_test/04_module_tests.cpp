#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test BankAcount class) {
	BankAccount account(100);
	REQUIRE_THROWS_AS(account.withdraw(101), InvalidAmount)
}