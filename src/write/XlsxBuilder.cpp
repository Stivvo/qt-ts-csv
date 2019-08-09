#include "XlsxBuilder.hpp"

//#include "interfaces/c++/headers/OpenXLSX.h"
#include "OpenXLSX.h"

#include <chrono>
#include <iomanip>
#include <string>

void XlsxBuilder::build(const TsPOD &ts, std::string name) const
{
    OpenXLSX::XLDocument doc;
    doc.CreateDocument(name);
    doc.Workbook().AddWorksheet("sheet1");
    auto wbk = doc.Workbook();
    wbk.AddWorksheet("sheet1");
    auto wks = wbk.Worksheet("sheet1");

    int col = 1;
    int row = 1;

    wks.Cell("A1").Value() = "context";
    wks.Cell("A2").Value() = "source";
    wks.Cell("A3").Value() = "translation";
    wks.Cell("A4").Value() = "location";

    for (int i = 1; i < ts.max_locations; ++i)
        wks.Row(row).Cell(col++).Value() = "location";

    wks.Row(row).Cell(col++).Value() = "version";
    wks.Row(row).Cell(col++).Value() = "language";

    bool write_ver = true;
    for (const auto &c : ts) {
        for (const auto &d : c.translations) {
            col = 1;
            ++row;

            wks.Row(row).Cell(col++).Value() = c.name;
            wks.Row(row).Cell(col++).Value() = d.source;
            wks.Row(row).Cell(col++).Value() = d.tr;

            for (unsigned long long i = 0; i < ts.max_locations; ++i) {
                if (d.locations.size() != 0 && i <= d.locations.size() - 1) {
                    wks.Row(row).Cell(col++).Value() =
                        d.locations[i].path + " - " +
                        std::to_string(d.locations[i].line);
                } else
                    ++col;
            }
            if (write_ver) {
                write_ver                        = false;
                wks.Row(row).Cell(col++).Value() = ts.version;
                wks.Row(row).Cell(col++).Value() = ts.language;
            }
        }
    }
    doc.SaveDocument();
}
