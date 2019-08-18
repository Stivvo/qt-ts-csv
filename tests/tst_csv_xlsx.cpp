#include "TestHelper.hpp"

#include <Csv2Xlsx.hpp>
#include <XlsxParser.hpp>

static bool cmp_file(const std::string &in, const std::string &out,
                     const std::string &exp)
{
    std::string f = TestHelper::fullPath("xlsx_csv");

    std::string fOut = f + out;
    std::string fIn  = f + in;
    std::string fExp = f + exp;
    auto fOut1       = fOut;

    if (fOut.find("Saved", 0) == std::string::npos) {
        TestHelper::pushDocs(fOut);
        Csv2Xlsx().convert(std::move(fIn), std::move(fOut));
    }

    auto rOut = XlsxParser().parse(std::move(fOut1));
    auto rExp = XlsxParser().parse(std::move(fExp));

    return rOut == rExp;
}

TEST_CASE("CSV -> XLSX")
{
    SECTION("conversion")
    {
        CHECK(cmp_file("exp.csv", "out.xlsx", "exp.xlsx"));
    }

    SECTION(
        "compare the saved output of conversion with the manual expected file")
    {
        CHECK(cmp_file("exp.csv", "outSaved.xlsx", "exp.xlsx"));
    }
}
