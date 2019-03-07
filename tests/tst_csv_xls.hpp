#pragma once

#include <Csv2Xlsx.hpp>
#include <Reader.hpp>
#include <XlsxParser.hpp>

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

class test_csv_xlsx : public testing::Test
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

TEST_F(test_csv_xlsx, completeConversion)
{
    n_doc = "../../qt-ts-csv/tests/files/csv_xlsx/out.xlsx";
    const auto file_compare = "../../qt-ts-csv/tests/files/csv_xlsx/exp.xlsx";
    Csv2Xlsx().convert("../../qt-ts-csv/tests/files/csv_xlsx/exp.csv", n_doc);

    EXPECT_EQ(XlsxParser().parse(n_doc), XlsxParser().parse(file_compare));
}


