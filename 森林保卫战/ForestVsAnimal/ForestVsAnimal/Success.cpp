//
//  Success.cpp
//  ForestVsAnimal
//
//  Created by OldHorse on 13-12-27.
//
//

#include "Success.h"
bool Success::init()
{
    if (!CCLayer::init()) {
        return false;
    }
    CCParticleSystemQuad* mSystem = new CCParticleSystemQuad();
    mSystem->initWithFile("fengye.plist");
    mSystem->setTextureWithRect(CCTextureCache::sharedTextureCache()->addImage("fengye.png"), CCRectMake(0, 0, 91, 91));
    mSystem->setBlendAdditive(true);
    mSystem->setPosition(ccp(240, 160));
    addChild(mSystem);
    CCLabelTTF *winLB = CCLabelTTF::create("Game Win", "Zapfino", 28);
    winLB->setPosition(ccp(240,160));
    winLB->setColor(ccc3(255, 0, 0));
    this->addChild(winLB);
    
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                                         "CloseNormal.png",
                                                         "CloseSelected.png",
                                                         this,
                                                         menu_selector(Success::back) );
    pCloseItem->setPosition( ccp(CCDirector::sharedDirector()->getWinSize().width - 20, 20) );
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition( CCPointZero );
    this->addChild(pMenu, 2);
    return true;
}
CCScene* Success::scene()
{
    CCScene* scene = CCScene::create();
    Success* layer = Success::create();
    scene->addChild(layer);
    return scene;
}
void Success::back()
{
    CCDirector::sharedDirector()->end();
}