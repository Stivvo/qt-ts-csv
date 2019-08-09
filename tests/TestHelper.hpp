#pragma once

#include <algorithm>
#include <experimental/filesystem>
#include <string>

class TestHelper
{
  private:
    static std::string sp;
    static std::string pth;
    static std::vector<std::string> docs;

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
        for (std::string &t : docs)
            std::experimental::filesystem::remove(t);
    }
    static std::string sep()
    {
        return sp;
    }
    static std::string fullPath(std::string fldr)
    {
        return pth + fldr + sp;
    }
};
