#include "Converter.hpp"

#include "Csv2Ts.hpp"
#include "Ts2Csv.hpp"
#include "Ts2Xlsx.hpp"
#include "Xlsx2Ts.hpp"

QString Converter::convert(const QString &source,
                           const QString &dest) const
{
    if (source.isEmpty() || dest.isEmpty()) {
        return "Empty arguments";
    }

    std::string sep = "///";
    std::string input = source.toStdString();
    input = input.substr(input.find(sep) + sep.length());
    std::string output = dest.toStdString();
    output = output.substr(output.find(sep) + sep.length());

    if (input.find(".ts") != std::string::npos &&
        input.find(".csv") != std::string::npos &&
        input.find(".xlsx") != std::string::npos) {
        return "Invalid extention";
    }

    if (input.find(".xlsx") != std::string::npos &&
        output.find(".ts") == std::string::npos) {
        return "Invalid conversion";
    }
    if (input.find(".ts") != std::string::npos) {
        if (output.find(".csv") != std::string::npos) {
            Ts2Csv().convert(std::move(input), std::move(output));
        } else if (output.find(".xlsx") != std::string::npos) {
            Ts2Xlsx().convert(std::move(input), std::move(output));
        } else {
            return "Invalid conversion";
        }
    } else if (input.find(".csv") != std::string::npos){
        if (output.find(".ts") != std::string::npos) {
            Csv2Ts().convert(std::move(input), std::move(output));
        } else {
            return "Invalid conversion";
        }
    } else {
        if (output.find(".ts") != std::string::npos) {
            Xlsx2Ts().convert(std::move(input), std::move(output));
        } else {
            return "Invalid conversion";
        }
    }
    return "Conversion terminated";
}

