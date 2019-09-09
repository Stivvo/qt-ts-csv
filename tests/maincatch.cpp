#define CATCH_CONFIG_RUNNER

#include "TestHelper.hpp"

int main(int argc, char *argv[])
{
    TestHelper::init();

    Catch::Session session;
    int ret = session.applyCommandLine(argc, argv);
    if (ret != 0)
        return ret;
    int result = session.run(argc, argv);

    TestHelper::teardown();
    return result;
}
