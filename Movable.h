//
// Created by shrivathsav on 12/8/16.
//

#pragma once

#include "Drawable.h"

class Movable : Drawable {
    virtual void move(sf::RenderWindow&) =0;
};