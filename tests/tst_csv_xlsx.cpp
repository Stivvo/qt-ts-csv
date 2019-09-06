#include "TestHelper.hpp"

#include <Csv2Xlsx.hpp>
#include <XlsxParser.hpp>
#include <catch.hpp>

static bool cmp_file(const std::string &in, const std::string &out,
                     const std::string &exp)
{
    std::string f = TestHelper::full_path("xlsx_csv");

    std::string fOut = f + out;
    std::string fIn  = f + in;
    std::string fExp = f + exp;
    auto fOut1       = fOut;

    if (fOut.find("Saved", 0) == std::string::npos) {
        TestHelper::instance.docs.emplace_back(fOut);
        Csv2Xlsx().convert(std::move(fIn), std::move(fOut));
    }

    auto rOut = XlsxParser().parse(std::move(fOut1));
    auto rExp = XlsxParser().parse(std::move(fExp));

    return rOut == rExp;
}

TEST_CASE("CSV -> XLSX")
{
    //    if (TestHelper::ToRun("csv_xlsx")) {
    //        SECTION("conversion")
    //        {
    //            CHECK(cmp_file("exp.csv", "out.xlsx", "exp.xlsx"));
    //        }

    //        SECTION("compare the saved output of conversion with the manual "
    //                "expected file")
    //        {
    //            CHECK(cmp_file("exp.csv", "outSaved.xlsx", "exp.xlsx"));
    //        }
    //    }
}
