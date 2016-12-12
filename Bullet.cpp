//
// Created by shrivathsav on 12/9/16.
//

#include "Bullet.h"

Bullet::Bullet() {
    x = 0;
    y = 0;
    theta = 0;
    clock.restart();
    creationTime = clock.getElapsedTime();
}

Bullet::Bullet(float somex, float somey, float someTheta) {
    x = somex;
    y = somey;
    theta = someTheta;
    clock.restart();
    creationTime = clock.getElapsedTime();
}

float Bullet::getX() {
    return x;
}

float Bullet::getY() {
    return y;
}

float Bullet::getTheta() {
    return theta;
}

void Bullet::move(float dx, float dy) {
    x += dx;
    y += dy;
}

void Bullet::moveTo(float newx, float newy) {
    x = newx;
    y = newy;
}

void Bullet::turn(float dTheta) {
    theta += dTheta;
}

void Bullet::turnTo(float newTheta) {
    theta = newTheta;
}

bool Bullet::justLaunched(DE2Bot* bot) {
    if (hasLeftBot) {
        return !hasLeftBot;
    } else {
        float x = this->getX();
        float y = this->getY();
        float botx = bot->getX();
        float boty = bot->getY();
        bool insideBot = (x >= botx && x - bot->spriteSize/2 <= botx + bot->spriteSize/2 && y >= boty - bot->spriteSize/2 && y <= boty + bot->spriteSize/2);
        hasLeftBot = !insideBot;
        return !hasLeftBot;
    }
}

void Bullet::draw(sf::RenderWindow &window) {
    move(window);
}

void Bullet::move(sf::RenderWindow &window) {
    sf::CircleShape c;
    c.setRadius(bulletRadius);
    c.setPosition(x, y);
    c.setFillColor(sf::Color::Black);
    window.draw(c);
    sf::Time stamp = clock.getElapsedTime();
    if (stamp - creationTime >= lifeTime) {
        leave = true;
    }
}