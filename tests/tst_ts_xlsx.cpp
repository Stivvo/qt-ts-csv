#pragma once

#include "Path.hpp"
#include "Ts2Xlsx.hpp"
#include "XlsxParser.hpp"

#include <catch.hpp>

Path p;
std::string f = p.get_files_basename() + "ts_xlsx" + p.sep();
std::vector<std::string> docs;

static bool cmp_file(const std::string &in, const std::string &out,
                     const std::string &expected)
{
    auto doc     = f + out;
    auto docCstr = doc.c_str();
    docs.push_back(doc);
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

    Path().teardown(docs);
}
