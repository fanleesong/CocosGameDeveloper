//
//  TowerTools.h
//  test
//
//  Created by user on 13-12-19.
//
//

#ifndef __test__TowerTools__
#define __test__TowerTools__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"
USING_NS_CC;
USING_NS_CC_EXT;

enum TowerType {
    //炮塔
    TurretTower = 0,
    //箭塔
    LarrowTower,
    //减速塔
    DecelerationTower,
    //魔法塔
    MagicTower,
    
    };

enum AttackType {
    Shell = 0,//炮弹攻击
    Sword,//用剑攻击
    Deceleration,//减速
    Magic//魔法攻击
    };


class TowerTools:public CCSprite {
    
public:
    TowerType towerType;//塔的类型
    AttackType attackType;//攻击类型
    CCPoint mypostion;
    int towerLevel;//塔的等级
    char towerName[30];//塔的名字
    float Attack;//攻击力
    float AttackRange;//攻击范围
    float Frequency;//攻击频率
    float tempFre;
    
    
    float NeedGold;//所需金币
    CCMenuItemImage* updataItem;
    bool isAttack;
    float updataLevelGold;//升级所需的金币数
    TowerTools(TowerType towerType);//构造函数
    void updataLevel(TowerTools* oneTower);//塔升级
    TowerType TowerCreatWithtag(char* type);
    
    };

#endif /* defined(__test__TowerTools__) */
