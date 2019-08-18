#include "TestHelper.hpp"

#include <Ts2Xlsx.hpp>
#include <XlsxParser.hpp>

static bool cmp_file(const std::string &in, const std::string &out,
                     const std::string &exp)
{
    std::string f = TestHelper::fullPath("ts_xlsx");

    std::string fOut = f + out;
    std::string fIn  = f + in;
    std::string fExp = f + exp;
    auto fOut1       = fOut;

    TestHelper::pushDocs(fOut);
    Ts2Xlsx().convert(std::move(fIn), std::move(fOut));

    auto rOut = XlsxParser().parse(std::move(fOut1));
    auto rExp = XlsxParser().parse(std::move(fExp));

    return rOut == rExp;
}

TEST_CASE("TS -> XLSX")
{
    SECTION("conversion")
    {
        CHECK(cmp_file("conversionIn.ts", "conversionOut.xlsx",
                       "conversionIn.xlsx"));
    }
}
