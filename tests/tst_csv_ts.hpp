#pragma once

#include "Path.hpp"

#include <Csv2Ts.hpp>
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

class tst_CsvTs : public testing::Test
{
  public:
    std::vector<std::string> docs;

  protected:
    virtual void TearDown()
    {
        std::for_each(docs.begin(), docs.end(), [](const std::string &d) {
            std::experimental::filesystem::remove(d);
        });
    }
};

TEST_F(tst_CsvTs, completeConversion)
{
    auto doc          = Path().get_files_basename() + "csv_ts/out.ts";
    auto file_compare = Path().get_files_basename() + "/csv_ts/exp.ts";
    Csv2Ts().convert(Path().get_files_basename() + "csv_ts/in.csv",
                     doc.c_str());
    bool bul = Path().debug(doc, Reader().read(std::move(file_compare)));
    EXPECT_TRUE(bul);
}
