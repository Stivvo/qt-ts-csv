#pragma once

#include "IConverter.hpp"

class Xlsx2Csv : public IConverter
{
public:
    void convert(std::string &&filename, std::string &&output) override;
};

