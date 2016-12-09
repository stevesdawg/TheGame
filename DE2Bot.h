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
    DE2Bot(int somex, int somey, double someTheta);
    void turn(double dTheta);
    void turnTo(int newTheta);
    void move(int dx, int dy);
    void moveTo(int newx, int newy);

    int getX();
    int getY();
    double getTheta();
private:
    int x;
    int y;
    double theta;
    sf::Sprite sprite;
    sf::Texture texture;

    void loadSprite();
};