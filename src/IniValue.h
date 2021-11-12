#pragma once
#include <string>
#include <stdexcept>

//TODO: memorize all computations (on first request)
class IniValue
{
public:
	explicit IniValue(const std::string& str) : s(str) {}

	bool isInt() const
	{
		char* end;
		errno = 0;
		long l = strtol(s.c_str(), &end, 10);
		return !(errno != 0 || l > INT_MAX || l < INT_MIN || s.empty() || *end != '\0');
	}

	int asInt() const
	{
		char* end;
		errno = 0;
		long l = strtol(s.c_str(), &end, 10);
		if (errno)
		{
			if (errno == ERANGE || l > INT_MAX || l < INT_MIN)
				throw std::out_of_range("IniValue::asInt: out of range");
			throw std::invalid_argument("IniValue::asInt: other error");
		}

		if (s.empty() || *end != '\0')
			throw std::invalid_argument("IniValue::asInt: invalid string");

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
		double f = strtod(s.c_str(), &end);
		if (errno)
		{
			if (f == HUGE_VAL || f == -HUGE_VAL)
				throw std::out_of_range("IniValue::asDouble: out of range");
			throw std::invalid_argument("IniValue::asDouble: underflow or other error");
		}

		if (s.empty() || *end != '\0')
			throw std::invalid_argument("IniValue::asDouble: invalid string");

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
		float f = strtof(s.c_str(), &end);
		if (errno)
		{
			if (f == HUGE_VALF || f == -HUGE_VALF)
				throw std::out_of_range("IniValue::asFloat: out of range");
			throw std::invalid_argument("IniValue::asFloat: underflow or other error");
		}

		if (s.empty() || *end != '\0')
			throw std::invalid_argument("IniValue::asFloat: invalid string");

		return f;
	}

private:
	std::string s;
};
