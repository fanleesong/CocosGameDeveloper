//
//  StartScene.cpp
//  ForestVsAnimal
//
//  Created by OldHorse on 13-12-16.
//
//

#include "StartScene.h"
#include "HelpScene.h"
#include "LevelScene.h"
CCScene*  StartScene::scene()
{
    CCScene* scene = CCScene::create();
    StartScene* layer = StartScene::create();
    scene->addChild(layer);
    return scene;
}

bool StartScene::init()
{
    if (!CCLayer::init()) {
        return false;
    }
    CCSize winsize = CCDirector::sharedDirector()->getWinSize();
    CCSprite* bgsprite = CCSprite::create("bg54.jpg");
    bgsprite->setScale(0.6);
    bgsprite->setPosition(ccp(winsize.width/2, winsize.height/2));
    this->addChild(bgsprite);
    
    CCSprite* bgtitle = CCSprite::create("bgtitle.png");
    bgtitle->setScale(0.35);
    bgtitle->setPosition(ccp(winsize.width/2, winsize.height/2+100));
    this->addChild(bgtitle);
    
    CCSprite* bg = CCSprite::create("gamebg.png");
    bg->setScale(0.6);
    bg->setPosition(ccp(winsize.width/2, winsize.height/2-25));
    this->addChild(bg);
    
    //选择按钮
    CCMenuItemImage* startItem = CCMenuItemImage::create("start.png", "start.png",this,menu_selector(StartScene::startBtn));
    startItem->setScale(0.6);
    startItem->setPosition(ccp(winsize.width/2, winsize.height/2-25));
    
    CCMenuItemImage* helpItem = CCMenuItemImage::create("help.png", "help.png");
    helpItem->setTarget(this, menu_selector(StartScene::helpBtn));
    helpItem->setScale(0.6);
    helpItem->setPosition(ccp(winsize.width/2, winsize.height/2-75));
    
    //音效按钮
    CCMenuItemImage* start = CCMenuItemImage::create("music2.png", "music2.png");
    CCMenuItemImage* start1 = CCMenuItemImage::create("music1.png", "music1.png");
    CCMenuItemToggle* tog1 = CCMenuItemToggle::createWithTarget(this, menu_selector(StartScene::musicBtn),start,start1,NULL);
    tog1->setPosition(ccp(winsize.width/2+100, winsize.height/2-25));
    
    CCMenuItemImage* yinxiao = CCMenuItemImage::create("music3.png", "music3.png");
    CCMenuItemImage* yinxiao1 = CCMenuItemImage::create("music4.png", "music4.png");
    CCMenuItemToggle* tog2 = CCMenuItemToggle::createWithTarget(this, menu_selector(StartScene::yinxiaoBtn),yinxiao,yinxiao1,NULL);
    tog2->setPosition(ccp(winsize.width/2+100, winsize.height/2-55));
    
    CCMenu* menu = CCMenu::create(startItem,helpItem,tog1,tog2, NULL);
    menu->setPosition(CCPointZero);
    
    this->addChild(menu,1);
    return true;
}
void StartScene::startBtn()
{
    CCDirector::sharedDirector()->replaceScene(CCTransitionFadeUp::create(1.5, LevelScene::scene()));
}
void StartScene::helpBtn()
{
    HelpScene* helpLayer = HelpScene::create();
    helpLayer->setAnchorPoint(ccp(0,1));
    helpLayer->setScale(0.8);
    helpLayer->setPosition(ccp(-150, -30));
    this->addChild(helpLayer,2);
}
void StartScene::musicBtn()
{

}
void StartScene::yinxiaoBtn()
{

}
