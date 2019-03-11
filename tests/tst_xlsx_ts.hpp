#pragma once

#include "xlsxdocument.h"
#include "Reader.hpp"
#include "Xlsx2Ts.hpp"
#include "Ts2Xlsx.hpp"
#include "XlsxParser.hpp"
#include "TsParser.hpp"

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

class test_xlsx_ts : public testing::Test
{
public:
    const char *n_doc;

protected:
    virtual void TearDown()
    {
        remove(n_doc);
    }

    virtual void SetUp()
    {
        n_doc = nullptr;
    }
};

TEST_F(test_xlsx_ts, completeConversion)
{
    const auto file_compare = "../../qt-ts-csv/tests/files/ts_xlsx/in.ts";
    n_doc = "../../qt-ts-csv/tests/files/ts_xlsx/out.ts";

    Xlsx2Ts().convert("../../qt-ts-csv/tests/files/ts_xlsx/in.xlsx", n_doc);

    EXPECT_EQ(TsParser().parse(Reader().read(std::move(n_doc))),
              TsParser().parse(Reader().read(std::move(file_compare))));
}

