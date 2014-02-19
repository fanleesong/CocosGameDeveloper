//
//  Level.h
//  ForestVsAnimal
//
//  Created by OldHorse on 13-12-17.
//
//

#ifndef __ForestVsAnimal__Level__
#define __ForestVsAnimal__Level__

#include <iostream>
#include "cocos2d.h"
using namespace cocos2d;
class Level:public CCObject
{
public:
    int _number;
    bool _unlocked;
    int _numberX;
    int _numberY;
    int _score;
public:
    Level(int number,bool unlocked,int numberX,int numberY,int score);
    ~Level();
};
#endif /* defined(__ForestVsAnimal__Level__) */
