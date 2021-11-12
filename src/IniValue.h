#pragma once
#include <string>
#include <stdexcept>

class IniValue
{
public:
	explicit IniValue(const std::string& str) : s(str) {}

	// all methods ignore leading whitespaces (as identified by calling std::isspace)

	bool isInt() const
	{
		char* end;
		errno = 0;
		const long l = strtol(s.c_str(), &end, 10);
		return !(errno != 0 || s.empty() || *end != '\0' || l > INT_MAX || l < INT_MIN);
	}

	int asInt() const
	{
		char* end;
		errno = 0;
		const long l = strtol(s.c_str(), &end, 10);
		if (errno != 0 || s.empty() || *end != '\0' || l > INT_MAX || l < INT_MIN)
			throw std::exception();
		return static_cast<int>(l);
	}

	double isDouble() const
	{
		char* end;
		errno = 0;
		strtod(s.c_str(), &end);
		return !(errno != 0 || s.empty() || *end != '\0');
	}

	double asDouble() const
	{
		char* end;
		errno = 0;
		const double f = strtod(s.c_str(), &end);
		if (errno != 0 || s.empty() || *end != '\0')
			throw std::exception();
		return f;
	}

	bool isFloat() const
	{
		char* end;
		errno = 0;
		strtof(s.c_str(), &end);
		return !(errno != 0 || s.empty() || *end != '\0');
	}

	float asFloat() const
	{
		char* end;
		errno = 0;
		const float f = strtof(s.c_str(), &end);
		if (errno != 0 || s.empty() || *end != '\0')
			throw std::exception();
		return f;
	}

private:
	std::string s;
};
