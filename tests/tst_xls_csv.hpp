#pragma once

#include <Xlsx2csv.hpp>
#include <Reader.hpp>

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

class test_xls_csv : public testing::Test
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

TEST_F(test_xls_csv, completeConversion)
{
    n_doc = "../../qt-ts-csv/tests/files/csv_xlsx/out.csv";
    const auto file_compare = "../../qt-ts-csv/tests/files/csv_xlsx/exp.csv";

    Xlsx2Csv().convert("../../qt-ts-csv/tests/files/csv_xlsx/exp.xlsx", n_doc);

    EXPECT_EQ(Reader().read(n_doc), Reader().read(file_compare));
}

