//
// Created by shrivathsav on 12/9/16.
//

#pragma once

#include "Map.h"

Map::Map() {
    window = new sf::RenderWindow(sf::VideoMode(1024, 768), "TheGame");
    bot.moveTo(300, 300);
    Wall w(5, 5, 500, 3);
    walls.push_back(w);
}

void Map::drawObjects() {
    window->clear(sf::Color::Black);
    readKeyboardInputs();
    bot.draw(*window);
    for (Wall w : walls) {
        w.draw(*window);
    }
    if (bullets.size() > 0) {
        for (Bullet b : bullets) {
            float bulletXStep = 5;
            float bulletYStep = 5;
            b.move(bulletXStep * (float) cos(b.getTheta() * M_PI / 180),
                   bulletYStep * (float) sin(b.getTheta() * M_PI / 180));
            b.draw(*window);
        }
    }
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
            Bullet b(bot.getX(), bot.getY(), theta);
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
                case sf::Keyboard::M:
                    bullets.push_back(b);
                default:
                    break;
            }
        } else if (event.type == sf::Event::Closed) {
            window->close();
        }
    }
}