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
    const float xStep = 5;
    const float yStep = 5;
    const float thetaStep = 6;
private:
    sf::RenderWindow* window;
    DE2Bot bot;
    bool botForward = false;
    bool botBackward = false;
    bool botRight = false;
    bool botLeft = false;
    std::vector<Wall*> walls;
    std::vector<Bullet*> bullets;
    sf::Color background;
    void readKeyboardInputs();
    void processInputs();
    void checkLeftCollision(float *dx, float *dy);
    void checkRightCollision(float *dx, float *dy);
    void checkTopCollision(float *dx, float *dy);
    void checkBottomCollision(float *dx, float *dy);
};