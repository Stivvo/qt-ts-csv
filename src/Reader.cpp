#include "Reader.hpp"

#include <fstream>
#include <sstream>
#include <qdebug.h>
#include <iostream>
#include <QFile>

std::string Reader::read(std::string &&filename) const
{
    QFile f(QString::fromStdString(filename));
    qDebug() << f.exists();
    qDebug() << "filename qdebug: "<<filename.c_str();
    std::ifstream ifs;
    qDebug() << "filename qdebug: "<<filename.c_str();
    ifs.open(filename);
    std::stringstream ss;
    qDebug() << "ss: "<<QString::fromStdString(ss.str());
    ss << ifs.rdbuf();
    qDebug() <<ifs.rdbuf();
    qDebug() << "ss: "<<QString::fromStdString(ss.str());
    return ss.str();
}
