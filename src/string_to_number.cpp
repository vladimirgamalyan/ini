#include "string_to_number.h"
#include "doctest.h"

TEST_CASE("string_to_number")
{
	REQUIRE(!string_to_number<int>(""));
	REQUIRE(!string_to_number<int>(" "));
	REQUIRE(!string_to_number<int>("42 "));
	REQUIRE(!string_to_number<int>(" 42"));
	REQUIRE(!string_to_number<int>(" 42 "));
	REQUIRE(!string_to_number<int>("a"));
	REQUIRE(!string_to_number<int>(" a"));
	REQUIRE(!string_to_number<int>("a "));
	REQUIRE(!string_to_number<int>(" a "));
	REQUIRE(!string_to_number<int>("42 42"));
	REQUIRE(!string_to_number<int>("4a2"));

	REQUIRE(string_to_number<int>("42"));
	REQUIRE(string_to_number<int>("42").value() == 42);
}
