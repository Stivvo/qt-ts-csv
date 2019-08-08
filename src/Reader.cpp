#include "Reader.hpp"

#include <fstream>
#include <iostream>
#include <sstream>

std::string Reader::read(std::string &&filename) const
{
    std::ifstream ifs;
    ifs.open(filename);
    std::stringstream ss;
    ss << ifs.rdbuf();
    return ss.str();
}
