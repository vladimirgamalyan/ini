#include "string_converter.h"
#include "doctest.h"

TEST_CASE("toInt")
{
	CHECK(!string_to_number<int>(""));
	CHECK(!string_to_number<int>(" "));
	CHECK(!string_to_number<int>("42 "));
	CHECK(!string_to_number<int>(" 42"));
	CHECK(!string_to_number<int>(" 42 "));
	CHECK(!string_to_number<int>("a"));
	CHECK(!string_to_number<int>(" a"));
	CHECK(!string_to_number<int>("a "));
	CHECK(!string_to_number<int>(" a "));
	CHECK(!string_to_number<int>("42 42"));
	CHECK(!string_to_number<int>("4a2"));

	CHECK(string_to_number<int>("42"));
	CHECK(string_to_number<int>("42").value() == 42);
}
