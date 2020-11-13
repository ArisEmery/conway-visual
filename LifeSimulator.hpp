//
//  LifeSimulator.hpp
//  conway
//
//  Created by Aris  Emery on 11/10/20.
//  Copyright © 2020 Aris Emery. All rights reserved.
//

#pragma once
#include "Pattern.hpp"
#include "rlutil.h"
#include <vector>
#include <cstdint>
#include <array>
//internal to life simulator, we maintain a grid of cells

class LifeSimulator
{
public:
    LifeSimulator(std::uint8_t sizeX, std::uint8_t sizeY);
    
    void insertPattern(const Pattern& pattern, std::uint8_t startX, std::uint8_t startY);
    void update();

    std::uint8_t getSizeX() const;
    std::uint8_t getSizeY() const;
    bool getCell(std::uint8_t x, std::uint8_t y) const;
    
private:
    int m_sizeX;
    int m_sizeY;
    std::vector<std::vector<bool>> grid;
    std::vector<std::vector<bool>> next_generation;


};

