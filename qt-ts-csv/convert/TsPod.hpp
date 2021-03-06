#pragma once

#include <string>
#include <vector>

struct Location {
    std::string path;
    unsigned line{};

    bool operator==(const Location &other) const
    {
        bool ret = path == other.path && line == other.line;
        return ret;
    }

    bool operator!=(const Location &other) const
    {
        return !(*this == other);
    }
};

struct Translation {
    std::vector<Location> locations;
    std::string source;
    std::string tr;

    bool operator==(const Translation &other) const
    {
        if (tr != other.tr || source != other.source ||
            locations.size() != other.locations.size()) {
            return false;
        }

        for (size_t i = 0; i < locations.size(); ++i) {
            if (locations.at(i) != other.locations.at(i)) {
                return false;
            }
        }

        return true;
    }

    bool operator!=(const Translation &other) const
    {
        return !(*this == other);
    }
};

struct Context {
    std::string name;
    std::vector<Translation> translations;

    bool operator==(const Context &other) const
    {
        if (name != other.name ||
            translations.size() != other.translations.size()) {
            return false;
        }

        for (size_t i = 0; i < translations.size(); ++i) {
            if (translations.at(i) != other.translations.at(i)) {
                return false;
            }
        }

        return true;
    }

    bool operator!=(const Context &other) const
    {
        return !(*this == other);
    }
};

struct TsPOD : public std::vector<Context> {
    std::string language;
    std::string version;
    uint16_t max_locations{};

    bool operator==(const TsPOD &other) const
    {
        if (this->size() != other.size() || language != other.language ||
            version != other.version || max_locations != other.max_locations) {
            return false;
        }

        for (size_t i = 0; i < this->size(); ++i) {
            if (this->at(i) != other.at(i)) {
                return false;
            }
        }

        return true;
    }
};
