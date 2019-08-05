#pragma once

#include "Path.hpp"

#include <Reader.hpp>
#include <Ts2Csv.hpp>
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

class tst_TsCsv : public testing::Test
{
  public:
    std::vector<std::string> docs;

  protected:
    void TearDown() override
    {
        std::for_each(docs.begin(), docs.end(), [](const std::string &d) {
            std::experimental::filesystem::remove(d);
        });
    }
};

TEST_F(tst_TsCsv, conversion)
{
    const auto output = "\"context\"|\"source\"|\"translation\"|\"location\"|"
                        "\"version\"|\"language\"\n"
                        "\"AddNewForm\"|\"Cottura Manuale\"|\"Manual "
                        "Cooking\"|\"../../QML/OggettiEditDash/AddNewForm.qml "
                        "- 21\"|\"2.1\"|\"en_GB\"\n";

    auto doc = Path().get_files_basename() + "csv_ts/r1.csv";
    docs.emplace_back(doc);
    Ts2Csv().convert(Path().get_files_basename() + "csv_ts/t1.ts", doc.c_str());

    EXPECT_EQ(Reader().read(std::move(doc)), output);
}

TEST_F(tst_TsCsv, multirow)
{
    const auto output =
        "\"context\"|\"source\"|\"translation\"|\"location\"|\"version\"|"
        "\"language\"\n"
        "\"Connettivita\"|\"Impostazioni\r\n    Wi-fi\"|\"WI-fi\r\n"
        "    settings\"|\"../../QML/OggettiSettings/Connettivita.qml - "
        "66\"|\"2.1\"|\"en_GB\"\n";

    auto doc = Path().get_files_basename() + "csv_ts/r2.csv";
    docs.emplace_back(doc);
    Ts2Csv().convert(Path().get_files_basename() + "csv_ts/t2.ts", doc.c_str());

    EXPECT_EQ(Reader().read(std::move(doc)), output);
}

// TEST_F(test_ts_csv, typeVanishedAndObsolete)
//{
//    const auto output =
//    "\"context\"|\"source\"|\"translation\"|\"location\"|\"version\"|\"language\"\n";

//    n_doc = "../../qt-ts-csv/tests/files/csv_ts/r3.csv";
//    Ts2Csv().convert("../../qt-ts-csv/tests/files/csv_ts/t3.ts", n_doc);

//    EXPECT_EQ(Reader().read(n_doc), output);
//}

// TEST_F(test_ts_csv, dontDeleteUnfinished)
//{

//    const auto output =
//    "\"context\"|\"source\"|\"translation\"|\"location\"|\"version\"|\"language\"\n"
//                        "\"ProgrammaSettmodel\"|\"h\"|\"h\"|\"../../../Ricette/programmasettmodel.cpp
//                        - 687\"|\"2.1\"|\"en_US\"\n"
//                        "\"ProgrammaSettmodel\"|\"g\"|\"\"|\"../../../Ricette/programmasettmodel.cpp
//                        - 655\"|\"\"|\"\"\n";

//    n_doc = "../../qt-ts-csv/tests/files/csv_ts/r5.csv";
//    Ts2Csv().convert("../../qt-ts-csv/tests/files/csv_ts/t5.ts", n_doc);

//    EXPECT_EQ(Reader().read(n_doc), output);
//}

// TEST_F(test_ts_csv, completeConversion)
//{
//    n_doc = "../../qt-ts-csv/tests/files/r4.csv";
//    const auto file_compare = "../../qt-ts-csv/tests/files/csv_ts/tc4.csv";

//    Ts2Csv().convert("../../qt-ts-csv/tests/files/csv_ts/t4.ts", n_doc);

//    EXPECT_EQ(Reader().read(n_doc), Reader().read(file_compare));
//}
