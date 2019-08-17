#include "TestHelper.hpp"

#include <Csv2Xlsx.hpp>
#include <XlsxParser.hpp>

TEST_CASE("CSV -> XLSX")
{
    std::string f = TestHelper::fullPath("xlsx_csv");

    SECTION("complete conversion")
    {
        std::string doc          = f + "out.xlsx";
        auto doc1                = doc;
        std::string file_compare = f + "exp.xlsx";
        std::string input_file   = f + "exp.csv";

        Csv2Xlsx().convert(std::move(input_file), std::move(doc));
        TestHelper::pushDocs(doc);

        auto docReaded = XlsxParser().parse(std::move(doc1));
        auto expected  = XlsxParser().parse(std::move(file_compare));

        CHECK(docReaded == expected);
    }
}
