//
//  Levels.cpp
//  ForestVsAnimal
//
//  Created by OldHorse on 13-12-17.
//
//

#include "Levels.h"
Levels::Levels()
{
    _levels = CCArray::create();
    _levels->retain();
}
Levels::~Levels()
{
    _levels->release();
}