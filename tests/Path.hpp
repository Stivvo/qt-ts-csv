#pragma once

#include <Reader.hpp>
#include <algorithm>
#include <experimental/filesystem>
#include <iostream>
#include <string>

struct Path {
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
    bool debug(std::string &doc, const std::string &expected) const noexcept
    {
        std::string docReaded = Reader().read(std::move(doc));

        // debug
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
        // end debug

        return docReaded == expected;
    }
};
