#pragma once

#include <Ts2Xlsx.hpp>

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

class test_ts_xlsx : public testing::Test
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

TEST_F(test_ts_xlsx, completeConversion)
{
    n_doc = "../../qt-ts-csv/tests/files/ts_xlsx/out.xlsx";
    Ts2Xlsx().convert("../../qt-ts-csv/tests/files/ts_xlsx/in.ts", n_doc);
}
