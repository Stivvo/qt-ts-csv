#include "TestHelper.hpp"

#include <Csv2Xlsx.hpp>
#include <XlsxParser.hpp>

TEST_CASE("CSV -> XLSX")
{
    std::string f = TestHelper::fullPath("csv_ts");

    SECTION("complete conversion")
    {
        std::string doc          = f + "out.xlsx";
        auto doc1                = doc;
        std::string file_compare = f + "exp.xlsx";
        std::string input_file   = f + "exp.csv";
        TestHelper::pushDocs(doc);

        Csv2Xlsx().convert(std::move(input_file), std::move(doc));
        CHECK(XlsxParser().parse(std::move(doc1)) ==
              XlsxParser().parse(std::move(file_compare)));
    }
}
