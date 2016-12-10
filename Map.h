//
// Created by shrivathsav on 12/9/16.
//

#pragma once

#include <SFML/Graphics.hpp>
#include "DE2Bot.h"
#include "Wall.h"
#include "Bullet.h"

class Map {
public:
    Map();
    void drawObjects();
    const float xStep = 4;
    const float yStep = 4;
    const float thetaStep = 5;
private:
    sf::RenderWindow* window;
    DE2Bot bot;
    bool botUp = false;
    bool botDown = false;
    bool botRight = false;
    bool botLeft = false;
    std::vector<Wall*> walls;
    std::vector<Bullet*> bullets;
    void readKeyboardInputs();
    void processInputs();
    bool checkBotCollision(Wall* w);
};