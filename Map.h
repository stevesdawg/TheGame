//
// Created by shrivathsav on 12/9/16.
//

#pragma once

#include <SFML/Graphics.hpp>
#include "DE2Bot.h"

class Map {
public:
    Map();
    void drawObjects();
private:
    sf::RenderWindow* window;
    DE2Bot bot;
    void readKeyboardInputs();
};