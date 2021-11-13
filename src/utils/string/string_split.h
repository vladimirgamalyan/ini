#pragma once
#include <vector>
#include <string>
#include <string_view>

std::vector<std::string> string_split(const std::string_view& s, const std::string_view& delimiters, bool skipEmpty = true);
