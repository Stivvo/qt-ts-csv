#pragma once

#include "Debug.hpp"
#include "Path.hpp"
#include "Reader.hpp"
#include "Ts2Xlsx.hpp"
#include "TsParser.hpp"
#include "Xlsx2Ts.hpp"
#include "XlsxParser.hpp"

#include <catch.hpp>
#include <iostream>

Path p;
std::vector<std::string> docs;
std::string f = p.get_files_basename() + "ts_xlsx" + p.sep();

static bool cmp_file(const std::string &in, const std::string &out,
                     const std::string &expected)
{
    std::string doc          = f + out;
    std::string file_compare = f + expected;
    docs.emplace_back(doc);

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
    Path().teardown(docs);
}
