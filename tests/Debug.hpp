#pragma once

#include "Reader.hpp"

#include <iostream>

struct Debug {
    static bool file_string_eq(std::string &doc, const std::string &expected)
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
