//
// Created by shrivathsav on 12/8/16.
//

#pragma once

#include <SFML/Graphics.hpp>
#include "Movable.h"


class DE2Bot : Movable {
public:
    const int spriteSize = 96;
    const std::string spriteFilename = "botSprite.png";
    DE2Bot();
    DE2Bot(float somex, float somey, float someTheta);

    float getX();
    float getY();
    float getTheta();

    void turn(float dTheta);
    void turnTo(float newTheta);
    void move(float dx, float dy);
    void moveTo(float newx, float newy);

    void move(sf::RenderWindow& window);
    void draw(sf::RenderWindow& window);
private:
    float x;
    float y;
    float theta;
    sf::Sprite sprite;
    sf::Texture texture;

    void loadSprite();
};