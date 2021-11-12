#include "string_trimmer.h"
#include "doctest.h"
#include <string>

static void test_ltrim(const std::string& src, const std::string& expexted)
{
    CHECK(std::string(trim_left<char>(src)) == expexted);
}

static void test_rtrim(const std::string& src, const std::string& expexted)
{
    CHECK(std::string(trim_right<char>(src)) == expexted);
}

static void test_trim(const std::string& src, const std::string& expexted)
{
    CHECK(std::string(trim<char>(src)) == expexted);
}

TEST_CASE("ltrim")
{
    test_ltrim("", "");
    test_ltrim(" ", "");
    test_ltrim("  ", "");
    test_ltrim("foo", "foo");
    test_ltrim(" foo", "foo");
    test_ltrim("  foo", "foo");
    test_ltrim(" f oo", "f oo");
    test_ltrim(" f oo ", "f oo ");
}

TEST_CASE("rtrim")
{
    test_rtrim("", "");
    test_rtrim(" ", "");
    test_rtrim("  ", "");
    test_rtrim("foo", "foo");
    test_rtrim("foo ", "foo");
    test_rtrim("foo  ", "foo");
    test_rtrim("f oo  ", "f oo");
    test_rtrim(" f oo  ", " f oo");
}

TEST_CASE("trim")
{
    test_trim("", "");
    test_trim(" ", "");
    test_trim("  ", "");
    test_trim("foo", "foo");
    test_trim(" foo", "foo");
    test_trim("  foo", "foo");
    test_trim(" f oo", "f oo");
    test_trim("foo ", "foo");
    test_trim(" foo ", "foo");
    test_trim(" f oo ", "f oo");
}
