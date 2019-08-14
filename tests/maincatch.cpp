#define CATCH_CONFIG_RUNNER

#include "TestHelper.hpp"

#include <catch.hpp>

std::string TestHelper::sp  = "";
std::string TestHelper::pth = "";
std::list<std::string> TestHelper::docs;

int main(int argc, char *argv[])
{
    TestHelper::init();
    //    int result = Catch::Session().run(argc, argv);
    TestHelper::teardown();
    return /*result*/ 0;
}
