#pragma once

#include "Debug.hpp"
#include "Path.hpp"

#include <Csv2Ts.hpp>
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

class tst_CsvTs : public testing::Test
{
  public:
    std::vector<std::string> docs;
    std::string f = "csv_ts/";

  protected:
    void TearDown() override
    {
        Path().teardown(docs);
    }
};

TEST_F(tst_CsvTs, completeConversion)
{
    auto doc          = Path().get_files_basename() + f + "out.ts";
    auto file_compare = Path().get_files_basename() + f + "exp.ts";
    Csv2Ts().convert(Path().get_files_basename() + f + "in.csv", doc.c_str());
    docs.emplace_back(doc);

    std::string docReaded = Reader().read(std::move(doc));
    std::string expected  = Reader().read(std::move(file_compare));
    bool bul              = docReaded == expected;
    EXPECT_TRUE(bul);
}
