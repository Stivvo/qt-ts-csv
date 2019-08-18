#include "XlsxParser.hpp"

#include <OpenXLSX.h>
#include <algorithm>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <istream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <string>

template<class Container> void split1(const std::string &str, Container &cont)
{
    std::istringstream iss(str);
    std::copy(std::istream_iterator<std::string>(iss),
              std::istream_iterator<std::string>(), std::back_inserter(cont));
}

TsPOD XlsxParser::parse(std::string &&name) const
{
    OpenXLSX::XLDocument doc;
    doc.OpenDocument(name);
    auto wbk = doc.Workbook();
    auto wks = wbk.Worksheet(wbk.WorksheetNames().at(0));

    TsPOD ret;
    unsigned int row = 1;
    unsigned int col = 0;
    std::string cell;

    do {
        col++;
        cell = wks.Row(row).Cell(col).Value().AsString();
    } while (cell != "language");

    unsigned int row_lenght                 = col;
    unsigned int Context                    = 1;
    unsigned int Source                     = 2;
    unsigned int Translation                = 3;
    unsigned int Version                    = row_lenght - 1;
    unsigned int Language                   = row_lenght;
    const unsigned short field_not_location = 5;
    ret.max_locations =
        static_cast<unsigned short>(row_lenght) - field_not_location;

    for (row = 2; row < wks.RowCount() + 1; ++row) {
        bool mpty = true;
        struct Context c;
        struct Translation t;
        for (col = 1; col <= row_lenght; col++) {
            if (wks.Row(row).Cell(col).Value().AsString().empty())
                cell.clear();
            else {
                mpty = false;
                cell = wks.Row(row).Cell(col).Value().Get<std::string>();
            }

            if (col == Context) {
                c.name = cell;
            } else if (col == Source) {
                t.source = rmR(cell);
            } else if (col == Translation) {
                t.tr = rmR(cell);
            } else if (col == Language) {
                ret.language = ret.language.empty() ? cell : ret.language;
            } else if (col == Version) {
                ret.version = ret.version.empty() ? cell : ret.version;
            } else {
                Location l;
                std::vector<std::string> loc;
                split1(cell, loc);

                if (loc.empty() || cell.empty())
                    continue;

                l.path = loc.front();
                l.line = static_cast<unsigned>(std::stoi(loc.back()));
                t.locations.emplace_back(std::move(l));
            }
        }
        c.translations.emplace_back(std::move(t));
        if (!mpty)
            ret.emplace_back(std::move(c));
    }
    doc.CloseDocument();
    return ret;
}

std::string XlsxParser::rmR(const std::string &s) const
{
    std::string out;
    for (char i : s) {
        if (i != '\r')
            out += i;
    }
    return out;
}
