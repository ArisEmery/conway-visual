//
//  main.cpp
//  conway
//
//  Created by Aris  Emery on 11/10/20.
//  Copyright © 2020 Aris Emery. All rights reserved.
//
#include <cstdint>
#include <iostream>
#include <thread>
#include "rlutil.h"
#include "Pattern.hpp"
#include "PatternGosperGliderGun.hpp"
#include "LifeSimulator.hpp"
#include "PatternAcorn.hpp"
#include "PatternBlock.hpp"
#include "PatternBlinker.hpp"
#include "Renderer.hpp"
#include "RendererConsole.hpp"
#include "PatternGlider.hpp"


//todo look at destructors

int main() {

	std::vector<std::shared_ptr<Pattern>> patterns;
	uint8_t tester = 2;
	int waste = 4;
	if (waste == tester) {
		int waste2 = 10;
	}

	patterns.push_back(std::make_shared<GosperGliderGun>());
	patterns.push_back(std::make_shared<Acorn>());
	patterns.push_back(std::make_shared<Block>());
	patterns.push_back(std::make_shared<Blinker>());
	patterns.push_back(std::make_shared<Glider>());

	Renderer* renderer = new RendererConsole();

	for (int i = 0; i < 5; i++) {
		LifeSimulator simulation(static_cast<uint8_t>(rlutil::tcols()), static_cast<uint8_t>(rlutil::trows()));
		uint8_t x_coord = 1;
		uint8_t y_coord = 1;
		int iterations = 300;
		int sleepTime = 20;
		rlutil::cls();
		rlutil::locate((rlutil::tcols() / 2) - 20, rlutil::trows() / 2);
		rlutil::setColor(1);
		switch (i) {
		case 0:
			std::cout << "Pattern: Gosper glider gun. Generations: 300 \n";
			std::this_thread::sleep_for(std::chrono::milliseconds(2000));
			break;
		case 1:
			std::this_thread::sleep_for(std::chrono::milliseconds(2000));
			x_coord = rlutil::tcols() / 2;
			y_coord = rlutil::trows() / 2;
			iterations = 750;
			std::cout << "Pattern: Acorn. Generations: 750 \n";
			std::this_thread::sleep_for(std::chrono::milliseconds(2000));
			break;
		case 2:
			std::this_thread::sleep_for(std::chrono::milliseconds(2000));
			x_coord = rlutil::tcols() / 2;
			y_coord = rlutil::trows() / 2;
			iterations = 100;
			std::cout << "Pattern: Block. Generations: 100 \n";
			std::this_thread::sleep_for(std::chrono::milliseconds(2000));
			break;
		case 3:
			std::this_thread::sleep_for(std::chrono::milliseconds(2000));
			x_coord = rlutil::tcols() / 2;
			y_coord = rlutil::trows() / 2;
			iterations = 20;
			std::cout << "Pattern: Blinker. Generations: 20 \n";
			std::this_thread::sleep_for(std::chrono::milliseconds(2000));
			sleepTime = 250;
			break;
		case 4:
			std::this_thread::sleep_for(std::chrono::milliseconds(2000));
			x_coord = 1;
			y_coord = 1;
			iterations = 300;
			std::cout << "Pattern: Glider. Generations: 300 \n";
			std::this_thread::sleep_for(std::chrono::milliseconds(2000));
			break;

		default:
			break;
		}

		simulation.insertPattern(*patterns[i], y_coord, x_coord);

		for (int j = 0; j< iterations; j++) {
			renderer->render(simulation);
			simulation.update();
			std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime));
		}
	}
	//    std::cout<< "size of x:" << rlutil::tcols() <<std::endl;
	//    std::cout<< "size of y:" << rlutil::trows() <<std::endl;
	//    std::cout<< "size of x/2:" << rlutil::tcols()/2 <<std::endl;
	//    std::cout<< "size of y/2:" << rlutil::trows()/2 <<std::endl;


	return 0;
}