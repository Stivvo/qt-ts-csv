#include "Xlsx2csv.hpp"

#include "Writer.hpp"
#include "XlsxParser.hpp"
#include "CsvBuilder.hpp"

#include <sstream>

void Xlsx2Csv::convert(std::string &&filename, std::string &&output)
{

    /*XlsxBuilder().build(TsParser().parse(Reader().read(std::move(filename))),
                        std::move(output));

    Writer().write(TsBuilder().build(XlsxParser().parse(std::move(filename))),
                   std::move(output));*/

    Writer().write(CSVBuilder().build(XlsxParser().parse(std::move(filename))),
                   std::move(output));
}
