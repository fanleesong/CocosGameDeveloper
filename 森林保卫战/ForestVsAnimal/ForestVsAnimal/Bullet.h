//
//  Bullet.h
//  test
//
//  Created by user on 13-12-23.
//
//

#ifndef __test__Bullet__
#define __test__Bullet__

#include <iostream>
#include "cocos-ext.h"
#include "cocos2d.h"

USING_NS_CC;
USING_NS_CC_EXT;
class TowerTools;

class Bullet:public CCSprite {
    
    
public:
    
    float attack;
    bool isAttack;
    bool Moveed;
    
public:
    Bullet(TowerTools*_tools,CCPoint p,CCLayer *layer);
    void isMoved(Bullet*bullet);
    ~Bullet();
       
};
#endif /* defined(__test__Bullet__) */
