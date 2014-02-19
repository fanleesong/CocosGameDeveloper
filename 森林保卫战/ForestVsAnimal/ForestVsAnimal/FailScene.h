//
//  FailScene.h
//  ForestVsAnimal
//
//  Created by OldHorse on 13-12-27.
//
//

#ifndef __ForestVsAnimal__FailScene__
#define __ForestVsAnimal__FailScene__

#include <iostream>
#include "cocos2d.h"
using namespace cocos2d;

class FailScene:public CCLayer
{
public:
    virtual bool init();
    static CCScene* scene();
    CREATE_FUNC(FailScene);
    void menu();
    void back();
    void next();
    bool win;
    CCMenuItemImage* nextImage;
    //touch
    virtual void onEnter();
    virtual void onExit();
    virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent);
};
#endif /* defined(__ForestVsAnimal__FailScene__) */
