//
//  PatternGlider.cpp
//  conway
//
//  Created by Aris  Emery on 11/10/20.
//  Copyright © 2020 Aris Emery. All rights reserved.
//

#include "PatternGlider.hpp"

Glider::Glider()
{
    for (uint8_t i = 0; i<m_pattern_info.size(); i++){
        for (uint8_t j = 0; j < m_pattern_info[0].size(); j++) {
            m_pattern_info[i][j]=false;
        }
    }
    m_pattern_info[0][2] = true;
    m_pattern_info[1][2] = true;
    m_pattern_info[2][2] = true;
    m_pattern_info[2][1] = true;
    m_pattern_info[1][0] = true;

    
    
}

std::uint8_t Glider::getSizeX() const{
    return 3;
}
std::uint8_t Glider::getSizeY() const{
    return 3;
}
bool Glider::getCell(std::uint8_t x, std::uint8_t y) const {
    return m_pattern_info[x][y];
}

Glider::~Glider() {};

