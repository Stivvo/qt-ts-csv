#pragma once

#include "Csv2Xlsx.hpp"

#include "Writer.hpp"
#include "Reader.hpp"
#include "XlsxParser.hpp"
#include "CsvBuilder.hpp"
#include "XlsxBuilder.hpp"
#include "CsvParser.hpp"
#include "CsvParser.hpp"

#include <sstream>

void Csv2Xlsx::convert(std::string &&filename, std::string &&output)
{
    XlsxBuilder().build(CsvParser().parse(Reader().read(std::move(filename))),
                        std::move(output));
}
