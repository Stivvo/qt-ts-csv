#pragma once

#include <sstream>

class TsPOD;

class CSVBuilder
{
  public:
    std::ostringstream build(const TsPOD &ts) const;

  private:
    const std::string sep = "|";
    std::string rmR(const std::string &s) const;
};
