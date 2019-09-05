#include "TestHelper.hpp"

#include <Xlsx2csv.hpp>

TEST_CASE("XLSX -> CSV")
{
    if (TestHelper::ToRun("xlsx_csv")) {
        std::string f = TestHelper::fullPath("xlsx_csv");
        SECTION("complete conversion")
        {
            std::string fOut = f + "out.csv";
            std::string fIn  = f + "exp.xlsx";
            std::string fExp = f + "exp.csv";
            auto fOut1       = fOut;

            TestHelper::pushDocs(fOut);
            Xlsx2Csv().convert(std::move(fIn), std::move(fOut));

            auto rOut = Reader().read(std::move(fOut1));
            auto rExp = Reader().read(std::move(fExp));

            TestHelper::findDiff(rOut, rExp);

            CHECK(rOut == rExp);
        }
    }
}
