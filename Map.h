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
private:
    sf::RenderWindow* window;
    DE2Bot bot;
    DE2Bot networkBot;
    std::vector<Wall*> walls;
    std::vector<Bullet*> bullets;
    sf::Color background;
    sf::TcpSocket socket;
//    sf::TcpListener listener;
    void readKeyboardInputs();
    void processInputs(DE2Bot* bot);

    void checkBulletHit(Bullet* b, DE2Bot* bot);

    void checkBotLeftCollision(DE2Bot* bot);
    void checkBotRightCollision(DE2Bot* bot);
    void checkBotTopCollision(DE2Bot* bot);
    void checkBotBottomCollision(DE2Bot* bot);

    void checkBulletBottomCollision(Bullet* b);
    void checkBulletTopCollision(Bullet* b);
    void checkBulletRightCollision(Bullet* b);
    void checkBulletLeftCollision(Bullet* b);

//    void startServer();
    void startClient();
    void receive();
    void send();
};