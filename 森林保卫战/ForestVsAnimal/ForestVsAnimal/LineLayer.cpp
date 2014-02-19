//
//  LineLayer.cpp
//  ForestVsAnimal
//
//  Created by OldHorse on 13-12-26.
//
//

#include "LineLayer.h"
using namespace cocos2d;
bool LineLayer::init()
{
    if (!CCLayer::init()) {
        return false;
    }
    return true;
}
void LineLayer::addPoint(CCPoint p)
{
    CCSprite* sprite = CCSprite::create("point.png");
    sprite->setPosition(p);
    this->addChild(sprite);
}