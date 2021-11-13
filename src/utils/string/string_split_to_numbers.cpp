#include "string_split_to_numbers.h"
#include "string_split.h"
#include "string_to_number.h"
#include "string_trim.h"

std::vector<int> string_split_to_numbers(const std::string& s)
{
	auto a = string_split(s, ",", true);

	std::vector<int> result;
	for (std::string s : a)
	{
		auto t = string_to_number<int>(string_trim<char>(s));
		if (t)
			result.push_back(t.value());
	}

	return result;
}
