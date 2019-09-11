#pragma once

#include <string>
#include <vector>

class TestHelper
{
  public:
    static TestHelper instance;

    static std::string absolute_path(const std::string &fldr);
    //    static std::string findDiff(const std::string &docReaded,
    //                                const std::string &expected);

    std::vector<std::string> docs;

  private:
    TestHelper();
    ~TestHelper();

    std::string sp;
    std::string pth;
    std::vector<std::string> to{ "ts_csv",  "csv_ts",   "ts_xlsx",
                                 "xlsx_ts", "xlsx_csv", "csv_xlsx" };
};
