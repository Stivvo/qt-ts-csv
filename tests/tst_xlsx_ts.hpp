#pragma once

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

class test_xlsx_ts : public testing::Test
{
  public:
    std::string doc;

  protected:
    virtual void TearDown()
    {
        std::experimental::filesystem::remove(doc);
    }

    virtual void SetUp() {}
};

TEST_F(test_xlsx_ts, completeConversion)
{
    std::string file_compare = Path().get_files_basename() + "ts_xlsx/in.ts";
    doc                      = Path().get_files_basename() + "ts_xlsx/out.ts";

    Xlsx2Ts().convert(Path().get_files_basename() + "ts_xlsx/in.xlsx",
                      doc.c_str());

    EXPECT_EQ(TsParser().parse(Reader().read(std::move(doc))),
              TsParser().parse(Reader().read(std::move(file_compare))));
}
