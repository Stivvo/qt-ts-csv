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
    std::string f = Path().get_files_basename() + "ts_xlsx" + Path::sep();

  protected:
    void TearDown() override
    {
        Path().teardown(docs);
    }
};

TEST_F(test_ts_xlsx, conversion)
{
    EXPECT_TRUE(
        cmp_file("conversionIn.ts", "conversionOut.xlsx", "conversionIn.xlsx"));
}

bool test_ts_xlsx::cmp_file(const std::string &in, const std::string &out,
                            const std::string &expected)
{
    auto doc = f + out;
    auto docCstr = doc.c_str();
    docs.push_back(doc);
    std::string input = f + in;

    Ts2Xlsx().convert(std::move(input),
                      std::move(doc));

    std::string file_compare = f + expected;
    return XlsxParser().parse(std::move(docCstr)) ==
           XlsxParser().parse(std::move(file_compare));
}
