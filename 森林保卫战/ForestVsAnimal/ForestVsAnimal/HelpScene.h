//
//  HelpScene.h
//  ForestVsAnimal
//
//  Created by OldHorse on 13-12-16.
//
//

#ifndef __ForestVsAnimal__HelpScene__
#define __ForestVsAnimal__HelpScene__

#include <iostream>
#include "cocos2d.h"
using namespace cocos2d;
class HelpScene:public CCLayer
{
public:
    virtual bool init();
    static CCScene* scene();
    CREATE_FUNC(HelpScene);
    void callback();
virtual void onEnter();
virtual void onExit();
virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
virtual void ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent);
};
#endif /* defined(__ForestVsAnimal__HelpScene__) */
