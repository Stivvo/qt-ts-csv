#pragma once

#include <string>

class TSReader
{
public:
    TSReader() = default;
    ~TSReader() = default;

    std::string do_it(std::string &&filename) const;
};