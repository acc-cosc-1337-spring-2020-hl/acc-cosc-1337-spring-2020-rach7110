#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "vectors.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Function to get max from a vector") {
    vector<int> numbers1 { 3,8,1,99,1000 };
    vector<int> numbers2 { 15,12,11,99,88 };
    vector<int> numbers3 { 150,120,11,990,88888 };

    REQUIRE(get_max_from_vector(numbers1) == 1000);
    REQUIRE(get_max_from_vector(numbers2) == 99);
    REQUIRE(get_max_from_vector(numbers3) == 88888);
}

