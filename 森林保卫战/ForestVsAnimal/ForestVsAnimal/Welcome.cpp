//
//  Welcome.cpp
//  ForestVsAnimal
//
//  Created by OldHorse on 13-12-13.
//
//

#include "Welcome.h"
#include "StartScene.h"
static int num;
bool Welcome::init()
{
    if (!CCLayer::init()) {
        return false;
    }
    CCSize winsize = CCDirector::sharedDirector()->getWinSize();
    CCSprite* sprite = CCSprite::create("bg35.jpg");
    sprite->setScale(0.5);
    sprite->setPosition(ccp(winsize.width/2, winsize.height/2));
    this->addChild(sprite);
    CCSprite* title = CCSprite::create("wood2.png");
    title->setScale(0.4);
    title->setPosition(ccp(winsize.width/2-190, winsize.height/2-30));
    this->addChild(title);
    
    //添加进度条
    slider = CCControlSlider::create("xuetiao1 2.png", "xuetiao2 2.png", "xuetiao3 2.png");
    slider->setAnchorPoint(ccp(0.5, 0.5));
    
    slider->setMinimumValue(0);
    slider->setMaximumValue(100);
    slider->setValue(0);
    slider->setPosition(ccp(280, 25));
    this->addChild(slider);
    
    this->schedule(schedule_selector(Welcome::checkit), 0.1);
    num = 0;
    
    //label
    char temp[100];
    sprintf(temp, "loading...%i",num);
    label = CCLabelTTF::create(temp, "", 16);
    label->setColor(ccc3(225, 0, 0));
    label->setPosition(ccp(300, 50));
    this->addChild(label);
    return true;
}
CCScene* Welcome::scene()
{
    CCScene* scene = CCScene::create();
    Welcome* layer = Welcome::create();
    scene->addChild(layer);
    return scene;
}
void Welcome::checkit()
{
    num++;
    if (num<=100) {
        slider->setValue(num);
        char temp1[20];
        sprintf(temp1, "loading...%i",num);
        label->setString(temp1);
    }
    
    if (num == 101) {
        label->setString("加载完成");
        this->unschedule(schedule_selector(Welcome::checkit));
        CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.0, StartScene::scene()));
    }
}

