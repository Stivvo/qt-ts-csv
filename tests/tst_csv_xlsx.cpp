#include "TestHelper.hpp"

#include <Csv2Xlsx.hpp>
#include <XlsxParser.hpp>

TEST_CASE("CSV -> XLSX")
{
    std::string f = TestHelper::fullPath("xlsx_csv");

    SECTION("complete conversion")
    {
        std::string fOut = f + "out.xlsx";
        std::string fIn  = f + "exp.csv";
        std::string fExp = f + "exp.xlsx";
        auto fOut1       = fOut;

        TestHelper::pushDocs(fOut);
        Csv2Xlsx().convert(std::move(fIn), std::move(fOut));

        auto rOut = XlsxParser().parse(std::move(fOut1));
        auto rExp = XlsxParser().parse(std::move(fExp));

        CHECK(rOut == rExp);
    }
}
