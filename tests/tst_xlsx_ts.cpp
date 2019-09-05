#include "TestHelper.hpp"

#include <TsParser.hpp>
#include <Xlsx2Ts.hpp>
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
    Xlsx2Ts().convert(std::move(fIn), std::move(fOut));

    auto rOut = TsParser().parse(Reader().read(std::move(fOut1)));
    auto rExp = TsParser().parse(Reader().read(std::move(fExp)));

    return rOut == rExp;
}

TEST_CASE("XLSX -> TS")
{
    if (TestHelper::ToRun("xlsx_ts")) {
        SECTION("conversion")
        {
            CHECK(cmp_file("conversionIn.xlsx", "conversionOut.ts",
                           "conversionIn.ts"));
        }

        SECTION("multirow")
        {
            CHECK(
                cmp_file("multirowIn.xlsx", "multirowOut.ts", "multirowIn.ts"));
        }

        SECTION("complete Conversion")
        {
            CHECK(
                cmp_file("completeIn.xlsx", "completeOut.ts", "completeIn.ts"));
        }
    }
}
