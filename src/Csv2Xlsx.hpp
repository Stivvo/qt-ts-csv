#pragma once

#include "IConverter.hpp"

class Csv2Xlsx : public IConverter
{
public:
    void convert(std::string &&filename, std::string &&output) override;
};
