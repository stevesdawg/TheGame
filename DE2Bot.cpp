//
// Created by shrivathsav on 12/8/16.
//

#include "DE2Bot.h"

DE2Bot::DE2Bot() {
    x = 0;
    y = 0;
    theta = 0;
    loadSprite();
}

DE2Bot::DE2Bot(float somex, float somey, float someTheta) {
    x = somex;
    y = somey;
    theta = someTheta;
    loadSprite();
}

void DE2Bot::turn(float dTheta) {
    theta += dTheta;
}

void DE2Bot::turnTo(float newTheta) {
    theta = newTheta;
}

void DE2Bot::move(float dx, float dy) {
    x += dx;
    y += dy;
}

void DE2Bot::moveTo(float newx, float newy) {
    x = newx;
    y = newy;
}

float DE2Bot::getX() {
    return x;
}

float DE2Bot::getY() {
    return y;
}

float DE2Bot::getTheta() {
    return theta;
}

void DE2Bot::move(sf::RenderWindow& window) {
    sprite.setPosition(x, y);
    sprite.setRotation(theta);
    window.draw(sprite);
}

void DE2Bot::draw(sf::RenderWindow& window) {
    move(window);
}

void DE2Bot::loadSprite() {
    if (texture.loadFromFile(spriteFilename)) {
        sprite.setTexture(texture);
        sprite.setOrigin(spriteSize/2, spriteSize/2);
    }
}