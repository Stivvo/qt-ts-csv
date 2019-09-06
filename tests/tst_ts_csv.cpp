#include "TestHelper.hpp"

#include <Reader.hpp>
#include <Ts2Csv.hpp>
#include <catch.hpp>

bool cmp_file(const std::string &in, const std::string &out,
              const std::string &exp)
{
    std::string f    = TestHelper::full_path("csv_ts");
    std::string fOut = f + out;
    std::string fIn  = f + in;
    auto fOut1       = fOut;

    TestHelper::instance.docs.emplace_back(fOut);
    Ts2Csv().convert(std::move(fIn), std::string(std::move(fOut)));

    auto rOut = Reader().read(std::move(fOut1));
    return rOut == exp;
}

TEST_CASE("TS -> CSV")
{
    auto f = TestHelper::full_path("csv_ts");
    SECTION("conversion")
    {
        const auto exp =
            R"("context"|"source"|"translation"|"location"|"version"|"language"
"AddNewForm"|"Cottura Manuale"|"Manual Cooking"|"../../QML/OggettiEditDash/AddNewForm.qml - 21"|"2.1"|"en_GB"
)";
        CHECK(cmp_file("simple.ts", "output_simple.csv", exp));
    }

    //    SECTION("multirow")
    //    {
    //        auto file_compare = f + "multirow.csv";
    //        CHECK(cmp_file("t2.ts", "r2.csv",
    //                       Reader().read(std::move(file_compare))));
    //    }

    //    SECTION("type vanished and obsolete")
    //    {
    //        const auto exp =
    //            R"("context"|"source"|"translation"|"location"|"version"|"language"
    //)";
    //        CHECK(cmp_file("t3.ts", "r3.csv", exp));
    //    }

    //    SECTION("don't delete unfinished")
    //    {
    //        const auto exp =
    //            R"("context"|"source"|"translation"|"location"|"version"|"language"
    //"ProgrammaSettmodel"|"h"|"h"|"../../../Ricette/programmasettmodel.cpp -
    // 687"|"2.1"|"en_US"
    //"ProgrammaSettmodel"|"g"|""|"../../../Ricette/programmasettmodel.cpp -
    // 655"|""|""
    //)";
    //        CHECK(cmp_file("t5.ts", "r5.csv", exp));
    //    }

    //    SECTION("complete conversion")
    //    {
    //        auto file_compare = f + "tc4.csv";
    //        CHECK(cmp_file("t4.ts", "r4.csv",
    //                       Reader().read(std::move(file_compare))));
    //    }
}
