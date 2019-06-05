#include "Reader.hpp"

#include <QFile>
#include <fstream>
#include <iostream>
#include <sstream>

std::string Reader::read(std::string &&filename) const
{
    QFile f(QString::fromStdString(filename));
    std::ifstream ifs;
    ifs.open(filename);
    std::stringstream ss;
    ss << ifs.rdbuf();
    return ss.str();
}
