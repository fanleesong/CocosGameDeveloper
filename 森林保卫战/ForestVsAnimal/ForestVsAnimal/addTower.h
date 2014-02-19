//
//  addTower.h
//  test
//
//  Created by user on 13-12-20.
//
//

#ifndef __test__addTower__
#define __test__addTower__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"
USING_NS_CC;
USING_NS_CC_EXT;

class addTower:public CCLayer {
    
    
public:
    
    static CCScene* scene();
    virtual bool init();
    CCArray* towerBtnArray;
    void towerAdd(CCObject* sender);
    void addtowerBtn(CCObject* sender);
    void removeBtn(CCObject*sender);
    CCMenu* menu;
    CREATE_FUNC(addTower);
};

#endif /* defined(__test__addTower__) */
