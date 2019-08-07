#pragma once

#include "Path.hpp"
#include "Ts2Xlsx.hpp"

#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

class test_ts_xlsx : public testing::Test
{
  public:
    std::vector<std::string> docs;

  protected:
    void TearDown() override
    {
        Path().teardown(docs);
    }
    void SetUp() override {}
};

TEST_F(test_ts_xlsx, completeConversion)
{
    const auto file_compare = Path().get_files_basename() + "ts_xlsx/in.xlsx";
    doc                     = Path().get_files_basename() + "ts_xlsx/out.xlsx";
    docs.push_back(doc);
    Ts2Xlsx().convert(Path().get_files_basename() + "ts_xlsx/in.ts",
                      doc.c_str());
}
