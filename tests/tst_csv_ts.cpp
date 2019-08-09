#include "Debug.hpp"
#include "Path.hpp"

#include <Csv2Ts.hpp>
#include <catch.hpp>

TEST_CASE("CSV -> TS")
{
    SECTION("complete conversion")
    {
        auto doc          = f + "out.ts";
        auto file_compare = f + "exp.ts";
        auto input_file   = f + "in.csv";
        Csv2Ts().convert(std::move(input_file), std::move(doc.c_str()));
        docs.emplace_back(doc);

        std::string docReaded = Reader().read(std::move(doc));
        std::string expected  = Reader().read(std::move(file_compare));
        CHECK(docReaded == expected);
    }
}
