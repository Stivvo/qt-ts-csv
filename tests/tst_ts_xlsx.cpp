#include "TestHelper.hpp"

#include <Ts2Xlsx.hpp>
#include <XlsxParser.hpp>

static bool cmp_file(const std::string &in, const std::string &out,
                     const std::string &expected)
{
    std::string f = TestHelper::fullPath("ts_xlsx");

    auto doc     = f + out;
    auto docCstr = doc.c_str();
    TestHelper::pushDocs(doc);
    std::string input = f + in;

    Ts2Xlsx().convert(std::move(input), std::move(doc));

    std::string file_compare = f + expected;
    return XlsxParser().parse(std::move(docCstr)) ==
           XlsxParser().parse(std::move(file_compare));
}

TEST_CASE("TS -> XLSX")
{
    SECTION("conversion")
    {
        REQUIRE(cmp_file("conversionIn.ts", "conversionOut.xlsx",
                         "conversionIn.xlsx"));
    }
}
