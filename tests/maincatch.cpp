#define CATCH_CONFIG_RUNNER

//#include "TestHelper.hpp"

#include <catch.hpp>

int main(int argc, char *argv[])
{
    //    TestHelper::init();
    int result = Catch::Session().run(argc, argv);
    //    TestHelper::teardown();

    return result;
}
