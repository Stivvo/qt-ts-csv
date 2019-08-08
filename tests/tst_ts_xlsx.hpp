#pragma once

#include "Path.hpp"
#include "Ts2Xlsx.hpp"
#include "XlsxParser.hpp"

#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

class test_ts_xlsx : public testing::Test
{
  public:
    std::vector<std::string> docs;
    bool cmp_file(const std::string &in, const std::string &out,
                  const std::string &expected);
    std::string f = "ts_xlsx/";

  protected:
    void TearDown() override
    {
        Path().teardown(docs);
    }
    void SetUp() override {}
};

TEST_F(test_ts_xlsx, conversion)
{
    EXPECT_TRUE(
        cmp_file("conversionIn.ts", "conversionOut.xlsx", "conversionIn.xlsx"));
}

bool test_ts_xlsx::cmp_file(const std::string &in, const std::string &out,
                            const std::string &expected)
{
    auto doc = Path().get_files_basename() + f + out;
    docs.push_back(doc);

    Ts2Xlsx().convert(std::move(Path().get_files_basename() + f + in),
                      std::move(doc.c_str()));

    return XlsxParser().parse(doc.c_str()) ==
           XlsxParser().parse(Path().get_files_basename() + f + expected);
}
