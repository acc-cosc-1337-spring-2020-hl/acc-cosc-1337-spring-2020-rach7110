#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "dna.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test GC contentn function") {
	string seq1 = "AGCTATAG";
	string seq2 = "CGCTATAG";

	REQUIRE(get_gc_content(seq1) == 0.375);
	REQUIRE(get_gc_content(seq2) == 0.50);
}


