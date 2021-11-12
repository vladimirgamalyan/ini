#pragma once
#include <algorithm> 
#include <locale>
#include <string_view>

template <class T>
std::basic_string_view<T> string_trim_left(const std::basic_string_view<T>& s, const std::locale& loc = std::locale{ "C" })
{
    return { std::find_if(s.begin(), s.end(), [&loc](T ch) { return !std::isspace(ch, loc); }), s.end() };
}

template <class T>
std::basic_string_view<T> string_trim_right(const std::basic_string_view<T>& s, const std::locale& loc = std::locale{ "C" })
{
    return { s.begin(), std::find_if(s.rbegin(), s.rend(), [&loc](T ch) { return !std::isspace(ch, loc); }).base() };
}

template <class T>
std::basic_string_view<T> string_trim(const std::basic_string_view<T>& s, const std::locale& loc = std::locale{ "C" })
{
    return string_trim_left(string_trim_right(s, loc));
}
