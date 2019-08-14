#include "TestHelper.hpp"

#include <TsParser.hpp>
#include <Xlsx2Ts.hpp>
#include <XlsxParser.hpp>

static bool cmp_file(const std::string &in, const std::string &out,
                     const std::string &expected)
{
    std::string f = TestHelper::fullPath("ts_xlsx");

    std::string doc          = f + out;
    std::string file_compare = f + expected;
    TestHelper::pushDocs(doc);

    Xlsx2Ts().convert(f + in, doc.c_str());

    auto docReaded = TsParser().parse(Reader().read(std::move(doc)));
    auto file_compareReaded =
        TsParser().parse(Reader().read(std::move(file_compare)));

    return docReaded == file_compareReaded;
}

TEST_CASE("XLSX -> TS")
{
    SECTION("conversion")
    {
        REQUIRE(cmp_file("conversionIn.xlsx", "conversionOut.ts",
                         "conversionIn.ts"));
    }

    SECTION("multirow")
    {
        REQUIRE(cmp_file("multirowIn.xlsx", "multirowOut.ts", "multirowIn.ts"));
    }

    SECTION("complete Conversion")
    {
        REQUIRE(cmp_file("completeIn.xlsx", "completeOut.ts", "completeIn.ts"));
    }
}
