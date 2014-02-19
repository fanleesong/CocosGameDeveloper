//
//  Enery.cpp
//  test
//
//  Created by user on 13-12-18.
//
//

#include "Enery.h"
using namespace std;

//构造函数
Enery:: Enery(EneryType eneryType)
{
    this->loadSpriteFrameFiles();
    switch (eneryType) {
        case 0:
            this->eneryType = eneryType;
            tag = 0;
            canAction = false;
            speed = 40;
            blood = 100;
            Physical_Resistance =55;
            Spell_Resistance = 74;
            Catchgold = 30;
            sprintf(name, "mouse");
            this->initWithSpriteFrameName("mouse1.png");
            break;
        case 1:
            this->eneryType = eneryType;
            tag = 0;
            canAction = false;
            speed =30;
            blood = 150;
            Physical_Resistance =55;
            Spell_Resistance = 74;
            Catchgold = 50;
            this->initWithSpriteFrameName("monster1.png");
            sprintf(name, "monster");
            break;
        case 2:
            this->eneryType = eneryType;
            tag = 0;
            canAction = false;
            speed = 40;
            blood = 130;
            Physical_Resistance =55;
            Spell_Resistance = 74;
            Catchgold = 40;
            this->initWithSpriteFrameName("littleMonster1.png");
            sprintf(name, "littleMonster");
            break;
        case 3:
            this->eneryType = eneryType;
            tag = 0;
            canAction = false;
            speed = 38;
            blood = 110;
            Physical_Resistance =55;
            Spell_Resistance = 74;
            Catchgold = 30;
            this->initWithSpriteFrameName("bear1.png");
            sprintf(name, "bear");
            break;
        case 4:
            this->eneryType = eneryType;
            tag = 0;
            canAction = false;
            speed = 40;
            blood = 80;
            Physical_Resistance =55;
            Spell_Resistance = 74;
            Catchgold = 25;
            this->initWithSpriteFrameName("cock1.png");
            sprintf(name, "cock");
            break;
        case 5:
            this->eneryType = eneryType;
            tag = 0;
            canAction = false;
            speed = 25;
            blood = 200;
            Physical_Resistance =55;
            Spell_Resistance = 74;
            Catchgold = 60;
            this->initWithSpriteFrameName("dryad1.png");
            sprintf(name, "dryad");
            break;
        case 6:
            this->eneryType = eneryType;
            tag = 0;
            canAction = false;
            speed = 47;
            blood = 80;
            Physical_Resistance =55;
            Spell_Resistance = 74;
            Catchgold = 25;
            this->initWithSpriteFrameName("scorpion1.png");
            sprintf(name, "scorpion");
            break;
            default:
            break;
    }
    
    slider = CCControlSlider::create("xuetiao1.png", "xuetiao2.png", "xuetiao3.png");
    slider->setMinimumValue(0);
    slider->setMaximumValue(blood);
    slider->setValue(blood);
    slider->setTouchEnabled(false);
    slider->setAnchorPoint(ccp(0, -7));
    this->addChild(slider);
}

 EneryType Enery:: EneryCreatWithtag(int enerytag)
{
    if (enerytag==1)
    {
        return cock;
    }else if (enerytag ==2)
        
    {
        return scorpion ;
    }else if (enerytag==3)
        
    {
        return mouse;
    }else if (enerytag==4)
    {
        return bear;
    }else if (enerytag==5)
    {
        return littleMonster;
    }else if (enerytag==6)
    {
        return monster;
    }else
    {
        return dyrad;
    }
}

//预先加载纹理图集

void Enery:: loadSpriteFrameFiles()
{
    CCSpriteFrameCache* cache = CCSpriteFrameCache::sharedSpriteFrameCache();
    cache->addSpriteFramesWithFile("bear_default.plist");
    cache->addSpriteFramesWithFile("boss_default.plist");
    cache->addSpriteFramesWithFile("cock_default.plist");
    cache->addSpriteFramesWithFile("dryad_default.plist");
    cache->addSpriteFramesWithFile("littleMonster_default.plist");
    cache->addSpriteFramesWithFile("monster_default.plist");
    cache->addSpriteFramesWithFile("mouse_default.plist");
    cache->addSpriteFramesWithFile("scorpion_default.plist");
    cache->addSpriteFramesWithFile("end_default.plist");
}

//向前走
void Enery:: forthAction()
{
    this->stopAllActions();
    CCArray* actionPlist = new CCArray();
    actionPlist->retain();
    for (int i = 7; i<=8; i++) {
        char frameName[50];
        sprintf(frameName, "%s%d.png",this->name,i);
        CCSpriteFrame* oneFrame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(frameName);
        actionPlist->addObject(oneFrame);
        
    }
    CCAnimation* animation = CCAnimation::createWithSpriteFrames(actionPlist,0.2f);
    CCAnimate* animate = CCAnimate::create(animation);
    CCRepeatForever* forever = CCRepeatForever::create(animate);
    this->runAction(forever);
    CCMoveTo* rightMove = CCMoveTo::create(32/this->speed, CCPoint(this->getPositionX(),this->getPositionY()+32));
    this->runAction(rightMove);
    actionPlist->release();

    
    
    
}

//向左走
void Enery:: leftAction()
{
    
    this->stopAllActions();
    CCArray* actionPlist = new CCArray();
    actionPlist->retain();
    for (int i = 3; i<=4; i++) {
        char frameName[50];
        sprintf(frameName, "%s%d.png",this->name,i);
        CCSpriteFrame* oneFrame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(frameName);
        actionPlist->addObject(oneFrame);
        
    }
    CCAnimation* animation = CCAnimation::createWithSpriteFrames(actionPlist,0.2f);
    CCAnimate* animate = CCAnimate::create(animation);
    CCRepeatForever* forever = CCRepeatForever::create(animate);
    this->runAction(forever);
    CCMoveTo* leftMove = CCMoveTo::create(32/this->speed, CCPoint(this->getPositionX()-32,this->getPositionY()));
    this->runAction(leftMove);
    actionPlist->release();
    
}

//向右走
void Enery:: rightAction()
{
    this->stopAllActions();
    CCArray* actionPlist = new CCArray();
    actionPlist->retain();
    for (int i = 5; i<=6; i++) {
        char frameName[50];
        sprintf(frameName, "%s%d.png",this->name,i);
        CCSpriteFrame* oneFrame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(frameName);
        actionPlist->addObject(oneFrame);
        
    }
    CCAnimation* animation = CCAnimation::createWithSpriteFrames(actionPlist,0.2f);
    CCAnimate* animate = CCAnimate::create(animation);
    CCRepeatForever* forever = CCRepeatForever::create(animate);
    this->runAction(forever);
    CCMoveTo* rightMove = CCMoveTo::create(32/this->speed, CCPoint(this->getPositionX()+32,this->getPositionY()));
   this->runAction(rightMove);
    actionPlist->release();
}
//向下走
void Enery:: downAction()
{
    this->stopAllActions();
    CCArray* actionPlist = new CCArray();
    actionPlist->retain();
    for (int i = 1; i<=2; i++) {
        char frameName[50];
        sprintf(frameName, "%s%d.png",this->name,i);
        CCSpriteFrame* oneFrame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(frameName);
        actionPlist->addObject(oneFrame);
        
    }
    CCAnimation* animation = CCAnimation::createWithSpriteFrames(actionPlist,0.2f);
    CCAnimate* animate = CCAnimate::create(animation);
    CCRepeatForever* forever = CCRepeatForever::create(animate);
    this->runAction(forever);
    CCMoveTo* forthMove = CCMoveTo::create(32/this->speed, CCPoint(this->getPositionX(),this->getPositionY()-32));
    this->runAction(forthMove);
    actionPlist->release();
   }

//死亡动作
void Enery:: deathAction()
{
    this->stopAllActions();
    CCArray* actionPlist = new CCArray();
    actionPlist->retain();
    for (int i = 1; i<=2; i++) {
        char frameName[50];
        sprintf(frameName, "end%d.png",i);
        CCSpriteFrame* oneFrame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(frameName);
        actionPlist->addObject(oneFrame);
        
    }
    CCAnimation* animation = CCAnimation::createWithSpriteFrames(actionPlist,0.2f);
    CCAnimate* animate = CCAnimate::create(animation);
    this->runAction(animate);
    actionPlist->release();
}
void Enery:: startEnerymove()
{
    this->canAction = true;
}


void Enery:: deleteEnery(Enery* oneEnery)
{
    this->removeFromParent();
    
}

