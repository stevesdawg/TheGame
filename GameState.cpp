//
// Created by Kshitij Kulkarni on 12/14/16.
//

#include "GameState.h"


GameState::GameState()
{
    window = new sf::RenderWindow(sf::VideoMode(1440, 1080), "TheGameModified");

}

void GameState::mainFunc(){

    if (s == TITLE) {
        titleScreen();
        sf::Event event;
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::A) {
                    s = STORY;

                }
            }
        }
    }

    else if (s == STORY){
        gameStory();
        sf::Event event;
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::A) {
                    s = GAME;

                }
            }
        }
    }

    else if (s == GAME){
         m->drawObjects();
        int whodied = m->whoDied();
        if (whodied == 1){
            myScore++;
            s = GAME_OVERME;
        }
        else if (whodied == 2){
            uScore++;
            s = GAME_OVERU;
        }
    }

    else if (s == GAME_OVERME){
        gameOverMe();
        sf::Event event;
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::A) {
                    s = TITLE;

                }
            }
        }
    }

    else if (s == GAME_OVERU){
        gameOverU();
        sf::Event event;
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::A) {
                    s = TITLE;

                }
            }
        }
    }



}
void GameState::titleScreen() {
    sf::Font font;
    sf::Text text;
    sf::Text text2;
    text.setString("DE2 Trouble");
    text2.setString("Press A to play");
    text.setColor(sf::Color::White);
    text2.setColor(sf::Color::White);
    sf::Color color = sf::Color::Black;
    font.loadFromFile("arial.ttf");
    text.setFont(font);
    text2.setFont(font);
    text.setCharacterSize(100);
    text2.setCharacterSize(100);
    window->clear(color);
    text.move(400,400);
    text2.move(500,700);
    window->draw(text);
    window->draw(text2);

    window->display();
}

void GameState::gameOverMe(){
    sf::Font font;
    sf::Text text;
    text.setColor(sf::Color::White);
    sf::Color color = sf::Color::White;
    font.loadFromFile("arial.ttf");
    text.setFont(font);
    window->clear(color);
    text.setString("Game Over. You lost :(");
    window->draw(text);
    window->display();
    sf::Text text2;
    text2.setColor(sf::Color::White);
    text2.setFont(font);
    std::string printme = std::to_string(myScore);
    std::string printu = std::to_string(uScore);
    text2.setString("My score is: " + printme + "Player 2's score is " + printu + ".");
}
void GameState::gameOverU(){
    sf::Font font;
    sf::Text text;
    text.setColor(sf::Color::White);
    sf::Color color = sf::Color::White;
    font.loadFromFile("arial.ttf");
    text.setFont(font);
    window->clear(color);
    text.setString("Game Over. You won!");
    window->draw(text);
    window->display();
    sf::Text text2;
    text2.setColor(sf::Color::White);
    text2.setFont(font);
    std::string printme = std::to_string(myScore);
    std::string printu = std::to_string(uScore);
    text2.setString("My score is: " + printme + "Player 2's score is " + printu + ".");
}


void GameState::gameStory(){
    window->clear(sf::Color::Black);
    sf::Font font;
    sf::Text text;
    sf::Text text2;
    sf::Text text3;
    text.setColor(sf::Color::White);
    text2.setColor(sf::Color::White);
    text3.setColor(sf::Color::White);
    sf::Color color = sf::Color::Black;
    font.loadFromFile("arial.ttf");
    text.setFont(font);
    text2.setFont(font);
    text3.setFont(font);
    window->clear(color);
    text.setString("It is the year 2016, and two DE2Bots are the only pieces of electronic equipment left in the arena.");
    text2.setString("After a brutal year in ECE 2031, the bots are ready to battle it out for the throne.");
    text3.setString("Get ready for the adventure of a lifetime! PRESS A TO CONTINUE...");
    text.move(50,400);
    text2.move(50,450);
    text3.move(50,500);
    window->draw(text);
    window->draw(text2);
    window->draw(text3);
    window->display();
}

