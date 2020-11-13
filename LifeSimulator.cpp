//
//  LifeSimulator.cpp
//  conway
//
//  Created by Aris  Emery on 11/10/20.
//  Copyright © 2020 Aris Emery. All rights reserved.
//

#include "LifeSimulator.hpp"
LifeSimulator::LifeSimulator(std::uint8_t sizeX, std::uint8_t sizeY) :
    m_sizeX(sizeX),
    m_sizeY(sizeY)
{
    for (int i = 0; i<sizeY; i++){
        std::vector<bool> temp;
        for (int j = 0; j < sizeX; j++) {
            temp.push_back(false);
        }
        grid.push_back(temp);
    }
    
    for (int i = 0; i<sizeY; i++){
        std::vector<bool> temp;
        for (int j = 0; j < sizeX; j++) {
            temp.push_back(false);
        }
        next_generation.push_back(temp);
    }
}

void LifeSimulator::insertPattern(const Pattern& pattern, std::uint8_t startX, std::uint8_t startY){
//    if (startX + pattern.getSizeX() > grid[0].size() || startY + pattern.getSizeY() > grid.size() ) {
//        startX = 0;
//        startY = 0;
//    }
    int x_offset = startX;
    int y_offset = startY;
    for (int i = 0; i<pattern.getSizeY(); i++){
        for (int j = 0; j < pattern.getSizeX(); j++) {
            grid[i+x_offset][j+y_offset]=pattern.getCell(i, j);
        }
    }
}
void LifeSimulator::update(){
//    Any live cell with two or three live neighbours survives.
//    Any dead cell with three live neighbours becomes a live cell.
//    All other live cells die in the next generation. Similarly, all other dead cells stay dead.

    
    
    for (int i = 0; i<m_sizeY; i++){
        for (int j = 0; j < m_sizeX; j++) {
            int num_neighbors=0;
            //west neighbor
            if (j-1 >= 0 && grid[i][j-1] == true) {
                num_neighbors++;
            }
            //northwest neighbor
            if (j-1 >= 0 && i-1 >= 0 && grid[i-1][j-1] == true) {
                num_neighbors++;
            }
            //north neighbor
            if (i-1 >= 0 and grid[i-1][j] == true) {
                num_neighbors ++;
            }
            //northeast neighbor
            if (j+1 < m_sizeX && i-1 >=0 && grid[i-1][j+1] == true) {
                num_neighbors++;
            }
            //east neighbor
            if (j+1 < m_sizeX && grid[i][j+1] == true) {
                num_neighbors ++;
            }
            //southeast neighbor
            if (j+1 < m_sizeX && i+1 < m_sizeY && grid[i+1][j+1] == true){
                num_neighbors ++;
            }
            //south neighbor
            if (i+1 < m_sizeY && grid[i+1][j] == true){
                num_neighbors ++;
            }
            //southwest neighbor
            if (i+1 < m_sizeY && j-1 >= 0 && grid[i+1][j-1] == true){
                num_neighbors ++;
            }
            
            //live or die
//            std::cout<<num_neighbors<<std::endl;
            if (grid[i][j] == true){
                if (num_neighbors < 2 || num_neighbors > 3) {
                    next_generation[i][j] = false;
                }else{
                    next_generation[i][j] = true;
                }
            }else{
                if (num_neighbors == 3) {
                    next_generation[i][j] = true;
                }
            }
        }
        
        
        
    }
    //copy next generation into the grid to complete update
    for (int i = 0; i<m_sizeY; i++){
        for (int j = 0; j < m_sizeX; j++) {
            grid[i][j] = next_generation[i][j];
        }
    }
}

std::uint8_t LifeSimulator::getSizeX() const{
    return m_sizeX;
}
std::uint8_t LifeSimulator::getSizeY() const{
    return m_sizeY;
}
bool LifeSimulator::getCell(std::uint8_t x, std::uint8_t y) const{
    return grid[x][y];
}
