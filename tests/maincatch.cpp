#define CATCH_CONFIG_RUNNER

#include <catch.hpp>
#include <catch/Catch2/include/internal/catch_session.h>

int main(int argc, char *argv[])
{
    Catch::Session session;
    int ret = session.applyCommandLine(argc, argv);
    if (ret != 0) {
        return ret;
    }

    return session.run(argc, argv);
}
