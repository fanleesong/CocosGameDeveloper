//
//  Level.cpp
//  ForestVsAnimal
//
//  Created by OldHorse on 13-12-17.
//
//

#include "Level.h"
Level::Level(int number,bool unlocked,int numberX,int numberY,int score)
{
    _number = number;
    _unlocked = unlocked;
    _numberX = numberX;
    _numberY = numberY;
    _score = score;
}
Level::~Level()
{

}