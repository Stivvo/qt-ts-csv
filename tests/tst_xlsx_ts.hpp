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
    std::string f = Path().get_files_basename() + "ts_xlsx" + Path::sep();

  protected:
    void TearDown() override
    {
        Path().teardown(docs);
    }
};

TEST_F(tst_xlsx_ts, conversion)
{
    EXPECT_TRUE(cmp_file("conversionIn.xlsx",
                         "conversionOut.ts",
                         "conversionIn.ts"));
}

TEST_F(tst_xlsx_ts, multirow)
{
    EXPECT_TRUE(cmp_file("multirowIn.xlsx", "multirowOut.ts",
                         "multirowIn.ts"));
}

TEST_F(tst_xlsx_ts, completeConversion)
{
    EXPECT_TRUE(cmp_file("completeIn.xlsx", "completeOut.ts",
                         "completeIn.ts"));
}

bool tst_xlsx_ts::cmp_file(const std::string &in, const std::string &out,
                           const std::string &expected)
{
    std::string doc          =  f + out;
    std::string file_compare = f + expected;
    docs.emplace_back(doc);

    Xlsx2Ts().convert(f + in, doc.c_str());

    auto docReaded = TsParser().parse(Reader().read(std::move(doc)));
    auto file_compareReaded =
        TsParser().parse(Reader().read(std::move(file_compare)));

    return docReaded == file_compareReaded;
}
