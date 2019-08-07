#pragma once

#include "TsPod.hpp"

#include <xlsxdocument.h>

class XlsxParser
{
  public:
    TsPOD parse(std::string &&name) const;

  private:
    std::string rmR(const std::string &s) const;
};
