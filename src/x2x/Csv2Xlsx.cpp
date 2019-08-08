#include "Csv2Xlsx.hpp"

#include "CsvBuilder.hpp"
#include "CsvParser.hpp"
#include "Reader.hpp"
#include "Writer.hpp"
#include "XlsxBuilder.hpp"
#include "XlsxParser.hpp"

#include <sstream>

void Csv2Xlsx::convert(std::string &&filename, std::string &&output)
{
    XlsxBuilder().build(CsvParser().parse(Reader().read(std::move(filename))),
                        std::move(output));
}
