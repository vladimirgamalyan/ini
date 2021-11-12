#pragma once
#include <istream>
#include <string>
#include <map>

class Ini
{
public:
	using Section = std::map<std::string, std::string>;

	void parse(std::istream& is);
	void dump();

	const Section& getSection(const std::string& section) const
	{
		return sections.at(section);
	}
	std::string getValue(const std::string& section, const std::string& key) const
	{
		return sections.at(section).at(key);
	}
private:
	std::map<std::string, Section> sections;
};
