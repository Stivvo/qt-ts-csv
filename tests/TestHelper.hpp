#pragma once

#include <Reader.hpp>
#include <catch.hpp>
#include <catch/Catch2/include/internal/catch_session.h>
#include <list>

class TestHelper
{
  private:
    static std::string sp;
    static std::string pth;
    static std::list<std::string> docs;

  public:
    static void init();
    static void teardown();

    static std::string fullPath(const std::string &fldr);
    static void pushDocs(const std::string &doc);
    static std::string findDiff(const std::string &docReaded,
                                const std::string &expected);
};
