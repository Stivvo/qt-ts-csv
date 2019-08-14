#include "TestHelper.hpp"

#include <Csv2Ts.hpp>

TEST_CASE("CSV -> TS")
{
    std::string f = TestHelper::fullPath("csv_ts");
    SECTION("complete conversion")
    {
        auto doc          = f + "out.ts";
        auto file_compare = f + "exp.ts";
        auto input_file   = f + "in.csv";
        Csv2Ts().convert(std::move(input_file), std::move(doc.c_str()));
        TestHelper::pushDocs(doc);

        std::string docReaded = Reader().read(std::move(doc));
        std::string expected  = Reader().read(std::move(file_compare));
        CHECK(docReaded == expected);
    }
}
