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
    std::string f = Path().get_files_basename() + "csv_ts" + Path::sep();

  protected:
    void TearDown() override
    {
        Path().teardown(docs);
    }
};

TEST_F(tst_CsvTs, completeConversion)
{
    auto doc          =  f + "out.ts";
    auto file_compare = f + "exp.ts";
    auto input_file = f + "in.csv";
    Csv2Ts().convert(std::move(input_file), std::move(doc.c_str()));
    docs.emplace_back(doc);

    std::string docReaded = Reader().read(std::move(doc));
    std::string expected  = Reader().read(std::move(file_compare));
    bool bul              = docReaded == expected;
    EXPECT_TRUE(bul);
}
