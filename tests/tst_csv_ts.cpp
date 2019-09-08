#include "TestHelper.hpp"

#include <Csv2Ts.hpp>
#include <Reader.hpp>
#include <catch.hpp>

TEST_CASE("CSV -> TS")
{
    std::string f = TestHelper::absolute_path("csv_ts");
    SECTION("complete conversion")
    {
        std::string fOut = f + "out.ts";
        std::string fIn  = f + "in.csv";
        std::string fExp = f + "exp.ts";
        auto fOut1       = fOut;

        TestHelper::instance.docs.emplace_back(fOut);
        Csv2Ts().convert(std::move(fIn), std::move(fOut));

        auto rOut = Reader().read(std::move(fOut1));
        auto rExp = Reader().read(std::move(fExp));
        CHECK(rOut == rExp);
    }
}
