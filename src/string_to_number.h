#pragma once
#include <optional>
#include <string_view>
#include <charconv>
#include <type_traits>

template<class T>
inline std::optional<T> string_to_number(const std::string_view& s)
{
	static_assert(std::is_same<T, long double>::value || std::is_same<T, double>::value
		|| std::is_same<T, float>::value || std::is_same<T, int>::value);
	T result{};
	auto [ptr, ec] { std::from_chars(s.data(), s.data() + s.size(), result) };
	if (ec != std::errc{} || ptr != s.data() + s.size())
		return {};
	return result;
}
