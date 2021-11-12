#pragma once
#include <algorithm> 
#include <locale>
#include <string_view>

template <class CharT>
inline std::basic_string_view<CharT> trim_left(const std::basic_string_view<CharT>& s, const std::locale& loc = std::locale{ "C" })
{
    return { std::find_if(s.begin(), s.end(), [&loc](CharT ch) { return !std::isspace(ch, loc); }), s.end() };
}

template <class CharT>
inline std::basic_string_view<CharT> trim_right(const std::basic_string_view<CharT>& s, const std::locale& loc = std::locale{ "C" })
{
    return { s.begin(), std::find_if(s.rbegin(), s.rend(), [&loc](CharT ch) { return !std::isspace(ch, loc); }).base() };
}

template <class CharT>
inline std::basic_string_view<CharT> trim(const std::basic_string_view<CharT>& s, const std::locale& loc = std::locale{ "C" })
{
    return trim_left(trim_right(s, loc));
}
