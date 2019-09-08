#include "TestHelper.hpp"

#include <Reader.hpp>
#include <Xlsx2csv.hpp>
#include <catch.hpp>

TEST_CASE("XLSX -> CSV")
{
    std::string f = TestHelper::absolute_path("xlsx_csv");
    SECTION("complete conversion")
    {
        std::string fOut = f + "out.csv";
        std::string fIn  = f + "exp.xlsx";
        std::string fExp = f + "input.csv";
        auto fOut1       = fOut;

        TestHelper::instance.docs.emplace_back(fOut);
        Xlsx2Csv().convert(std::move(fIn), std::move(fOut));

        auto rOut = Reader().read(std::move(fOut1));
        auto rExp = Reader().read(std::move(fExp));

        /*
         * FIXME: this tests doesn't pass because it use the same files of
         * CSV -> XLSX and there is a problem when open xlsx
         */
        CHECK(rOut == rExp);
    }
}
