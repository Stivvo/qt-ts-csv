#pragma once

#include <algorithm>
#include <experimental/filesystem>
#include <string>

class Path
{
  public:
    std::string get_files_basename() const noexcept
    {
        auto current = std::experimental::filesystem::current_path();
        auto str     = current.string();
        auto it      = str.find("build");
        if (it == std::string::npos) {
            return str;
        }

        str.erase(it, str.size());
        return (str + "qt-ts-csv/tests/files/");
    }
};
