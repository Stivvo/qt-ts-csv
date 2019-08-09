#pragma once

#include "Debug.hpp"
#include "Path.hpp"

#include <Ts2Csv.hpp>
#include <catch.hpp>

std::vector<std::string> docs;
Path p;
std::string f = p.get_files_basename() + "csv_ts" + p.sep();

bool cmp_file(const std::string &in, const std::string &out,
              const std::string &expected)
{
    auto doc = f + in;
    docs.emplace_back(doc);
    Ts2Csv().convert(f + out, doc.c_str());

    return Reader().read(std::move(doc)) == expected;
}

TEST_CASE("TS -> CSV")
{
    SECTION("conversion")
    {
        const auto exp =
            R"("context"|"source"|"translation"|"location"|"version"|"language"
"AddNewForm"|"Cottura Manuale"|"Manual
 Cooking"|"../../QML/OggettiEditDash/AddNewForm.qml - 21"|"2.1"|"en_GB"
)";
        REQUIRE(cmp_file("r1.csv", "t1.ts", exp));
    }

    SECTION("multirow")
    {
        auto file_compare = f + "multirow.csv";
        REQUIRE(cmp_file("r2.csv", "t2.ts",
                         Reader().read(std::move(file_compare))));
    }

    SECTION("type vanished and obsolete")
    {
        const auto exp =
            R"("context"|"source"|"translation"|"location"|"version"|"language"
//)";
        REQUIRE(cmp_file("r3.csv", "t3.ts", exp));
    }

    SECTION("don't delete unfinished")
    {
        const auto exp =
            R"("context"|"source"|"translation"|"location"|"version"|"language"
    "ProgrammaSettmodel"|"h"|"h"|"../../../Ricette/programmasettmodel.cpp -
     687"|"2.1"|"en_US"
    "ProgrammaSettmodel"|"g"|""|"../../../Ricette/programmasettmodel.cpp -
     655"|""|""
    )";
        REQUIRE(cmp_file("r5.csv", "t5.ts", exp));
    }

    SECTION("complete conversion")
    {
        auto file_compare = f + "tc4.csv";
        REQUIRE(cmp_file("r4.csv", "t4.ts",
                         Reader().read(std::move(file_compare))));
    }
    Path().teardown(docs);
}
