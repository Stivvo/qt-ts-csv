#include "TestHelper.hpp"

#include <Xlsx2csv.hpp>

TEST_CASE("XLSX -> CSV")
{
    std::string f = TestHelper::fullPath("xlsx_csv");
    SECTION("complete conversion")
    {
        std::string doc          = f + "out.csv";
        auto doc1                = doc;
        std::string file_compare = f + "exp.csv";
        std::string input_file   = f + "exp.xlsx";
        TestHelper::pushDocs(doc1);

        Xlsx2Csv().convert(std::move(input_file), std::move(doc));

        std::string docReaded = Reader().read(std::move(doc1));
        std::string expected  = Reader().read(std::move(file_compare));

        CHECK(docReaded == expected);
    }
}
