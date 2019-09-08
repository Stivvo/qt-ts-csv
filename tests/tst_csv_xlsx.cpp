#include "TestHelper.hpp"

#include <Csv2Xlsx.hpp>
#include <XlsxParser.hpp>
#include <catch.hpp>

TEST_CASE("CSV -> XLSX")
{
    SECTION("conversion")
    {
        const auto f = TestHelper::absolute_path("xlsx_csv");

        auto fOut  = f + "out.xlsx";
        auto fIn   = f + "input.csv";
        auto fExp  = f + "exp.xlsx";
        auto fOut1 = fOut;

        TestHelper::instance.docs.emplace_back(fOut);
        Csv2Xlsx().convert(std::move(fIn), std::move(fOut));

        auto rOut = XlsxParser().parse(std::move(fOut1));
        auto rExp = XlsxParser().parse(std::move(fExp));

        CHECK(rOut == rExp);
    }
}
