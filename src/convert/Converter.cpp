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
    std::string input  = source;
    std::string output = dest;

    if (input.empty() || output.empty()) {
        return QStringLiteral("Empty arguments");
    }

    if (input.find(".ts") != std::string::npos &&
        input.find(".csv") != std::string::npos &&
        input.find(".xlsx") != std::string::npos) {
        return QStringLiteral("Invalid extention");
    }

    if (input.find(".xlsx") != std::string::npos &&
        output.find(".ts") == std::string::npos) {
        return QStringLiteral("Invalid conversion");
    }
    if (input.find(".ts") != std::string::npos) {
        if (output.find(".csv") != std::string::npos) {
            Ts2Csv().convert(std::move(input), std::move(output));
        } else if (output.find(".xlsx") != std::string::npos) {
            Ts2Xlsx().convert(std::move(input), std::move(output));
        } else {
            return QStringLiteral("Invalid conversion");
        }
    } else if (input.find(".csv") != std::string::npos) {
        if (output.find(".ts") != std::string::npos) {
            Csv2Ts().convert(std::move(input), std::move(output));
        } else if (output.find(".xlsx") != std::string::npos) {
            Csv2Xlsx().convert(std::move(input), std::move(output));
        } else {
            return QStringLiteral("Invalid conversion");
        }
    } else if (input.find(".xlsx") != std::string::npos) {
        if (output.find(".csv") != std::string::npos) {
            Xlsx2Csv().convert(std::move(input), std::move(output));
        } else if (output.find(".ts") != std::string::npos) {
            Xlsx2Ts().convert(std::move(input), std::move(output));
        } else {
            return QStringLiteral("Invalid conversion");
        }
    }
    return QStringLiteral("Conversion terminated");
}

QString Converter::setSource(const QString &source)
{
    std::string sep = "///";
    std::string input;

    input = source.toStdString();

    this->source = input.substr(input.find(sep) + sep.length());

#ifdef __linux__
    this->source = "/" + this->source;
#endif

    return QString::fromStdString(this->source);
}

QString Converter::setDest(const QString &dest)
{
    std::string sep = "///";
    std::string input;

    input = dest.toStdString();

    this->dest = input.substr(input.find(sep) + sep.length());

#ifdef __linux__
    this->dest = "/" + this->dest;
#endif

    return QString::fromStdString(this->dest);
}
