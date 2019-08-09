#pragma once

#include "Debug.hpp"
#include "Path.hpp"

#include <Csv2Ts.hpp>
#include <catch.hpp>

std::vector<std::string> docs;
Path p;
std::string f = p.get_files_basename() + "csv_ts" + p.sep();

TEST_CASE("CSV -> TS")
{
    SECTION("complete conversion")
    {
        auto doc          = f + "out.ts";
        auto file_compare = f + "exp.ts";
        auto input_file   = f + "in.csv";
        Csv2Ts().convert(std::move(input_file), std::move(doc.c_str()));
        docs.emplace_back(doc);

        std::string docReaded = Reader().read(std::move(doc));
        std::string expected  = Reader().read(std::move(file_compare));
        CHECK(docReaded == expected);
    }
    Path().teardown(docs);
}
