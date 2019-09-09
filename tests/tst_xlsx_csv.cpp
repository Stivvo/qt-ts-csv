#include "TestHelper.hpp"

#include <Reader.hpp>
#include <Xlsx2csv.hpp>
#include <catch.hpp>

TEST_CASE("XLSX -> CSV")
{
    std::string f = TestHelper::absolute_path("xlsx_csv");
    SECTION("complete conversion")
    {
        std::string fIn  = f + "input.xlsx";
        std::string fOut = f + "output.csv";
        std::string fExp = f + "expected.csv";
        auto fOut1       = fOut;

        TestHelper::instance.docs.emplace_back(fOut);
        Xlsx2Csv().convert(std::move(fIn), std::move(fOut));

        auto rOut = Reader().read(std::move(fOut1));
        auto rExp = Reader().read(std::move(fExp));

        CHECK(rOut == rExp);
    }
}
