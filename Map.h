//
// Created by shrivathsav on 12/9/16.
//

#pragma once

#include <SFML/Graphics.hpp>
#include "DE2Bot.h"
#include "Wall.h"
#include "Bullet.h"
#include <iostream>
#include <SFML/Network.hpp>

class Map {
public:
    Map();
    void drawObjects();
    const float xStep = 5;
    const float yStep = 5;
    const float thetaStep = 6;
    const int numBullets = 5;
private:
    sf::RenderWindow* window;
    DE2Bot bot;
    DE2Bot networkBot;
    std::vector<Wall*> walls;
    std::vector<Bullet*> bullets;
    sf::Color background;
    sf::TcpSocket socket;
    sf::TcpListener listener;
    bool hasShot = false;
    void readKeyboardInputs();
    void processInputs(DE2Bot*);

    void checkBulletHit(Bullet* b, DE2Bot*);

    void checkBotLeftCollision(DE2Bot*);
    void checkBotRightCollision(DE2Bot*);
    void checkBotTopCollision(DE2Bot*);
    void checkBotBottomCollision(DE2Bot*);

    void checkBulletBottomCollision(Bullet* b);
    void checkBulletTopCollision(Bullet* b);
    void checkBulletRightCollision(Bullet* b);
    void checkBulletLeftCollision(Bullet* b);

    void startServer();
    void startClient();
    void receive();
    void send();
};