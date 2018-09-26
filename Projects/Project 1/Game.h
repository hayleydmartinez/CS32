//
//  Game.h
//  Proj1
//
//  Created by Hayley Martinez on 4/4/18.
//  Copyright © 2018 Hayley Martinez. All rights reserved.
//

#ifndef Game_h
#define Game_h

#include "City.h"

class Game
{
public:
    // Constructor/destructor
    Game(int rows, int cols, int nFlatulans);
    ~Game();
    
    // Mutators
    void play();
    int  decodeDirection(char dir);
    
private:
    City* m_city;
};

#endif /* Game_h */
