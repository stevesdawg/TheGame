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
private:
    sf::RenderWindow* window;
    DE2Bot bot;
    std::vector<Wall> walls;
    std::vector<Bullet> bullets;
    void readKeyboardInputs();
};