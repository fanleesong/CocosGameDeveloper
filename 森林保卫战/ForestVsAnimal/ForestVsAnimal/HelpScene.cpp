//
//  HelpScene.cpp
//  ForestVsAnimal
//
//  Created by OldHorse on 13-12-16.
//
//

#include "HelpScene.h"
bool HelpScene::init()
{
    if (!CCLayer::init()) {
        return false;
    }
    CCSize winsize = CCDirector::sharedDirector()->getWinSize();
    CCSprite* bg = CCSprite::create("c4.png");
    bg->setOpacity(90);
    bg->setPosition(ccp(winsize.width/2, winsize.height/2));
    this->addChild(bg);
    
    //label
    CCLabelTTF* label1 = CCLabelTTF::create("游戏目标:", "", 20);
    label1->setColor(ccc3(225, 0, 0));
    label1->setPosition(ccp(winsize.width/2, winsize.height-30));
    this->addChild(label1);
    CCLabelTTF* fontLabel1 = CCLabelTTF::create("阻挡敌人到达森林的终点", "", 16);
    fontLabel1->setPosition(ccp(winsize.width/2+50, winsize.height-65));
    this->addChild(fontLabel1);
    
    CCLabelTTF* label2 = CCLabelTTF::create("如何开始:", "", 20);
    label2->setColor(ccc3(225, 0, 0));
    label2->setPosition(ccp(winsize.width/2, winsize.height-100));
    this->addChild(label2);
    CCLabelTTF* fontLabel2 = CCLabelTTF::create("游戏载入后，点击“开始游戏”进入,\n选择关卡", "", 16);
    fontLabel2->setPosition(ccp(winsize.width/2+80, winsize.height-135));
    this->addChild(fontLabel2);
    
    CCLabelTTF* label3 = CCLabelTTF::create("操作指南:", "", 20);
    label3->setColor(ccc3(225, 0, 0));
    label3->setPosition(ccp(winsize.width/2, winsize.height-175));
    this->addChild(label3);
    CCLabelTTF* fontLabel3 = CCLabelTTF::create("鼠标点击防御塔，并把他们放在相应的\n位置,防御塔就会对怪兽进行攻击.技巧：\n积累一定金币，防御塔升级按钮被点亮\n,升级后,防御塔的攻击力就会得到提升", "", 16);
    fontLabel3->setPosition(ccp(winsize.width/2+90, winsize.height-230));
    this->addChild(fontLabel3);
    
    CCMenuItemImage* item = CCMenuItemImage::create("1e.png", "1e.png");
    item->setScale(0.8);
    item->setTarget(this, menu_selector(HelpScene::callback));
    item->setPosition(ccp(winsize.width/2+180, winsize.height/2-170));
    CCMenu* menu = CCMenu::create(item,NULL);
    menu->setPosition(CCPointZero);
    
    this->addChild(menu,1);
    
    return true;
}
CCScene* HelpScene::scene()
{
    CCScene* scene = CCScene::create();
    HelpScene* layer = HelpScene::create();
    scene->addChild(layer);
    return scene;
}
void HelpScene::callback()
{
    this->removeFromParent();
}
void HelpScene::onEnter()
{
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, -128, true);
    CCLayer::onEnter();
}
void HelpScene::onExit()
{
    CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
    CCLayer::onExit();
}
bool HelpScene::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
    return true;
}
void HelpScene::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{

}
void HelpScene::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{

}
void HelpScene::ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent)
{

}