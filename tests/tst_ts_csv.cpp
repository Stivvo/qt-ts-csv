#include "TestHelper.hpp"

#include <Reader.hpp>
#include <Ts2Csv.hpp>
#include <catch.hpp>

bool cmp_file(const std::string &in, const std::string &out,
              const std::string &exp)
{
    std::string f    = TestHelper::absolute_path("csv_ts");
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
    SECTION("simple")
    {
        const auto exp =
            R"("context"|"source"|"translation"|"location"|"version"|"language"
"AddNewForm"|"Cottura Manuale"|"Manual Cooking"|"../../QML/OggettiEditDash/AddNewForm.qml - 21"|"2.1"|"en_GB"
)";
        CHECK(cmp_file("simple.ts", "output_simple.csv", exp));
    }

    SECTION("multirow translation")
    {
        const auto exp =
            R"("context"|"source"|"translation"|"location"|"version"|"language"
"Connettivita"|"Impostazioni
Wi-fi"|"WI-fi
Settings"|"../../QML/OggettiSettings/Connettivita.qml - 66"|"2.1"|"en_GB"
)";
        CHECK(cmp_file("multirow_field.ts", "output_multirow_field.csv", exp));
    }

    SECTION("type to discard")
    {
        const auto exp =
            R"("context"|"source"|"translation"|"location"|"version"|"language"
)";
        CHECK(cmp_file("discard.ts", "output_discard.csv", exp));
    }

    SECTION("don't delete unfinished")
    {
        const auto exp =
            R"("context"|"source"|"translation"|"location"|"version"|"language"
"ProgrammaSettmodel"|"h"|"h"|"../../../Ricette/programmasettmodel.cpp - 687"|"2.1"|"en_US"
"ProgrammaSettmodel"|"g"|""|"../../../Ricette/programmasettmodel.cpp - 655"|""|""
)";
        CHECK(cmp_file("unfinished.ts", "output_unfinished.csv", exp));
    }

    SECTION("complete conversion")
    {
        auto file_compare =
            TestHelper::absolute_path("csv_ts") + "complete_expected.csv";
        CHECK(cmp_file("complete.ts", "output_complete.csv",
                       Reader().read(std::move(file_compare))));
    }
}
