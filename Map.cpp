//
// Created by shrivathsav on 12/9/16.
//

#pragma once

#include <math.h>
#include "Map.h"

Map::Map() {
    window = new sf::RenderWindow(sf::VideoMode(1024, 768), "TheGame");
    bot.moveTo(300, 300);
}

void Map::drawObjects() {
    window->clear(sf::Color::Black);
    readKeyboardInputs();
    bot.draw(*window);
    window->display();
}

void Map::readKeyboardInputs() {
    sf::Event event;
    float xStep = 4;
    float yStep = 4;
    float thetaStep = 5;

    while (window->pollEvent(event)) {
        if (event.type == sf::Event::KeyPressed) {
            float theta = bot.getTheta();
            switch (event.key.code) {
                case sf::Keyboard::Up:
                    bot.move(xStep * (float) cos(theta * M_PI/ 180), yStep * (float) sin(theta * M_PI / 180));
                    break;
                case sf::Keyboard::Down:
                    bot.move(-xStep * (float) cos(theta * M_PI/ 180), -yStep * (float) sin(theta * M_PI / 180));
                    break;
                case sf::Keyboard::Left:
                    bot.turn(-thetaStep);
                    break;
                case sf::Keyboard::Right:
                    bot.turn(thetaStep);
                    break;
                default:
                    break;
            }
        } else if (event.type == sf::Event::Closed) {
            window->close();
        }
    }
}