//
// Created by shrivathsav on 12/8/16.
//

#pragma once

#include <SFML/Graphics.hpp>
#include <deque>
#include "Movable.h"

class DE2Bot : public Movable {
public:
    const int spriteSize = 64;
    const std::string spriteFilename = "botSprite.png";
    DE2Bot();
    DE2Bot(float somex, float somey, float someTheta, int walls);

    float getX();
    float getY();
    float getTheta();

    void turn(float dTheta);
    void turnTo(float newTheta);
    void move(float dx, float dy);
    void moveTo(float newx, float newy);
    void setNumWalls(int num);
    bool hasHitLeft();
    bool hasHitRight();
    bool hasHitTop();
    bool hasHitBottom();
    bool dead = false;
    bool botForward = false;
    bool botBackward = false;
    bool botRight = false;
    bool botLeft = false;
    bool shot = false;

    void move(sf::RenderWindow& window);
    void draw(sf::RenderWindow& window);

    std::deque<bool> leftHits;
    std::deque<bool> rightHits;
    std::deque<bool> topHits;
    std::deque<bool> bottomHits;

private:
    float x;
    float y;
    float theta;
    int numWalls;

    sf::Sprite sprite;
    sf::Texture texture;

    void loadSprite();
    void normalizeTheta();
};