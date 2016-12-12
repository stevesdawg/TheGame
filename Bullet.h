//
// Created by shrivathsav on 12/9/16.
//

#pragma once

#include <SFML/Graphics.hpp>
#include "Movable.h"

class Bullet : public Movable {
public:
    Bullet();
    Bullet(float somex, float somey, float someTheta);

    float getX();
    float getY();
    float getTheta();

    float bulletXStep = 7;
    float bulletYStep = 7;
    const float bulletRadius = 5;
    const sf::Time lifeTime = sf::seconds(5);
    bool leave = false;

    void move(float dx, float dy);
    void moveTo(float newx, float newy);
    void turn(float dTheta);
    void turnTo(float newTheta);

    void move(sf::RenderWindow &window);
    void draw(sf::RenderWindow &window);

private:
    float x;
    float y;
    float theta;
    sf::Time creationTime;
    sf::Clock clock;
};