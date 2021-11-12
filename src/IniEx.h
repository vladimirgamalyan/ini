#pragma once
#include "Ini.h"
#include <vector>
#include "utils/string_to_number.h"
#include "utils/string_split.h"

class IniEx : public Ini
{
public:
	int getInt(const std::string& section, const std::string& key, int defaultValue) const
	{
		auto v = getValue(section, key);
		if (!v)
			return defaultValue;
		return string_to_number<int>(v.value()).value_or(defaultValue);
	}

	std::string getStr(const std::string& section, const std::string& key, const std::string& defaultValue = "") const
	{
		return getValue(section, key).value_or(defaultValue);
	}

	bool getBool(const std::string& section, const std::string& key, bool defaultValue) const
	{
		std::string v{ getStr(section, key) };

		if (v == "1" || v == "yes" || v == "true" || v == "on")
			return true;

		if (v == "0" || v == "no" || v == "false" || v == "off")
			return false;

		return defaultValue;
	}

	std::vector<int> getIntArray(const std::string& section, const std::string& key) const
	{
		auto v = getValue(section, key);
		if (!v)
			return {};
		
		auto a = string_split(v.value(), ",",  true);

		std::vector<int> result;
		for (std::string s : a)
		{
			auto t = string_to_number<int>(std::string(string_trim<char>(s)));
			if (t)
				result.push_back(t.value());
		}

		return result;
	}

private:

};
