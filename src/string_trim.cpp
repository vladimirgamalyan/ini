#include "string_trim.h"
#include "doctest.h"
#include <string>

static void test_string_trim_left(const std::string& src, const std::string& expexted)
{
    REQUIRE(std::string(string_trim_left<char>(src)) == expexted);
}

static void test_string_trim_right(const std::string& src, const std::string& expexted)
{
    REQUIRE(std::string(string_trim_right<char>(src)) == expexted);
}

static void test_string_trim(const std::string& src, const std::string& expexted)
{
    REQUIRE(std::string(string_trim<char>(src)) == expexted);
}

TEST_CASE("test_string_trim_left")
{
    test_string_trim_left("", "");
    test_string_trim_left(" ", "");
    test_string_trim_left("  ", "");
    test_string_trim_left("foo", "foo");
    test_string_trim_left(" foo", "foo");
    test_string_trim_left("  foo", "foo");
    test_string_trim_left(" f oo", "f oo");
    test_string_trim_left(" f oo ", "f oo ");
}

TEST_CASE("test_string_trim_right")
{
    test_string_trim_right("", "");
    test_string_trim_right(" ", "");
    test_string_trim_right("  ", "");
    test_string_trim_right("foo", "foo");
    test_string_trim_right("foo ", "foo");
    test_string_trim_right("foo  ", "foo");
    test_string_trim_right("f oo  ", "f oo");
    test_string_trim_right(" f oo  ", " f oo");
}

TEST_CASE("test_string_trim")
{
    test_string_trim("", "");
    test_string_trim(" ", "");
    test_string_trim("  ", "");
    test_string_trim("foo", "foo");
    test_string_trim(" foo", "foo");
    test_string_trim("  foo", "foo");
    test_string_trim(" f oo", "f oo");
    test_string_trim("foo ", "foo");
    test_string_trim(" foo ", "foo");
    test_string_trim(" f oo ", "f oo");
}
