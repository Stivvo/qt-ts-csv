#include "Converter.hpp"

#include "Csv2Ts.hpp"
#include "Csv2Xlsx.hpp"
#include "Ts2Csv.hpp"
#include "Ts2Xlsx.hpp"
#include "Xlsx2Ts.hpp"
#include "Xlsx2csv.hpp"

#include <QFile>
#include <fstream>
#include <iostream>
#include <qdebug.h>
#include <sstream>

QString Converter::convert() const
{
    auto input  = this->source;
    auto output = this->dest;

    if (input.empty() || output.empty()) {
        return "Empty arguments";
    }

    if (input.find(".ts") == std::string::npos &&
        input.find(".csv") == std::string::npos &&
        input.find(".xlsx") == std::string::npos)
        return "Invalid input extension";

    if (output.find(".ts") == std::string::npos &&
        output.find(".csv") == std::string::npos &&
        output.find(".xlsx") == std::string::npos)
        return "Invalid output extension";

    if (input.find(".xlsx") != std::string::npos &&
        output.find(".xlsx") != std::string::npos)
        return "Cannot convert from xlsx to xlsx";
    if (input.find(".csv") != std::string::npos &&
        output.find(".csv") != std::string::npos)
        return "Cannot convert from csv to csv";
    if (input.find(".ts") != std::string::npos &&
        output.find(".ts") != std::string::npos)
        return "Cannot convert from ts to ts";

    if (input.find(".ts") != std::string::npos) {
        if (output.find(".csv") != std::string::npos) {
            Ts2Csv().convert(std::move(input), std::move(output));
        } else {
            Ts2Xlsx().convert(std::move(input), std::move(output));
        }
    } else if (input.find(".csv") != std::string::npos) {
        if (output.find(".ts") != std::string::npos) {
            Csv2Ts().convert(std::move(input), std::move(output));
        } else {
            Csv2Xlsx().convert(std::move(input), std::move(output));
        }
    } else { // input is .xlsx
        if (output.find(".csv") != std::string::npos) {
            Xlsx2Csv().convert(std::move(input), std::move(output));
        } else {
            Xlsx2Ts().convert(std::move(input), std::move(output));
        }
    }
    return "Conversion terminated";
}

QString Converter::setSource(const QString &source)
{
    return setPath(source, this->source);
}

void Converter::setSource(const std::string &source)
{
    this->source = source;
}

QString Converter::setDest(const QString &dest)
{
    return setPath(dest, this->dest);
}

void Converter::setDest(const std::string &dest)
{
    this->dest = dest;
}

QString Converter::setPath(const QString &path, std::string &thispath)
{
    if (!path.isEmpty()) {
        std::string sep = "///";

        thispath = path.toStdString();
        thispath = thispath.substr(thispath.find(sep) + sep.length());

#ifdef __linux__
        thispath = "/" + thispath;
#endif
    }
    return QString::fromStdString(thispath);
}
