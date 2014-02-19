//
//  LevelScene.cpp
//  ForestVsAnimal
//
//  Created by OldHorse on 13-12-17.
//
//

#include "LevelScene.h"
#include "Level.h"
#include "Levels.h"
#include "LevelParser.h"
#include "MainLayer.h"
#include "LineLayer.h"
#include "cocos-ext.h"
USING_NS_CC;
USING_NS_CC_EXT;

CCScene* LevelScene::scene()
{
    CCScene* scene = CCScene::create();
    LevelScene* layer = LevelScene::create();
    scene->addChild(layer);
    
    return scene;
}
bool LevelScene::init()
{
    if (!CCLayer::init()) {
        return false;
    }
    
    lineLayer = LineLayer::create();
    this->addChild(lineLayer,1);
    CCSize winsize = CCDirector::sharedDirector()->getWinSize();
    CCSprite* bgf = CCSprite::create("bgf.png");
    bgf->setScale(0.6);
    bgf->setPosition(ccp(winsize.width/2, winsize.height/2));
    this->addChild(bgf);
    flag = CCSprite::create("98019.png");
    flag->setScale(0.5);
    addLevelMenu();
    return true;
}
void LevelScene::addLevelMenu()
{
    Level* level1;
    CCArray* array = CCArray::create();
    Levels* levels = LevelParser::loadData();
    for (int i = 0; i<(levels->_levels)->count(); i++) {
        Level* level = (Level*)((levels->_levels)->objectAtIndex(i));
        if (i >0) {
            level1 = (Level*)((levels->_levels)->objectAtIndex(i-1));
        }
        if (level->_unlocked) {
            CCMenuItemImage * levelSprite =CCMenuItemImage::create("level.png", "level.png",this,menu_selector(LevelScene::playGame));
            levelSprite->setTag(level->_number);
            levelSprite->setScale(0.55);
            levelSprite->setPosition(ccp(level->_numberX, level->_numberY));
            array->addObject(levelSprite);
            flag->setPosition(ccp((level->_numberX),( level->_numberY)+10));
            if (level->_number == 1) {
                
            }
            else
            {
                CCUserDefault::sharedUserDefault()->setIntegerForKey("newX", level->_numberX);
                CCUserDefault::sharedUserDefault()->setIntegerForKey("newY", level->_numberY);
                CCUserDefault::sharedUserDefault()->setIntegerForKey("oldX", level1->_numberX);
                CCUserDefault::sharedUserDefault()->setIntegerForKey("oldY", level1->_numberY);
            }
        }
        else
        {
            CCMenuItemImage * lockSprite = CCMenuItemImage::create("lock.png","lock.png",this,menu_selector(LevelScene::playGame));
            lockSprite->setTag(level->_number);
            lockSprite->setEnabled(false);
            lockSprite->setScale(0.55);
            lockSprite->setPosition(ccp(level->_numberX, level->_numberY));
            array->addObject(lockSprite);
        }
        char temp[20];
        sprintf(temp,"%i",level->_number);
        CCLabelTTF* label = CCLabelTTF::create(temp, "", 12);
        label->setPosition(ccp(level->_numberX, level->_numberY));
        this->addChild(label, 1);
        
    }
    CCMenu* menu = CCMenu::createWithArray(array);
    menu->setPosition(CCPointZero);
    this->addChild(menu);
    this->addChild(flag);
    
    checkLine();
}
void LevelScene::playGame(CCMenuItemImage* image)
{
    int tag = image->getTag();
    CCUserDefault::sharedUserDefault()->setIntegerForKey("LevelNum", tag);
    CCDirector::sharedDirector()->replaceScene(CCTransitionMoveInL::create(1.0, MainLayer::scene()));
}
void LevelScene::checkLine()
{
    int num = CCUserDefault::sharedUserDefault()->getIntegerForKey("LevelNum");
    if (num == 1) {
        
    }
    else
    {
        float oldX = CCUserDefault::sharedUserDefault()->getIntegerForKey("oldX");
        float oldY = CCUserDefault::sharedUserDefault()->getIntegerForKey("oldY");
        float newX = CCUserDefault::sharedUserDefault()->getIntegerForKey("newX");
        float newY = CCUserDefault::sharedUserDefault()->getIntegerForKey("newY");
        float x = newX-oldX;
        float y = newY-oldY;
        int m = x/3;
        
        float angle = atan2(y, x);
        lineLayer->addPoint(ccp(m+oldX,oldY+m*angle));
        lineLayer->addPoint(ccp(m*2+oldX,oldY + m*2*angle));
        
    }
}
