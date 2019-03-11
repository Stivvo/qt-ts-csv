#pragma once

#include <Ts2Csv.hpp>
#include <Reader.hpp>

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

class test_ts_csv : public testing::Test
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

TEST_F(test_ts_csv, conversion)
{
    const auto output = "\"context\"|\"source\"|\"translation\"|\"location\"|\"version\"|\"language\"\n"
                        "\"AddNewForm\"|\"Cottura Manuale\"|\"Manual Cooking\"|\"../../QML/OggettiEditDash/AddNewForm.qml - 21\"|\"2.1\"|\"en_GB\"\n";

    n_doc = "../../qt-ts-csv/tests/files/csv_ts/r1.csv";
    Ts2Csv().convert("../../qt-ts-csv/tests/files/csv_ts/t1.ts", n_doc);

    EXPECT_EQ(Reader().read(n_doc), output);
}

TEST_F(test_ts_csv, multirow)
{
    const auto output = "\"context\"|\"source\"|\"translation\"|\"location\"|\"version\"|\"language\"\n"
                        "\"Connettivita\"|\"Impostazioni\n    Wi-fi\"|\"WI-fi\n"
                        "    settings\"|\"../../QML/OggettiSettings/Connettivita.qml - 66\"|\"2.1\"|\"en_GB\"\n";

    n_doc = "../../qt-ts-csv/tests/files/csv_ts/r2.csv";
    Ts2Csv().convert("../../qt-ts-csv/tests/files/csv_ts/t2.ts", n_doc);

    EXPECT_EQ(Reader().read(n_doc), output);
}

TEST_F(test_ts_csv, typeVanishedAndObsolete)
{
    const auto output = "\"context\"|\"source\"|\"translation\"|\"location\"|\"version\"|\"language\"\n";

    n_doc = "../../qt-ts-csv/tests/files/csv_ts/r3.csv";
    Ts2Csv().convert("../../qt-ts-csv/tests/files/csv_ts/t3.ts", n_doc);

    EXPECT_EQ(Reader().read(n_doc), output);
}

TEST_F(test_ts_csv, dontDeleteUnfinished)
{

    const auto output = "\"context\"|\"source\"|\"translation\"|\"location\"|\"version\"|\"language\"\n"
                        "\"ProgrammaSettmodel\"|\"h\"|\"h\"|\"../../../Ricette/programmasettmodel.cpp - 687\"|\"2.1\"|\"en_US\"\n"
                        "\"ProgrammaSettmodel\"|\"g\"|\"\"|\"../../../Ricette/programmasettmodel.cpp - 655\"|\"\"|\"\"\n";

    n_doc = "../../qt-ts-csv/tests/files/csv_ts/r5.csv";
    Ts2Csv().convert("../../qt-ts-csv/tests/files/csv_ts/t5.ts", n_doc);

    EXPECT_EQ(Reader().read(n_doc), output);
}

TEST_F(test_ts_csv, completeConversion)
{
    n_doc = "../../qt-ts-csv/tests/files/r4.csv";
    const auto file_compare = "../../qt-ts-csv/tests/files/csv_ts/tc4.csv";

    Ts2Csv().convert("../../qt-ts-csv/tests/files/csv_ts/t4.ts", n_doc);

    EXPECT_EQ(Reader().read(n_doc), Reader().read(file_compare));
}

