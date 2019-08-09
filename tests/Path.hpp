#pragma once

#include <algorithm>
#include <experimental/filesystem>
#include <iostream>
#include <string>

class Path
{
  private:
    std::string sp;

  public:
    Path()
    {
#ifdef _WIN32
        sp = "\\";
#else
        sp = "/";
#endif
    }
    std::string get_files_basename() const noexcept
    {
        auto current = std::experimental::filesystem::current_path();
        auto str     = current.string();
        auto it      = str.find("build");
        if (it == std::string::npos) {
            return str;
        }

        std::string ret;
        str.erase(it, str.size());

        ret = str + "qt-ts-csv" + sp + "tests" + sp + "files" + sp;
        return ret;
    }
    void teardown(std::vector<std::string> &docs)
    {
        for (std::string &t : docs)
            std::experimental::filesystem::remove(t);
    }
    void initSep() {}
    std::string sep()
    {
        return sp;
    }
};
