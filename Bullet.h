//
// Created by shrivathsav on 12/9/16.
//

#pragma once

#include <SFML/Graphics.hpp>
#include "Movable.h"
#include "DE2Bot.h"

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
    bool hasLeftBot = false;
    bool leave = false;

    void move(float dx, float dy);
    void moveTo(float newx, float newy);
    void turn(float dTheta);
    void turnTo(float newTheta);
    bool justLaunched(DE2Bot* bot);

    void move(sf::RenderWindow &window);
    void draw(sf::RenderWindow &window);

private:
    float x;
    float y;
    float theta;
    sf::Time creationTime;
    sf::Clock clock;
};