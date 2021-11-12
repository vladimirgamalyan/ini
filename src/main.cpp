#include "Ini.h"
#include <fstream>
#include <iostream>
#include "utils/string/string_to_number.h"

#define DOCTEST_CONFIG_IMPLEMENT
#include "external/doctest.h"

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

        std::cout << "b: " << string_to_number<int>(ini.getValue("section2", "b").value_or("777")).value_or(-1) << "\n";

        std::cout << ini.getInt("section2", "b", 23) << "\n";

        auto a = ini.getIntArray("parcel", "many");
        for (const auto n : a)
            std::cout << n << " ";
        std::cout << "\n";
    }

    return 0;
}
