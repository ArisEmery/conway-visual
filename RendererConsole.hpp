//
//  RendererConsole.hpp
//  conway
//
//  Created by Aris  Emery on 11/10/20.
//  Copyright © 2020 Aris Emery. All rights reserved.
//

#pragma once
#include "Renderer.hpp"

class RendererConsole : public Renderer
{
public:
    virtual void render(const LifeSimulator& simulation) override;
};

