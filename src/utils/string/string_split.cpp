#include "string_split.h"
#include "external/doctest.h"

TEST_CASE("string_split")
{
	REQUIRE(string_split("foo/bar", "/") == std::vector<std::string>{"foo", "bar"});
	REQUIRE(string_split("foo//bar", "/") == std::vector<std::string>{"foo", "bar"});
	REQUIRE(string_split("foo//bar", "/", false) == std::vector<std::string>{"foo", "", "bar"});
}

std::vector<std::string> string_split(const std::string_view& s, const std::string_view& delimiters, bool skipEmpty)
{
	std::vector<std::string> result;
	size_t last = 0;
	size_t next = 0;
	std::string_view token;
	while ((next = s.find_first_of(delimiters, last)) != std::string::npos)
	{
		token = s.substr(last, next - last);
		if (!token.empty() || !skipEmpty)
			result.emplace_back(token);
		last = next + 1;
	}
	token = s.substr(last);
	if (!token.empty() || !skipEmpty)
		result.emplace_back(token);
	return result;
}
