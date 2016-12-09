//
// Created by shrivathsav on 12/8/16.
//

#include "DE2Bot.h"

DE2Bot::DE2Bot() {
    x = 0;
    y = 0;
}

DE2Bot::DE2Bot(int somex, int somey, double someTheta) {
    x = somex;
    y = somey;
    theta = someTheta;
}

void DE2Bot::turn(double dTheta) {
    theta += dTheta;
}

void DE2Bot::turnTo(int newTheta) {
    theta = newTheta;
}

void DE2Bot::move(int dx, int dy) {
    x += dx;
    y += dy;
}

void DE2Bot::moveTo(int newx, int newy) {
    x = newx;
    y = newy;
}

int DE2Bot::getX() {
    return x;
}

int DE2Bot::getY() {
    return y;
}

double DE2Bot::getTheta() {
    return theta;
}

void DE2Bot::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

void DE2Bot::loadSprite() {
    if (texture.loadFromFile(spriteFilename)) {
        sprite.setTexture(texture);
    }
}