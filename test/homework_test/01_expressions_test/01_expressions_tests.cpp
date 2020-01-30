#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "expressions.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Verify sum_numbers function") 
{
	REQUIRE(add_numbers(5, 5) == 10);
	REQUIRE(add_numbers(10, 10) == 20);
}

TEST_CASE("Verify multiplication numbers function")
{
	REQUIRE(multiply_numbers(5, 5) == 25);
	REQUIRE(multiply_numbers(5, 5) != 5*5);
	REQUIRE(multiply_numbers(2, 0) == 0);
	REQUIRE(multiply_numbers(2, -5) == -10);
}

