#pragma once
#include <istream>
#include <iostream>
#include <string>
#include <map>
#include <optional>
#include "string_trimmer.h"

class Ini
{
public:
	using Section = std::map<std::string, std::string>;

	void parse(std::istream& is)
	{
		sections.clear();

		std::string curSection;
		std::string line;
		while (std::getline(is, line))
		{
			auto stripped_line = trim<char>(line);

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

				auto key = stripped_line.substr(0, p);
				auto value = stripped_line.substr(p + 1);

				sections[curSection][std::string(key)] = value;
			}
		}
	}

	void dump() const
	{
		for (auto const& [name, section] : sections)
		{
			std::cout << "[" << name << "]\n";
			for (auto const& [key, value] : section)
				std::cout << key << "=" << value << "\n";
		}
	}

	const Section* getSection(const std::string& section) const
	{
		const auto s = sections.find(section);
		if (s == sections.end())
			return nullptr;

		return &s->second;
	}

	std::optional<std::string> getValue(const std::string& section, const std::string& key) const
	{
		const auto s = sections.find(section);
		if (s == sections.end())
			return {};

		const auto kv = s->second.find(key);
		if (kv == s->second.end())
			return {};

		return kv->second;
	}

private:
	std::map<std::string, Section> sections;
};
