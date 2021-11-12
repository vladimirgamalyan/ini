#include "string_split.h"
#include "doctest.h"

TEST_CASE("string_split")
{
	REQUIRE(string_split("foo/bar", "/") == std::vector<std::string>{"foo", "bar"});
	REQUIRE(string_split("foo//bar", "/") == std::vector<std::string>{"foo", "bar"});
	REQUIRE(string_split("foo//bar", "/", false) == std::vector<std::string>{"foo", "", "bar"});
}
