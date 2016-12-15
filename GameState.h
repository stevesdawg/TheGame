//
// Created by Kshitij Kulkarni on 12/14/16.
//

#include "Map.h"
#include "SFML/Graphics.hpp"
class GameState{
public:
    GameState();
    void mainFunc();
    void titleScreen();

    void gameOverMe();
    void gameOverU();
    void gameStory();
    int myScore = 0;
    int uScore = 0;


private:
    sf::RenderWindow* window;
    Map *m ;
    enum STATE{
        TITLE, STORY, GAME, GAME_OVERME, GAME_OVERU
    };
    STATE s = TITLE;
};