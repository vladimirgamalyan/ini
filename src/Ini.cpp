#include "Ini.h"
#include "utils/string/string_trim.h"
#include "utils/string/string_to_number.h"
#include "utils/string/string_split.h"
#include "imemstream.h"

Ini::Ini(std::istream& is)
{
	parse(is);
}

Ini::Ini(const char* data, size_t size)
{
	parse(data, size);
}

Ini::Ini(const std::string_view& s)
{
	parse(s);
}

void Ini::parse(std::istream& is)
{
	sections.clear();

	std::string curSection;
	std::string line;
	while (std::getline(is, line))
	{
		auto stripped_line = string_trim<char>(line);

		if (stripped_line.empty() || stripped_line.front() == ';')
			continue;

		if (stripped_line.front() == '[')
		{
			if (stripped_line.back() != ']')
				throw std::exception();

			curSection = stripped_line.substr(1, stripped_line.length() - 2);
		}
		else
		{
			auto p = stripped_line.find("=");
			if (p == 0 || p == std::string::npos)
				throw std::exception();

			auto key = string_trim_right(stripped_line.substr(0, p));
			auto value = string_trim_left(stripped_line.substr(p + 1));

			sections[curSection][std::string(key)] = value;
		}
	}
}

void Ini::parse(const char* data, size_t size)
{
	imemstream ms(data, size);
	parse(ms);
}

void Ini::parse(const std::string_view& s)
{
	parse(s.data(), s.size());
}

void Ini::dump(std::ostream& os) const
{
	for (auto const& [name, section] : sections)
	{
		os << "[" << name << "]\n";
		for (auto const& [key, value] : section)
			os << key << "=" << value << "\n";
	}
}

const Ini::Section* Ini::getSection(const std::string& section) const
{
	const auto s = sections.find(section);
	if (s == sections.end())
		return nullptr;

	return &s->second;
}

std::optional<std::string> Ini::getValue(const std::string& section, const std::string& key) const
{
	const auto s = sections.find(section);
	if (s == sections.end())
		return {};

	const auto kv = s->second.find(key);
	if (kv == s->second.end())
		return {};

	return kv->second;
}

int Ini::getInt(const std::string& section, const std::string& key, int defaultValue) const
{
	auto v = getValue(section, key);
	if (!v)
		return defaultValue;
	return string_to_number<int>(v.value()).value_or(defaultValue);
}

std::string Ini::getStr(const std::string& section, const std::string& key, const std::string& defaultValue /*= ""*/) const
{
	std::string result = getValue(section, key).value_or(defaultValue);
	if (result.size() >= 2 && result.front() == '\"' && result.back() == '\"')
	{
		result.erase(result.end() - 1);
		result.erase(result.begin());
	}
	return result;
}

bool Ini::getBool(const std::string& section, const std::string& key, bool defaultValue) const
{
	std::string v{ getStr(section, key) };

	if (v == "1" || v == "yes" || v == "true" || v == "on")
		return true;

	if (v == "0" || v == "no" || v == "false" || v == "off")
		return false;

	return defaultValue;
}
