#include "csvbuilder.hpp"

#include "tspod.hpp"

static const char sep[] = ";";

void replace_all(std::string &str, const std::string &from, const std::string &to)
{
    if (from.empty()) { return; }
    size_t start_pos = 0;
    while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }
}

std::string fix_return(std::string input)
{
    replace_all(input, "\n", "\\n");
    return input;
}

std::ostringstream CSVBuilder::build(const TsPOD &ts,
                                     unsigned short max_locations) const
{
    std::ostringstream oss;
    oss << "\"" << "context" << "\"" << sep
        << "\"" << "source" << "\"" << sep
        << "\"" << "translation" << "\"" << sep
        << "\"" << "location" << "\"" << sep;

    for (int var = 0; var < max_locations - 1; ++var) {
        oss << "\"" << "location" << "\"" << sep;
    }

    oss << "\"" << "version" << "\"" << sep
        << "\"" << "language" << "\"" << sep
        << std::endl;

    bool write_ver = true;
    for (const auto &c : ts) {
        for (const auto &d : c.translations) {
            oss << "\"" << c.name << "\"" << sep;
            oss << "\"" << fix_return(d.source) << "\"" << sep;
            oss << "\"" << fix_return(d.tr) << "\"" << sep;
            for (unsigned short j = 0; j < max_locations; ++j) {
                if (j <= d.locations.size() - 1) {
                    oss << "\"" << d.locations[j].path << " - " << d.locations[j].line << "\"";
                }
                oss << sep;
            }
            if (write_ver) {
                write_ver = false;
                oss << "\"" << ts.version << "\"" << sep
                    << "\"" << ts.language << "\"" << sep << std::endl;
            } else {
                oss << "\"" << "\"" << sep << "\""<< "\"" << sep << std::endl;
            }
        }
    }

    return oss;
}