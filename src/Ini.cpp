#include "Ini.h"
#include <iostream>
#include "string_trimmer.h"

void Ini::parse(std::istream& is)
{
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

void Ini::dump()
{
	for (auto const& [name, section] : sections)
	{
		std::cout << "[" << name << "]\n";
		for (auto const& [key, value] : section)
			std::cout << key << "=" << value << "\n";
	}
}
