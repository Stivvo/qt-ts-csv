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

    bool cmp_file(const std::string &in, const std::string &out,
                  const std::string &expected);

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
    const auto exp = "\"context\"|\"source\"|\"translation\"|\"location\"|"
                     "\"version\"|\"language\"\n"
                     "\"AddNewForm\"|\"Cottura Manuale\"|\"Manual "
                     "Cooking\"|\"../../QML/OggettiEditDash/AddNewForm.qml "
                     "- 21\"|\"2.1\"|\"en_GB\"\n";

    EXPECT_TRUE(cmp_file("csv_ts/r1.csv", "csv_ts/t1.ts", exp));
}

TEST_F(tst_TsCsv, multirow)
{
    const auto exp =
        "\"context\"|\"source\"|\"translation\"|\"location\"|\"version\"|"
        "\"language\"\n"
        "\"Connettivita\"|\"Impostazioni\r\n    Wi-fi\"|\"WI-fi\r\n"
        "    settings\"|\"../../QML/OggettiSettings/Connettivita.qml - "
        "66\"|\"2.1\"|\"en_GB\"\n";

    EXPECT_TRUE(cmp_file("csv_ts/r2.csv", "csv_ts/t2.ts", exp));
}

TEST_F(tst_TsCsv, typeVanishedAndObsolete)
{
    const auto exp = "\"context\"|\"source\"|\"translation\"|\"location\"|"
                     "\"version\"|\"language\"\n";

    EXPECT_TRUE(cmp_file("csv_ts/r3.csv", "csv_ts/t3.ts", exp));
}

TEST_F(tst_TsCsv, dontDeleteUnfinished)
{
    const auto exp = "\"context\"|\"source\"|\"translation\"|\"location\"|"
                     "\"version\"|\"language\"\n"
                     "\"ProgrammaSettmodel\"|\"h\"|\"h\"|\"../../../Ricette/"
                     "programmasettmodel.cpp - 687\"|\"2.1\"|\"en_US\"\n"
                     "\"ProgrammaSettmodel\"|\"g\"|\"\"|\"../../../Ricette/"
                     "programmasettmodel.cpp - 655\"|\"\"|\"\"\n";

    EXPECT_TRUE(cmp_file("csv_ts/r5.csv", "csv_ts/t5.ts", exp));
}

TEST_F(tst_TsCsv, completeConversion)
{
    auto file_compare = Path().get_files_basename() + "csv_ts/tc4.csv";
    EXPECT_TRUE(cmp_file("csv_ts/r4.csv", "csv_ts/t4.ts",
                         Reader().read(std::move(file_compare))));
}

bool tst_TsCsv::cmp_file(const std::string &in, const std::string &out,
                         const std::string &expected)
{
    auto doc = Path().get_files_basename() + in;
    docs.emplace_back(doc);
    Ts2Csv().convert(Path().get_files_basename() + out, doc.c_str());
    std::string docReaded = Reader().read(std::move(doc));

    // debug
    std::string diffs = "";
    int j             = 0;
    for (int i = 0; i < expected.size(); ++i) {
        if (expected[i] == docReaded[j])
            ++j;
        else
            diffs += expected[i];
    }
    std::cout << "docReaded size: " << docReaded.size() << std::endl;
    std::cout << "expected size: " << expected.size() << std::endl;
    std::cout << "j: " << j << ", diffs.size: " << diffs.size() << std::endl
              << std::endl;
    // end debug

    return docReaded == expected;
}
