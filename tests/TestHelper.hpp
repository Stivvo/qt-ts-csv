#pragma once

#include "Reader.hpp"

#include <algorithm>
#include <experimental/filesystem>
#include <iostream>
#include <list>
#include <string>
#include <vector>

class TestHelper
{
  private:
    static std::string sp;
    static std::string pth;
    static std::list<std::string> docs;

  public:
    static void init()
    {
        //        start sp based on the user's platform
#ifdef _WIN32
        sp = "\\";
#else
        sp = "/";
#endif

        // start pth based on the current path position + test files path
        auto current = std::experimental::filesystem::current_path();
        auto str     = current.string();
        auto it      = str.find("build");
        if (it == std::string::npos) {
            return;
        }
        str.erase(it, str.size());
        pth = str + "qt-ts-csv" + sp + "tests" + sp + "files" + sp;
    }
    static void teardown()
    {
        while (!docs.empty()) {
            std::experimental::filesystem::remove(docs.front());
            docs.pop_front();
        }
    }
    static std::string fullPath(std::string fldr)
    {
        return pth + fldr + sp;
    }
    static void pushDocs(std::string doc)
    {
        docs.push_front(doc);
    }
    static std::string findDiff(const std::string &docReaded,
                                const std::string &expected)
    {
        std::string diffs = "";
        int j             = 0;
        for (int i = 0; i < expected.size(); ++i) {
            if (expected[i] == docReaded[j])
                ++j;
            else
                diffs += expected[i];
        }
        std::cout << "docReaded: " << std::endl << docReaded << std::endl;
        std::cout << "expected: " << std::endl << expected << std::endl;

        std::cout << "docReaded size: " << docReaded.size() << std::endl;
        std::cout << "expected size: " << expected.size() << std::endl;
        std::cout << "j: " << j << ", diffs.size: " << diffs.size() << std::endl
                  << std::endl;

        return diffs;
    }
};
