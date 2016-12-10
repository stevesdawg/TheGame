//
// Created by Kshitij Kulkarni on 12/9/16.
//

#pragma once

#include <math.h>
#include "Wall.h"

Wall::Wall(){
    x = 0;
    y = 0;
    length = 0;
    width = 0;
}
Wall::Wall(float x1, float y1, float length1, float width1) {
    x = x1;
    y = y1;
    length = length1;
    width = width1;
}

float Wall::getX() {
    return x;
}

float Wall::getY() {
    return y;
}

float Wall::getLength() {
    return length;
}

float Wall::getWidth() {
    return width;
}

void Wall::draw(sf::RenderWindow& window) {
    sf::RectangleShape rectObj;
    rectObj.setFillColor(sf::Color::Black);
    rectObj.setPosition(x, y);
    sf::Vector2f a(length, width);
    rectObj.setSize(a);
    window.draw(rectObj);
}