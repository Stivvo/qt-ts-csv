#include "tst_csv_ts.hpp"
#include "tst_ts_csv.hpp"
//
#include "tst_ts_xlsx.hpp"
#include "tst_xlsx_ts.hpp"
//
//#include "tst_xls_csv.hpp"
//#include "tst_csv_xls.hpp"

#include <gtest/gtest.h>
#include "Path.hpp"

int main(int argc, char *argv[])
{
    Path::initSep();
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
