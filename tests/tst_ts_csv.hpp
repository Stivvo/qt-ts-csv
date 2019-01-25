#pragma once

#include <ts2csv.hpp>
#include <ts2csv.cpp>
#include <converter.hpp>
#include <converter.cpp>
#include <writer.hpp>
#include <writer.cpp>
#include <reader.hpp>
#include <reader.cpp>
#include <tsparser.hpp>
#include <tsparser.cpp>
#include <csvbuilder.hpp>
#include <csvbuilder.cpp>

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

using namespace testing;

TEST(test_ts_csv, t1)
{
    const auto output = "\"context\"|\"source\"|\"translation\"|\"location\"|\"version\"|\"language\"|\n"
                        "\"AddNewForm\"|\"Cottura Manuale\"|\"Manual Cooking\"|\"../../QML/OggettiEditDash/AddNewForm.qml - 21\"|2.1|en_GB|\n";

    const auto file_output = "../../qt-ts-csv/tests/t1.csv";
    Ts2Csv().convert("../../qt-ts-csv/tests/t1.ts", file_output);

    EXPECT_EQ(Reader().read(file_output), output);
}