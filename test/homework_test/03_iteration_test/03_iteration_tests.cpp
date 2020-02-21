#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "dna.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test GC content function") {
	string seq1 = "AGCTATAG";
	string seq2 = "CGCTATAG";

	REQUIRE(get_gc_content(seq1) == 0.375);
	REQUIRE(get_gc_content(seq2) == 0.50);
}

TEST_CASE("Test reverse string function") {
	string seq1 = "AGCTATAG";
	string seq2 = "CGCTATAG";

	REQUIRE(get_reverse_string(seq1) == "GATATCGA");
	REQUIRE(get_reverse_string(seq2) == "GATATCGC");
}

TEST_CASE("Test dna compliment function") {
	string seq1 = "AAAACCCGGT";
	string seq2 = "CCCGGAAAAT";

	REQUIRE(get_dna_complement(seq1) == "ACCGGGTTTT");
	REQUIRE(get_dna_complement(seq2) == "ATTTTCCGGG");
}


