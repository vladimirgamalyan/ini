#include <iostream>
#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"

int main(int argc, char* argv[])
{
    {
        doctest::Context context;
        context.applyCommandLine(argc, argv);
        int res = context.run();
        if (context.shouldExit())
            return res;
    }

    return 0;
}

TEST_CASE("foo test")
{
    CHECK(2 * 2 == 4);
}
