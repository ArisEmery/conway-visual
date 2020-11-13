//
//  RendererConsole.cpp
//  conway
//
//  Created by Aris  Emery on 11/10/20.
//  Copyright © 2020 Aris Emery. All rights reserved.


#include "LifeSimulator.hpp"
#include "RendererConsole.hpp"


void RendererConsole::render(const LifeSimulator& simulation){
    rlutil::cls();
    rlutil::hidecursor();
    for (int i = 0; i<simulation.getSizeY(); i++){
        for (int j = 0; j < simulation.getSizeX(); j++) {
            if (simulation.getCell(i, j) == true) {
                rlutil::locate(j, i);
                rlutil::setColor(4);
                rlutil::setChar('*');
            }
        }
        std::cout<<"\n";
    }
    rlutil::showcursor();
}
