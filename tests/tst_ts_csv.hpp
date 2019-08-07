#pragma once

#include "Path.hpp"

#include <Ts2Csv.hpp>
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

class tst_TsCsv : public testing::Test
{
  public:
    std::vector<std::string> docs;

    bool cmp_file(const std::string &in, const std::string &out,
                  const std::string &expected);

  protected:
    void TearDown() override
    {
        std::for_each(docs.begin(), docs.end(), [](const std::string &d) {
            std::experimental::filesystem::remove(d);
        });
    }
};

TEST_F(tst_TsCsv, conversion)
{
    const auto exp =
        R"("context"|"source"|"translation"|"location"|"version"|"language"
"AddNewForm"|"Cottura Manuale"|"Manual Cooking"|"../../QML/OggettiEditDash/AddNewForm.qml - 21"|"2.1"|"en_GB"
)";

    EXPECT_TRUE(cmp_file("csv_ts/r1.csv", "csv_ts/t1.ts", exp));
}

TEST_F(tst_TsCsv, multirow)
{
    auto file_compare = Path().get_files_basename() + "csv_ts/multirow.csv";
    EXPECT_TRUE(cmp_file("csv_ts/r2.csv", "csv_ts/t2.ts",
                         Reader().read(std::move(file_compare))));
}

TEST_F(tst_TsCsv, typeVanishedAndObsolete)
{
    const auto exp =
        R"("context"|"source"|"translation"|"location"|"version"|"language"
)";

    EXPECT_TRUE(cmp_file("csv_ts/r3.csv", "csv_ts/t3.ts", exp));
}

TEST_F(tst_TsCsv, dontDeleteUnfinished)
{
    const auto exp =
        R"("context"|"source"|"translation"|"location"|"version"|"language"
"ProgrammaSettmodel"|"h"|"h"|"../../../Ricette/programmasettmodel.cpp - 687"|"2.1"|"en_US"
"ProgrammaSettmodel"|"g"|""|"../../../Ricette/programmasettmodel.cpp - 655"|""|""
)";
    EXPECT_TRUE(cmp_file("csv_ts/r5.csv", "csv_ts/t5.ts", exp));
}

TEST_F(tst_TsCsv, completeConversion)
{
    auto file_compare = Path().get_files_basename() + "csv_ts/tc4.csv";
    EXPECT_TRUE(cmp_file("csv_ts/r4.csv", "csv_ts/t4.ts",
                         Reader().read(std::move(file_compare))));
}

bool tst_TsCsv::cmp_file(const std::string &in, const std::string &out,
                         const std::string &expected)
{
    auto doc = Path().get_files_basename() + in;
    docs.emplace_back(doc);
    Ts2Csv().convert(Path().get_files_basename() + out, doc.c_str());

    return Path().debug(doc, expected);
}
