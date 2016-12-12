//
// Created by shrivathsav on 12/9/16.
//

#pragma once

#include <math.h>
#include <cmath>
#include <iostream>
#include "Map.h"

Map::Map() {
    window = new sf::RenderWindow(sf::VideoMode(1440, 1080), "TheGame");
    bot.moveTo(300, 300);
    Wall* w = new Wall(341, 200, 10, 500);
    Wall* w2 = new Wall(341, 200, 500, 10);
    Wall* w3 = new Wall(841, 200, 10, 500);
    Wall* w4 = new Wall(0, 0, 1440, 10);
    Wall* w5 = new Wall(0, 0, 10, 1080);
    Wall* w6 = new Wall(1420, 0, 10, 1080);
    Wall* w7 = new Wall(0, 1020, 1440, 10);
    walls.push_back(w);
    walls.push_back(w2);
    walls.push_back(w3);
    walls.push_back(w4);
    walls.push_back(w5);
    walls.push_back(w6);
    walls.push_back(w7);
    background = sf::Color::White;
    bot.setNumWalls(walls.size());
}

void Map::drawObjects() {
    window->clear(background);
    readKeyboardInputs();
    processInputs();
    bot.draw(*window);
    for (Wall* w : walls) {
        w->draw(*window);
    }
    if (bullets.size() > 0) {
        for (Bullet* b : bullets) {
            b->move(b->bulletXStep * (float) cos(b->getTheta() * M_PI / 180),
                   b->bulletYStep * (float) sin(b->getTheta() * M_PI / 180));
            checkBulletTopCollision(b);
            checkBulletRightCollision(b);
            checkBulletLeftCollision(b);
            checkBulletBottomCollision(b);
            b->draw(*window);
        }
    }
    window->display();
}

void Map::readKeyboardInputs() {
    sf::Event event;
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Up) {
                botForward = true;
            }
            if (event.key.code == sf::Keyboard::Down) {
                botBackward = true;
            }
            if (event.key.code == sf::Keyboard::Left) {
                botLeft = true;
            }
            if (event.key.code == sf::Keyboard::Right) {
                botRight = true;
            }
            if (event.key.code == sf::Keyboard::M) {
                Bullet *b = new Bullet(bot.getX(), bot.getY(), bot.getTheta());
                bullets.push_back(b);
            }
            if (event.key.code == sf::Keyboard::P) {
                std::cout << "Bot X: " << bot.getX() << std::endl;
                std::cout << "Bot Y: " << bot.getY() << std::endl;
                std::cout << "Bot Theta: " << bot.getTheta() << std::endl << std::endl;
            }
        } else if (event.type == sf::Event::KeyReleased) {
            if (event.key.code == sf::Keyboard::Up) {
                botForward = false;
            }
            if (event.key.code == sf::Keyboard::Down) {
                botBackward = false;
            }
            if (event.key.code == sf::Keyboard::Left) {
                botLeft = false;
            }
            if (event.key.code == sf::Keyboard::Right) {
                botRight = false;
            }
        }
        else if (event.type == sf::Event::Closed) {
            window->close();
        }
    }
}

void Map::checkBulletBottomCollision(Bullet* b) {
    for (int i = 0; i < walls.size(); i++) {
        Wall* w = walls[i];
        sf::RectangleShape* rect = w->getRectangle();
        float wx = w->getX();
        float wy = w->getY();
        float x = b->getX();
        float y = b->getY();
        float tolerance = 5;
        if (std::abs((y - b->bulletRadius) - (wy + w->getLength())) <= tolerance && wx <= (x + b->bulletRadius) &&
            wx + w->getWidth() >= (x - b->bulletRadius/2)) {
            rect->setFillColor(sf::Color::Red);
            b->bulletYStep *= -1;
        }
    }
}

void Map::checkBulletLeftCollision(Bullet *b) {
    for (int i = 0; i < walls.size(); i++) {
        Wall *w = walls[i];
        sf::RectangleShape *rect = w->getRectangle();
        float wx = w->getX();
        float wy = w->getY();
        float x = b->getX();
        float y = b->getY();
        float tolerance = 5;
        // check if hit left side of wall:
        if (std::abs((x + b->bulletRadius) - wx) <= tolerance && wy <= (y + b->bulletRadius) && wy + w->getLength() >= (y - b->bulletRadius)) {
            rect->setFillColor(sf::Color::Blue);
            b->bulletXStep *= -1;
        }
    }
}

void Map::checkBulletRightCollision(Bullet *b) {
    for (int i = 0; i < walls.size(); i++) {
        Wall *w = walls[i];
        sf::RectangleShape *rect = w->getRectangle();
        float wx = w->getX();
        float wy = w->getY();
        float x = b->getX();
        float y = b->getY();
        float tolerance = 5;
        // check if hit right side of wall:
        if (std::abs((x - b->bulletRadius) - (wx + w->getWidth())) <= tolerance && wy <= (y + b->bulletRadius) &&
            wy + w->getLength() >= (y - b->bulletRadius)) {
            rect->setFillColor(sf::Color::Cyan);
            b->bulletXStep *= -1;
        }
    }
}

void Map::checkBulletTopCollision(Bullet *b) {
    for (int i = 0; i < walls.size(); i++) {
        Wall *w = walls[i];
        sf::RectangleShape *rect = w->getRectangle();
        float wx = w->getX();
        float wy = w->getY();
        float x = b->getX();
        float y = b->getY();
        float tolerance = 5;
        // check if hit top side of wall:
        if (std::abs((y + b->bulletRadius) - wy) <= tolerance && wx <= (x + b->bulletRadius) &&
            wx + w->getWidth() >= (x - b->bulletRadius)) {
            rect->setFillColor(sf::Color::Magenta);
            b->bulletYStep *= -1;
        }
    }
}

void Map::processInputs() {
    float theta = bot.getTheta();
    const float standardXStep = xStep * (float) cos(theta * M_PI / 180);
    const float standardYStep = yStep * (float) sin(theta * M_PI / 180);
    float dx = standardXStep;
    float dy = standardYStep;
    checkBotBottomCollision();
    checkBotRightCollision();
    checkBotTopCollision();
    checkBotLeftCollision();
    if (botForward) {
        if (bot.hasHitLeft()) { // NO NEED TO CHECK CORNERS!!!
            dy = standardYStep;
            if (theta <= 270 && theta >= 90) {
                dx = standardXStep;
            } else {
                dx = 0;
            }
        }
        if (bot.hasHitRight()) { // NO NEED TO CHECK CORNERS!!!
            dy = standardYStep;
            if (theta >= 270 || theta <= 90) {
                dx = standardXStep;
            } else {
                dx = 0;
            }
        }
        if (bot.hasHitTop()) { // hit a wall from top
            if (bot.hasHitRight()) { // hit bottom left corner
                std::cout << "HIT BOTTOM LEFT CORNER!" << std::endl;
                if (theta >= 180) {
                    dy = standardYStep;
                    if (theta >= 270) {
                        dx = standardXStep;
                    } else {
                        dx = 0;
                    }
                } else {
                    dy = 0;
                    if (theta <= 90) {
                        dx = standardXStep;
                    } else {
                        dx = 0;
                    }
                }
            } else if (bot.hasHitLeft()) { // hit bottom right corner
                std::cout << "HIT BOTTOM RIGHT CORNER!" << std::endl;
                if (theta >= 90) {
                    dx = standardXStep;
                    dy = 0;
                    if (theta >= 180) {
                        dy = standardYStep;
                    }
                    if (theta >= 270) {
                        dx = 0;
                    }
                } else {
                    dx = 0;
                    dy = 0;
                }
            } else { // no corner hit
                dx = standardXStep;
                if (theta >= 180) {
                    dy = standardYStep;
                } else {
                    dy = 0;
                }
            }
        }
        if (bot.hasHitBottom()) { // hit a wall from below
            if (bot.hasHitRight()) { // hit top left corner
                std::cout << "HIT TOP LEFT CORNER!" << std::endl;
                if (theta <= 180) {
                    dy = standardYStep;
                    dx = 0;
                    if (theta <= 90) {
                        dx = standardXStep;
                    }
                } else {
                    dy = 0;
                    dx = 0;
                    if (theta >= 270) {
                        dx = standardXStep;
                    }
                }
            } else if (bot.hasHitLeft()) { // hit top right corner
                std::cout << "HIT TOP RIGHT CORNER!" << std::endl;
                if (theta <= 270) {
                    dx = standardXStep;
                    dy = 0;
                    if (theta <= 180) {
                        dy = standardYStep;
                    }
                    if (theta <= 90) {
                        dx = 0;
                    }
                } else {
                    dy = 0;
                    dx = 0;
                }
            } else { // no corner
                dx = standardXStep;
                if (theta <= 180) {
                    dy = standardYStep;
                } else {
                    dy = 0;
                }
            }
        }
        bot.move(dx, dy);
    }
    if (botBackward) {
        if (bot.hasHitLeft()) { // NO NEED TO CHECK CORNERS
            dy = standardYStep;
            if (theta >= 270 || theta <= 90) {
                dx = standardXStep;
            } else {
                dx = 0;
            }
        }
        if (bot.hasHitRight()) {
            dy = standardYStep;
            if (theta <= 270 && theta >= 90) { // NO NEED TO CHECK CORNERS
                dx = standardXStep;
            } else {
                dx = 0;
            }
        }
        if (bot.hasHitTop()) { // hit a wall from top
            if (bot.hasHitRight()) { // hit bottom left corner
                std::cout << "HIT BOTTOM LEFT CORNER!" << std::endl;
                if (theta <= 270) {
                    dx = standardXStep;
                    dy = 0;
                    if (theta <= 180) {
                        dy = standardYStep;
                    }
                    if (theta <= 90) {
                        dx = 0;
                    }
                } else {
                    dx = 0;
                    dy = 0;
                }
            } else if (bot.hasHitLeft()) { // hit bottom right corner
                std::cout << "HIT BOTTOM RIGHT CORNER!" << std::endl;
                if (theta <= 180) {
                    dx = 0;
                    dy = standardYStep;
                    if (theta <= 90) {
                        dx = standardXStep;
                    }
                } else {
                    dx = 0;
                    dy = 0;
                    if (theta >= 270) {
                        dx = standardXStep;
                    }
                }
            } else { // no corner hit
                dx = standardXStep;
                if (theta <= 180) {
                    dy = standardYStep;
                } else {
                    dy = 0;
                }
            }
        }
        if (bot.hasHitBottom()) { // hit a wall from below
            if (bot.hasHitRight()) { // hit top left corner
                std::cout << "HIT TOP LEFT CORNER!" << std::endl;
                if (theta >= 180) {
                    dy = standardYStep;
                    dx = standardXStep;
                    if (theta >= 270) {
                        dx = 0;
                    }
                } else {
                    dy = 0;
                    dx = standardXStep;
                    if (theta <= 90) {
                        dx = 0;
                    }
                }
            } else if (bot.hasHitLeft()) { // hit top right corner
                std::cout << "HIT TOP RIGHT CORNER!" << std::endl;
                if (theta >= 180) {
                    dy = standardYStep;
                    dx = 0;
                    if (theta >= 270) {
                        dx = standardYStep;
                    }
                } else {
                    dy = 0;
                    dx = 0;
                    if (theta <= 90) {
                        dx = standardXStep;
                    }
                }
            } else { // no corner
                dx = standardXStep;
                if (theta >= 180) {
                    dy = standardYStep;
                } else {
                    dy = 0;
                }
            }
        }
        dx *= -1;
        dy *= -1;
        bot.move(dx, dy);
    }
    if (botLeft) {
        bot.turn(-thetaStep);
    }
    if (botRight) {
        bot.turn(thetaStep);
    }
}

void Map::checkBotLeftCollision() {
    for (int i = 0; i < walls.size(); i++) {
        Wall* w = walls[i];
        float wx = w->getX();
        float wy = w->getY();
        float x = bot.getX();
        float y = bot.getY();
        float tolerance = 5;
        sf::RectangleShape* rect = w->getRectangle();
        // check if hit left side of wall:
        if (std::abs((x + bot.spriteSize/2) - wx) <= tolerance && wy <= (y + bot.spriteSize/2) && wy + w->getLength() >= (y - bot.spriteSize/2)) {
            rect->setFillColor(sf::Color::Blue);
            bot.leftHits[i] = true;
        } else {
            bot.leftHits[i] = false;
        }
    }
}

void Map::checkBotRightCollision() {
    for (int i = 0; i < walls.size(); i++) {
        Wall* w = walls[i];
        float wx = w->getX();
        float wy = w->getY();
        float x = bot.getX();
        float y = bot.getY();
        float tolerance = 3;
        sf::RectangleShape* rect = w->getRectangle();
        // check if hit right side of wall:
        if (std::abs((x - bot.spriteSize/2) - (wx + w->getWidth())) <= tolerance && wy <= (y + bot.spriteSize/2) &&
            wy + w->getLength() >= (y - bot.spriteSize/2)) {
            rect->setFillColor(sf::Color::Cyan);
            bot.rightHits[i] = true;
        } else {
            bot.rightHits[i] = false;
        }
    }
}

void Map::checkBotTopCollision() {
    for (int i = 0; i < walls.size(); i++) {
        Wall* w = walls[i];
        float wx = w->getX();
        float wy = w->getY();
        float x = bot.getX();
        float y = bot.getY();
        float tolerance = 3;
        sf::RectangleShape* rect = w->getRectangle();
        // check if hit top side of wall:
        if (std::abs((y + bot.spriteSize/2) - wy) <= tolerance && wx <= (x + bot.spriteSize/2) && wx + w->getWidth() >= (x - bot.spriteSize/2)) {
            rect->setFillColor(sf::Color::Magenta);
            bot.topHits[i] = true;
        } else {
            bot.topHits[i] = false;
        }
    }
}

void Map::checkBotBottomCollision() {
    for (int i = 0; i < walls.size(); i++) {
        Wall* w = walls[i];
        float wx = w->getX();
        float wy = w->getY();
        float x = bot.getX();
        float y = bot.getY();
        float tolerance = 3;
        sf::RectangleShape* rect = w->getRectangle();
        // check if hit bottom side of wall:
        if (std::abs((y - bot.spriteSize/2) - (wy + w->getLength())) <= tolerance && wx <= (x + bot.spriteSize/2) &&
            wx + w->getWidth() >= (x - bot.spriteSize/2)) {
            rect->setFillColor(sf::Color::Red);
            bot.bottomHits[i] = true;
        } else {
            bot.bottomHits[i] = false;
        }
    }
}
