#include "IniValue.h"
#include "doctest.h"

//TODO: unit tests for all types

TEST_CASE("IniValue::isInt")
{
	CHECK(!IniValue("").isInt());
	CHECK(!IniValue(" ").isInt());
	CHECK(!IniValue("42 ").isInt());
	CHECK(!IniValue(" 42 ").isInt());
	CHECK(!IniValue("a").isInt());
	CHECK(!IniValue(" a").isInt());
	CHECK(!IniValue("a ").isInt());
	CHECK(!IniValue(" a ").isInt());
	CHECK(!IniValue("42 42").isInt());
	CHECK(!IniValue("4a2").isInt());

	CHECK(IniValue("42").isInt());
	CHECK(IniValue("42").asInt() == 42);
}
