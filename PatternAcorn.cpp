//
//  PatternAcorn.cpp
//  conway
//
//  Created by Aris  Emery on 11/10/20.
//  Copyright © 2020 Aris Emery. All rights reserved.
//

#include "PatternAcorn.hpp"

Acorn::Acorn()
{
    for (uint8_t i = 0; i<m_pattern_info.size(); i++){
        for (uint8_t j = 0; j < m_pattern_info[0].size(); j++) {
            m_pattern_info[i][j]=false;
        }
    }
    m_pattern_info[0][1] = true;
    m_pattern_info[1][3] = true;
    m_pattern_info[2][0] = true;
    m_pattern_info[2][1] = true;
    m_pattern_info[2][4] = true;
    m_pattern_info[2][5] = true;
    m_pattern_info[2][6] = true;

}

std::uint8_t Acorn::getSizeX() const{
    return 7;
}
std::uint8_t Acorn::getSizeY() const{
    return 3;
}
bool Acorn::getCell(std::uint8_t x, std::uint8_t y) const {
    return m_pattern_info[x][y];
}

Acorn::~Acorn() {};

