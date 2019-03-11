#include "Reader.hpp"

#include <fstream>
#include <sstream>
#include <qdebug.h>
#include <iostream>
#include <QFile>

std::string Reader::read(std::string &&filename) const
{
    QFile f(QString::fromStdString(filename));
    std::ifstream ifs;
    ifs.open(filename);
    std::stringstream ss;
    ss << ifs.rdbuf();
    return ss.str();
}
