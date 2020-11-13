//
//  PatternAcorn.hpp
//  conway
//
//  Created by Aris  Emery on 11/10/20.
//  Copyright © 2020 Aris Emery. All rights reserved.
//

#pragma once
#include <array>
#include "Pattern.hpp"

class Acorn : public Pattern
{
    
private:
    std::array<std::array<bool, 7>, 3> m_pattern_info;
    
public:
    Acorn();
    virtual std::uint8_t getSizeX() const override;
    virtual std::uint8_t getSizeY() const override;
    virtual bool getCell(std::uint8_t x, std::uint8_t y) const override;
    virtual ~Acorn();
};

