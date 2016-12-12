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
Wall::Wall(float x1, float y1, float width1, float length1) {
    x = x1;
    y = y1;
    length = length1;
    width = width1;
    rect.setPosition(x, y);
    rect.setFillColor(sf::Color::Black);
    sf::Vector2f a(width, length);
    rect.setSize(a);
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
    window.draw(rect);
}

sf::RectangleShape* Wall::getRectangle() {
    return &rect;
}
