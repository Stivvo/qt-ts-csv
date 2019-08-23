#pragma once

#include "Reader.hpp"

#include <iostream>
#include <vector>

struct Debug {
    static std::string findDiff(std::string &docReaded,
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
