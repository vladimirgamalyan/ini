#include <iostream>
#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include "Ini.h"
#include <fstream>

int main(int argc, char* argv[])
{
    {
        doctest::Context context;
        context.applyCommandLine(argc, argv);
        int res = context.run();
        if (context.shouldExit())
            return res;
    }

    {
        std::fstream fs("test/test.ini");
        Ini ini;
        ini.parse(fs);
        ini.dump();
    }

    return 0;
}
