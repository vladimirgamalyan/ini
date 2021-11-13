#pragma once
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <optional>

class Ini
{
public:
	using Section = std::map<std::string, std::string>;

	void parse(std::istream& is);
	void parse(const char* data, size_t size);
	void parse(const std::string_view& s);
	void dump(std::ostream& os) const;
	const Section* getSection(const std::string& section) const;
	std::optional<std::string> getValue(const std::string& section, const std::string& key) const;
	int getInt(const std::string& section, const std::string& key, int defaultValue) const;
	std::string getStr(const std::string& section, const std::string& key, const std::string& defaultValue = "") const;
	bool getBool(const std::string& section, const std::string& key, bool defaultValue) const;

private:
	std::map<std::string, Section> sections;
};
