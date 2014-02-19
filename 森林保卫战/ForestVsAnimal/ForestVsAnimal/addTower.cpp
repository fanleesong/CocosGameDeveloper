//
//  addTower.cpp
//  test
//
//  Created by user on 13-12-20.
//
//

#include "addTower.h"
#include "TowerTools.h"
CCScene* addTower:: scene()
{
    CCScene* scene = CCScene::create();
    addTower* layer = addTower::create();
    scene->addChild(layer);
    return scene;
}


bool addTower:: init()
{
    if (!CCLayer::init()) {
        return false;
    }
    
    towerBtnArray = new CCArray();
    towerBtnArray->retain();
    CCMenuItemImage* tower = CCMenuItemImage::create("tower1.png", "tower1f.png",this,menu_selector(addTower::towerAdd));
    tower->setTag(1);
    towerBtnArray->addObject(tower);
    
    CCMenuItemImage* tower1 = CCMenuItemImage::create("tower2.png", "tower2f.png",this,menu_selector(addTower::towerAdd));
    tower1->setTag(2);
    towerBtnArray->addObject(tower1);
    
    CCMenuItemImage* tower2 = CCMenuItemImage::create("tower3.png", "tower3f.png",this,menu_selector(addTower::towerAdd));
    tower2->setTag(3);
    towerBtnArray->addObject(tower2);
    
    CCMenuItemImage* tower3 = CCMenuItemImage::create("tower4.png", "tower4f.png",this,menu_selector(addTower::towerAdd));
    tower3->setTag(4);
    towerBtnArray->addObject(tower3);
    
    CCMenuItemImage* tower4 = CCMenuItemImage::create("btn.png", "btn.png",this,menu_selector(addTower::removeBtn));
    tower4->setTag(6);
    towerBtnArray->addObject(tower4);
    if (!menu) {
        menu= CCMenu::createWithArray(towerBtnArray);
    }else
    {
        menu->removeFromParent();
         menu= CCMenu::createWithArray(towerBtnArray);
    }
    menu->setPosition(ccp(100, 20));
    menu->alignItemsHorizontallyWithPadding(10);
    this->addChild(menu,1);
    towerBtnArray->release();
    return true;
}

void addTower:: towerAdd(CCObject* sender)
{
    int towerTag = CCUserDefault::sharedUserDefault()-> getIntegerForKey("towerTag");
    if (towerTag ==0) {
        towerTag = 1000;
    }else
    {
        towerTag ++;
    }
    CCUserDefault::sharedUserDefault()->setIntegerForKey("towerTag", towerTag);
    CCMenuItemImage* item = (CCMenuItemImage*)sender;
    if (item->getTag() ==1) {
        CCUserDefault::sharedUserDefault()->setStringForKey("towerType", "TurretTower");
       
    }else if (item->getTag()==2)
    {
        CCUserDefault::sharedUserDefault()->setStringForKey("towerType", "LarrowTower");
    }else if (item->getTag() ==3)
    {
        CCUserDefault::sharedUserDefault()->setStringForKey("towerType", "DecelerationTower");
        
    }else if (item->getTag()==4)
    {
        CCUserDefault::sharedUserDefault()->setStringForKey("towerType", "MagicTower");
        
    }
    else{
        
    }
}



 void addTower:: removeBtn(CCObject*sender)
{
    this->removeFromParent();
  }