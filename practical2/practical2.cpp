/*
* Name   : practical2_test.cpp
* Purpose: To test the Search Functions
* Author : your name
* Version: 1.0
*/

// Use this definition when providing a user defined main 
#define CATCH_CONFIG_RUNNER

#include "catch.hpp"

#include "Array.h"
#include "Search.h"

/**
* Ordered Search Axioms
*/
TEST_CASE("Ordered Search Axioms", "[SearchOrdered]")
{
	// arrange an ordered 10 element array
	Array<int> oa(10);
	//oa[0] = 5; oa[1] = 10; oa[2] = 13; oa[3] = 21; oa[4] = 21; oa[5] = 29; oa[6] = 34; oa[7] = 38; oa[8] = 45; oa[9] = 60;
	loadFromFile<int>(oa, "ordered.txt");


	SECTION("Binary Search Success")
	{
		//assert that array is ordered
		REQUIRE(isOrdered<int>(oa) == true);

		//assert that 5 is found at position 0
		REQUIRE(binarySearch<int>(oa, 5) == 0);

		// assert that 60 is found at postion 9
		REQUIRE(binarySearch<int>(oa, 60) == 9);
	}

	SECTION("Binary Search Failure")
	{
		//assert that 100 is not found
		REQUIRE(binarySearch<int>(oa, 100) == -1);
	}

	SECTION("Count ordered occurrence exists")
	{
		//assert that 21 occurs twice
		REQUIRE(countOccurrenceOrdered<int>(oa, 21) == 2);
	}

	SECTION("Count ordered occurence non existent")
	{
		//assert that 100 is not found
		REQUIRE(countOccurrenceOrdered<int>(oa, 100) == 0);
	}
}


// UnOrdered Search Axioms
TEST_CASE("UnOrdered Search Axioms", "[SearchUnOrdered]")
{
	// arrange an ordered 10 element array
	Array<int> ua(10);
	ua[0] = 5; ua[1] = 10; ua[2] = 3; ua[3] = 11; ua[4] = 7; ua[5] = 9; ua[6] = 3; ua[7] = 18; ua[8] = 5; ua[9] = 20;

	SECTION("Sequential Search Success")
	{
		//assert that 5 is found at position 0
		REQUIRE(sequentialSearch<int>(ua, 5) == 0);

		// assert that 20 is found at postion 9
		REQUIRE(sequentialSearch<int>(ua, 20) == 9);
	}

	SECTION("Sequential Search Failure")
	{
		//assert that 100 is not found 
		REQUIRE(sequentialSearch<int>(ua, 100) == -1);
	}

	SECTION("Count occurence exists")
	{
		//assert that 3 is found twice
		REQUIRE(countOccurrence<int>(ua, 3) == 2);
	}

	SECTION("Count occurence non-existent")
	{
		//assert that counting occurrence of 100 returns 0
		REQUIRE(countOccurrence<int>(ua, 100) == 0);
	}
}

// UnOrdered Search Axioms
TEST_CASE("UnOrdered String Search Axioms", "[SearchUnOrderedString]")
{
	// arrange an ordered 10 element array
	Array<std::string> ua(5);
	ua[0] = "tue"; ua[1] = "mon"; ua[2] = "sun"; ua[3] = "fri"; ua[4] = "sat";
	//loadFromFile<std::string>(ua, "words.txt");

	SECTION("Sequential Search Success")
	{
		//assert that 5 is found at position 0
		REQUIRE(sequentialSearch<std::string>(ua, "tue") == 0);

		// assert that 20 is found at postion 9
		REQUIRE(sequentialSearch<std::string>(ua, "sat") == 4);
	}

}

// UnOrdered Search All Axioms
TEST_CASE("ContainsAll Search Axioms", "[ContainsAll]")
{
	// arrange an 5 element array
	Array<int> ua(5);
	ua[0] = 3; ua[1] = 2; ua[2] = 9; ua[3] = 7; ua[4] = 6;

	// create the keys array
	Array<int> keys(2);

	SECTION("containsAll Success")
	{
		// populate the keys that are found		
		keys[0] = 2; keys[1] = 6;

		//assert that 2 and 6 are contained in array
		REQUIRE(containsAll<int>(ua, keys) == true);
	}

	SECTION("containsAll Failure")
	{
		// populate the keys that are not found
		keys[0] = 1; keys[1] = 6;

		//assert that 1 and 6 are not contained in array
		REQUIRE(containsAll<int>(ua, keys) == false);
	}

}


// ----------- Main method calls catch and menu ------------

int main(int argc, char* argv[]) {

	// run the tests
	int result = Catch::Session().run(argc, argv);

	// ---------------------------------------------------
	std::cout << std::endl << "Press enter to quit";
	std::cin.get();

	return result;
}

