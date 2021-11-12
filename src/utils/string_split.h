#pragma once
#include <vector>
#include <string>

inline std::vector<std::string> string_split(const std::string& s, const std::string& delimiters, bool skipEmpty = true)
{
	std::vector<std::string> result;
	size_t last = 0;
	size_t next = 0;
	std::string token;
	while ((next = s.find_first_of(delimiters, last)) != std::string::npos)
	{
		token = s.substr(last, next - last);
		if (!token.empty() || !skipEmpty)
			result.push_back(token);
		last = next + 1;
	}
	token = s.substr(last);
	if (!token.empty() || !skipEmpty)
		result.push_back(token);
	return result;
}
