//
//  Pattern.hpp
//  conway
//
//  Created by Aris  Emery on 11/10/20.
//  Copyright © 2020 Aris Emery. All rights reserved.
//

#pragma once

#include <cstdint>
//derived class will have private data member on it

class Pattern
{
public:
    virtual std::uint8_t getSizeX() const = 0;
    virtual std::uint8_t getSizeY() const = 0;
    virtual bool getCell(std::uint8_t x, std::uint8_t y) const = 0;
};


