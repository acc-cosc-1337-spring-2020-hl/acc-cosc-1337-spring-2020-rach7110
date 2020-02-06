#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "loops.h"
#include "decision.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test gross pay function") {
	REQUIRE(gross_pay(10,15) == 150);
	REQUIRE(gross_pay(5, 20) == 100);
	REQUIRE(gross_pay(20,10) == 200);
	REQUIRE(gross_pay(40, 10) == 400);
	REQUIRE(gross_pay(50,10) == 550);
}

// hours 10 hourly_rate 15 result should be 150
// hours  5 hourly_rate 20 result should be 100
// hours 20 hourly_rate 10 result should be 200

