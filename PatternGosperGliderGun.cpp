//
//  PatternGosperGliderGun.cpp
//  conway
//
//  Created by Aris  Emery on 11/10/20.
//  Copyright © 2020 Aris Emery. All rights reserved.
//

#include "PatternGosperGliderGun.hpp"

GosperGliderGun::GosperGliderGun()
{
    for (uint8_t i = 0; i<m_pattern_info.size(); i++){
        for (uint8_t j = 0; j < m_pattern_info[0].size(); j++) {
            m_pattern_info[i][j]=false;
        }
    }
    m_pattern_info[4][0] = true;
    m_pattern_info[4][1] = true;
    m_pattern_info[5][0] = true;
    m_pattern_info[5][1] = true;
    
    m_pattern_info[2][12] = true;
    m_pattern_info[2][13] = true;
    m_pattern_info[3][11] = true;
    m_pattern_info[3][15] = true;
    m_pattern_info[4][10] = true;
    m_pattern_info[4][16] = true;
    m_pattern_info[5][10] = true;
    m_pattern_info[5][14] = true;
    m_pattern_info[5][16] = true;
    m_pattern_info[5][17] = true;
    m_pattern_info[6][10] = true;
    m_pattern_info[6][16] = true;
    m_pattern_info[7][11] = true;
    m_pattern_info[7][15] = true;
    m_pattern_info[8][12] = true;
    m_pattern_info[8][13] = true;
    
    m_pattern_info[4][20] = true;
    m_pattern_info[3][20] = true;
    m_pattern_info[2][20] = true;
    m_pattern_info[4][21] = true;
    m_pattern_info[3][21] = true;
    m_pattern_info[2][21] = true;
    m_pattern_info[1][22] = true;
    m_pattern_info[5][22] = true;
    m_pattern_info[0][24] = true;
    m_pattern_info[1][24] = true;
    m_pattern_info[5][24] = true;
    m_pattern_info[6][24] = true;
    
    m_pattern_info[2][34] = true;
    m_pattern_info[2][35] = true;
    m_pattern_info[3][34] = true;
    m_pattern_info[3][35] = true;
}

std::uint8_t GosperGliderGun::getSizeX() const{
    return 36;
}
std::uint8_t GosperGliderGun::getSizeY() const{
    return 9;
}
bool GosperGliderGun::getCell(std::uint8_t x, std::uint8_t y) const {
    return m_pattern_info[x][y];
}

GosperGliderGun::~GosperGliderGun() {};
