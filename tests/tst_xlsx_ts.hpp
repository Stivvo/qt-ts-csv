#pragma once

#include "Debug.hpp"
#include "Path.hpp"
#include "Reader.hpp"
#include "Ts2Xlsx.hpp"
#include "TsParser.hpp"
#include "Xlsx2Ts.hpp"
#include "XlsxParser.hpp"
#include "xlsxdocument.h"

#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include <iostream>

class tst_xlsx_ts : public testing::Test
{
  public:
    std::vector<std::string> docs;
    bool cmp_file(const std::string &in, const std::string &out,
                  const std::string &expected);

  protected:
    void TearDown() override
    {
        Path().teardown(docs);
    }

    virtual void SetUp() {}
};

TEST_F(tst_xlsx_ts, conversion)
{
    EXPECT_TRUE(cmp_file("ts_xlsx/conversionIn.xlsx",
                         "ts_xlsx/conversionOut.ts",
                         "ts_xlsx/conversionIn.ts"));
}

TEST_F(tst_xlsx_ts, multirow)
{
    EXPECT_TRUE(cmp_file("ts_xlsx/multirowIn.xlsx", "ts_xlsx/multirowOut.ts",
                         "ts_xlsx/multirowIn.ts"));
}

TEST_F(tst_xlsx_ts, completeConversion)
{
    EXPECT_TRUE(cmp_file("ts_xlsx/completeIn.xlsx", "ts_xlsx/completeOut.ts",
                         "ts_xlsx/completeIn.ts"));
}

bool tst_xlsx_ts::cmp_file(const std::string &in, const std::string &out,
                           const std::string &expected)
{
    std::string doc          = Path().get_files_basename() + out;
    std::string file_compare = Path().get_files_basename() + expected;
    docs.emplace_back(doc);

    Xlsx2Ts().convert(Path().get_files_basename() + in, doc.c_str());

    auto docReaded = TsParser().parse(Reader().read(std::move(doc)));
    auto file_compareReaded =
        TsParser().parse(Reader().read(std::move(file_compare)));

    return docReaded == file_compareReaded;
}
