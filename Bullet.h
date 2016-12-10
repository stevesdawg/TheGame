//
// Created by shrivathsav on 12/9/16.
//

#pragma once

#include <SFML/Graphics.hpp>

class Bullet : Movable {
public:
    Bullet();
    Bullet(float somex, float somey, float someTheta);

    float getX();
    float getY();
    float getTheta();

    void move(float dx, float dy);
    void moveTo(float newx, float newy);
    void turn(float dTheta);
    void turnTo(float newTheta);

    void move(sf::RenderWindow& window);
    void draw(sf::RenderWindow& window);

private:
    float x;
    float y;
    float theta;
};