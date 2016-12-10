//
// Created by shrivathsav on 12/9/16.
//

#include "Bullet.h"

Bullet::Bullet() {
    x = 0;
    y = 0;
    theta = 0;
}

Bullet::Bullet(float somex, float somey, float someTheta) {
    x = somex;
    y = somey;
    theta = someTheta;
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

void Bullet::draw(sf::RenderWindow &window) {
    move(window);
}

void Bullet::move(sf::RenderWindow &window) {
    sf::CircleShape c;
    c.setRadius(10);
    c.setPosition(x, y);
    c.setFillColor(sf::Color::Black);
    window.draw(c);
}