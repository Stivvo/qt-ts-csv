#include "TestHelper.hpp"

#include <Csv2Xlsx.hpp>
#include <XlsxParser.hpp>
#include <catch.hpp>

static bool cmp_file(const std::string &in, const std::string &out,
                     const std::string &exp)
{
    const auto f = TestHelper::absolute_path("xlsx_csv");

    auto fOut  = f + out;
    auto fIn   = f + in;
    auto fExp  = f + exp;
    auto fOut1 = fOut;

    TestHelper::instance.docs.emplace_back(fOut);
    Csv2Xlsx().convert(std::move(fIn), std::move(fOut));

    auto rOut = XlsxParser().parse(std::move(fOut1));
    auto rExp = XlsxParser().parse(std::move(fExp));

    return rOut == rExp;
}

TEST_CASE("CSV -> XLSX")
{
    SECTION("conversion")
    {
        CHECK(cmp_file("input.csv", "out.xlsx", "exp.xlsx"));
    }
}
