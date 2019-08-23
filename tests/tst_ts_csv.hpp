#pragma once

#include "Debug.hpp"
#include "Path.hpp"

#include <Ts2Csv.hpp>
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

class tst_TsCsv : public testing::Test
{
  public:
    std::vector<std::string> docs;
    std::string f = Path().get_files_basename() + "csv_ts" + Path::sep();

    bool cmp_file(const std::string &in, const std::string &out,
                  const std::string &expected);

  protected:
    void TearDown() override
    {
        Path().teardown(docs);
    }
};

TEST_F(tst_TsCsv, conversion)
{
    const auto exp =
        R"("context"|"source"|"translation"|"location"|"version"|"language"
"AddNewForm"|"Cottura Manuale"|"Manual Cooking"|"../../QML/OggettiEditDash/AddNewForm.qml - 21"|"2.1"|"en_GB"
)";

    EXPECT_TRUE(cmp_file("r1.csv", "t1.ts", exp));
}

TEST_F(tst_TsCsv, multirow)
{
    auto file_compare = f + "multirow.csv";
    EXPECT_TRUE(
        cmp_file("r2.csv", "t2.ts", Reader().read(std::move(file_compare))));
}

TEST_F(tst_TsCsv, typeVanishedAndObsolete)
{
    const auto exp =
        R"("context"|"source"|"translation"|"location"|"version"|"language"
)";

    EXPECT_TRUE(cmp_file("r3.csv", "t3.ts", exp));
}

TEST_F(tst_TsCsv, dontDeleteUnfinished)
{
    const auto exp =
        R"("context"|"source"|"translation"|"location"|"version"|"language"
"ProgrammaSettmodel"|"h"|"h"|"../../../Ricette/programmasettmodel.cpp - 687"|"2.1"|"en_US"
"ProgrammaSettmodel"|"g"|""|"../../../Ricette/programmasettmodel.cpp - 655"|""|""
)";
    EXPECT_TRUE(cmp_file("r5.csv", "t5.ts", exp));
}

TEST_F(tst_TsCsv, completeConversion)
{
    auto file_compare = f + "tc4.csv";
    EXPECT_TRUE(
        cmp_file("r4.csv", "t4.ts", Reader().read(std::move(file_compare))));
}

bool tst_TsCsv::cmp_file(const std::string &in, const std::string &out,
                         const std::string &expected)
{
    auto doc = f + in;
    docs.emplace_back(doc);
    Ts2Csv().convert(f + out, doc.c_str());

    return Reader().read(std::move(doc)) == expected;
}
