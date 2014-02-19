//
//  Success.h
//  ForestVsAnimal
//
//  Created by OldHorse on 13-12-27.
//
//

#ifndef __ForestVsAnimal__Success__
#define __ForestVsAnimal__Success__

#include <iostream>
#include "cocos2d.h"
using namespace cocos2d;
class Success:public CCLayer
{
public:
    virtual bool init();
    static CCScene* scene();
    CREATE_FUNC(Success);
void back();
};
#endif /* defined(__ForestVsAnimal__Success__) */
