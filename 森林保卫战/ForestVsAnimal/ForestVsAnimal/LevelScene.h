//
//  LevelScene.h
//  ForestVsAnimal
//
//  Created by OldHorse on 13-12-17.
//
//

#ifndef __ForestVsAnimal__LevelScene__
#define __ForestVsAnimal__LevelScene__

#include <iostream>
#include "cocos2d.h"
class LineLayer;
using namespace cocos2d;
class LevelScene:public CCLayer
{
public:
    virtual bool init();
    static CCScene* scene();
    CREATE_FUNC(LevelScene);
    CCSprite* flag;
    void addLevelMenu();
    void playGame(CCMenuItemImage* image);
    void checkLine();
    LineLayer* lineLayer;
    
};

#endif /* defined(__ForestVsAnimal__LevelScene__) */
