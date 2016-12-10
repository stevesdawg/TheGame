//
// Created by shrivathsav on 12/9/16.
//

#pragma once

#include "Map.h"

Map::Map() {
    window = new sf::RenderWindow(sf::VideoMode(1024, 768), "TheGame");
    bot.moveTo(300, 300);
    Wall* w = new Wall(5, 5, 500, 3);
    walls.push_back(w);
}

void Map::drawObjects() {
    window->clear(sf::Color::White);
    readKeyboardInputs();
    processInputs();
    bot.draw(*window);
    for (Wall* w : walls) {
        w->draw(*window);
    }
    if (bullets.size() > 0) {
        for (Bullet* b : bullets) {
            float bulletXStep = 5;
            float bulletYStep = 5;
            b->move(bulletXStep * (float) cos(b->getTheta() * M_PI / 180),
                   bulletYStep * (float) sin(b->getTheta() * M_PI / 180));
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
                botUp = true;
            }
            if (event.key.code == sf::Keyboard::Down) {
                botDown = true;
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
        } else if (event.type == sf::Event::KeyReleased) {
            if (event.key.code == sf::Keyboard::Up) {
                botUp = false;
            }
            if (event.key.code == sf::Keyboard::Down) {
                botDown = false;
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

void Map::processInputs() {
    float xStep = 4;
    float yStep = 4;
    float thetaStep = 5;
    float theta = bot.getTheta();
    if (botUp) {
        bot.move(xStep * (float) cos(theta * M_PI / 180), yStep * (float) sin(theta * M_PI / 180));
    }
    if (botDown) {
        bot.move(-xStep * (float) cos(theta * M_PI / 180), -yStep * (float) sin(theta * M_PI / 180));
    }
    if (botLeft) {
        bot.turn(-thetaStep);
    }
    if (botRight) {
        bot.turn(thetaStep);
    }
}

void Map::checkBotCollision(Wall* w) {

}