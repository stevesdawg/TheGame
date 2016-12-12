//
// Created by shrivathsav on 12/8/16.
//

#include <math.h>
#include "DE2Bot.h"

DE2Bot::DE2Bot() {
    x = 0;
    y = 0;
    theta = 0;
    loadSprite();
}

DE2Bot::DE2Bot(float somex, float somey, float someTheta, int walls) {
    x = somex;
    y = somey;
    theta = someTheta;
    numWalls = walls;
    for (int i = 0; i < numWalls; i++) {
        leftHits.push_back(false);
        rightHits.push_back(false);
        topHits.push_back(false);
        bottomHits.push_back(false);
    }
    loadSprite();
}

void DE2Bot::turn(float dTheta) {
    theta += dTheta;
    normalizeTheta();
}

void DE2Bot::turnTo(float newTheta) {
    theta = newTheta;
    normalizeTheta();
}

void DE2Bot::move(float dx, float dy) {
    x += dx;
    y += dy;
}

void DE2Bot::moveTo(float newx, float newy) {
    x = newx;
    y = newy;
}

void DE2Bot::setNumWalls(int num) {
    numWalls = num;
    for (int i = 0; i < numWalls; i++) {
        leftHits.push_back(false);
        rightHits.push_back(false);
        topHits.push_back(false);
        bottomHits.push_back(false);
    }
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

bool DE2Bot::hasHitBottom() {
    bool b = false;
    for (int i = 0; i < numWalls; i++) {
        b = b || bottomHits[i];
    }
    return b;
}

bool DE2Bot::hasHitTop() {
    bool b = false;
    for (int i = 0; i < numWalls; i++) {
        b = b || topHits[i];
    }
    return b;
}

bool DE2Bot::hasHitRight() {
    bool b = false;
    for (int i = 0; i < numWalls; i++) {
        b = b || rightHits[i];
    }
    return b;
}

bool DE2Bot::hasHitLeft() {
    bool b = false;
    for (int i = 0; i < numWalls; i++) {
        b = b || leftHits[i];
    }
    return b;
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

void DE2Bot::normalizeTheta() {
    if (theta >= 360) {
        int quotient = (int) floor(theta / 360);
        theta = theta - quotient * 360;
    } else if (theta < 0) {
        theta = theta * -1;
        normalizeTheta();
        theta = 360 - theta;
    }
}