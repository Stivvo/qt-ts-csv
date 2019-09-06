#include "Xlsx2csv.hpp"

#include "CsvBuilder.hpp"
#include "Writer.hpp"
#include "XlsxParser.hpp"

#include <sstream>

void Xlsx2Csv::convert(std::string &&filename, std::string &&output)
{
    Writer().write(CSVBuilder().build(XlsxParser().parse(std::move(filename))),
                   std::move(output));
}
