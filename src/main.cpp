#include <iostream>
#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include "Ini.h"
#include "IniValue.h"
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
        ini.dump(std::cout);

        auto p = ini.getSection("foo");
        if (!p)
            std::cout << "section 'foo' is not found\n";
        p = ini.getSection("section1");
        if (p)
            for (auto& [key, value] : *p)
                std::cout << key << "=" << value << "\n";

        auto foo = ini.getValue("section1", "foo2");
        std::cout << "foo: " << foo.value_or("7") << "\n";

        std::cout << "b: " << IniValue(ini.getValue("section2", "b").value_or("777")).asInt() << "\n";
    }

    return 0;
}
