//
//  LineLayer.h
//  ForestVsAnimal
//
//  Created by OldHorse on 13-12-26.
//
//

#ifndef __ForestVsAnimal__LineLayer__
#define __ForestVsAnimal__LineLayer__

#include <iostream>
#include "cocos2d.h"
using namespace cocos2d;
class LineLayer:public CCLayer
{
public:
    virtual bool init();
    CREATE_FUNC(LineLayer);
public:
    void addPoint(CCPoint p);
};
#endif /* defined(__ForestVsAnimal__LineLayer__) */
