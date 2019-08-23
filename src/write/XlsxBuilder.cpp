#include "XlsxBuilder.hpp"

#include <OpenXLSX.h>
#include <chrono>
#include <iomanip>
#include <string>

void XlsxBuilder::build(const TsPOD &ts, std::string &&name) const
{
    OpenXLSX::XLDocument doc;
    doc.CreateDocument(name);
    auto wbk = doc.Workbook();
    auto wks = wbk.Worksheet(wbk.WorksheetNames().at(0));

    unsigned int col = 5;
    unsigned int row = 1;

    wks.Cell("A1").Value() = "context";
    wks.Cell("B1").Value() = "source";
    wks.Cell("C1").Value() = "translation";
    wks.Cell("D1").Value() = "location";

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
                if (!d.locations.empty() && i <= d.locations.size() - 1) {
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
    doc.SaveDocumentAs(name);
}
