#pragma once
#include <vector>
#include <string>
#include "string_split.h"
#include "string_to_number.h"
#include "string_trim.h"

template<class T>
std::vector<T> string_split_to_numbers(const std::string_view& s)
{
	std::vector<T> result;
	for (std::string i : string_split(s, ",", true))
		if (auto t = string_to_number<T>(string_trim<char>(i)))
			result.push_back(t.value());
	return result;
}
