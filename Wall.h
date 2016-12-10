//
// Created by Kshitij Kulkarni on 12/9/16.
//

#pragma once

#include <SFML/Graphics.hpp>
#include "Drawable.h"

class Wall:Drawable {
public:
    Wall();
    Wall(float x, float y, float length, float width);

    float getX();
    float getY();
    float getLength();
    float getWidth();

    void draw(sf::RenderWindow& window);
private:
    float x;
    float y;
    float length;
    float width;
};