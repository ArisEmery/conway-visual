//
//  PatternBlock.cpp
//  conway
//
//  Created by Aris  Emery on 11/10/20.
//  Copyright © 2020 Aris Emery. All rights reserved.
//

#include "PatternBlock.hpp"

Block::Block()
{
    for (uint8_t i = 0; i<m_pattern_info.size(); i++){
        for (uint8_t j = 0; j < m_pattern_info[0].size(); j++) {
            m_pattern_info[i][j]=false;
        }
    }
    m_pattern_info[0][0] = true;
    m_pattern_info[0][1] = true;
    m_pattern_info[1][0] = true;
    m_pattern_info[1][1] = true;

    
}

std::uint8_t Block::getSizeX() const{
    return 2;
}
std::uint8_t Block::getSizeY() const{
    return 2;
}
bool Block::getCell(std::uint8_t x, std::uint8_t y) const {
    return m_pattern_info[x][y];
}

Block::~Block() {};

