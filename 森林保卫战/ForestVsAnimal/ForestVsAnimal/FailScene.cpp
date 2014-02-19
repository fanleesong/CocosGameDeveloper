//
//  FailScene.cpp
//  ForestVsAnimal
//
//  Created by OldHorse on 13-12-27.
//
//

#include "FailScene.h"
#include "LevelScene.h"
#include "MainLayer.h"
using namespace cocos2d;
bool FailScene::init()
{
    if (!CCLayer::init()) {
        return false;
    }
    win = CCUserDefault::sharedUserDefault()->getBoolForKey("WIN");
    CCSprite* bg = CCSprite::create("bg8.png");
    bg->setPosition(ccp(240, 160));
    this->addChild(bg);
    
    CCMenuItemImage* menuImage = CCMenuItemImage::create("menu1.png", "menu1.png",this,menu_selector(FailScene::menu));
    menuImage->setScale(0.5);
    CCMenuItemImage* backImage = CCMenuItemImage::create("menu2.png", "menu2.png",this,menu_selector(FailScene::back));
    backImage->setScale(0.5);
    if (win == true) {
        nextImage = CCMenuItemImage::create("menu3.png", "menu3.png",this,menu_selector(FailScene::next));
        nextImage->setScale(0.5);
    }
    CCMenu* menu = CCMenu::create(menuImage,backImage,nextImage,NULL);
    menu->alignItemsHorizontallyWithPadding(12);
    menu->setPosition(ccp(240, 160));
    this->addChild(menu);
    
    return true;
}
CCScene* FailScene::scene()
{
    CCScene* scene = CCScene::create();
    FailScene* layer = FailScene::create();
    scene->addChild(layer);
    return scene;
}
void FailScene::menu()
{
    CCDirector::sharedDirector()->replaceScene(LevelScene::scene());
}
void FailScene::back()
{
    int newNum = CCUserDefault::sharedUserDefault()->getIntegerForKey("LevelNum");
    CCUserDefault::sharedUserDefault()->setIntegerForKey("LevelNum", newNum);
    CCDirector::sharedDirector()->replaceScene(MainLayer::scene());
}
void FailScene::next()
{
    int newNum = CCUserDefault::sharedUserDefault()->getIntegerForKey("LevelNum")+1;
    CCUserDefault::sharedUserDefault()->setIntegerForKey("LevelNum", newNum);
    CCDirector::sharedDirector()->replaceScene(MainLayer::scene());
}
void FailScene::onEnter()
{
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, -128, true);
    CCLayer::onEnter();
}
void FailScene::onExit()
{
    CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
    CCLayer::onExit();
}
bool FailScene::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
    return true;
}
void FailScene::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{

}
void FailScene::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{

}
void FailScene::ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent)
{

}