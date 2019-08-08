#pragma once

#include "TsPod.hpp"

#include <sstream>
//#include <xlsxdocument.h>

class XlsxBuilder
{
  public:
    void build(const TsPOD &ts, std::string name) const;
};
