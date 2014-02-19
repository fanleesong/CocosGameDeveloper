//
//  Enery.h
//  test
//
//  Created by user on 13-12-18.
//
//

#ifndef __test__Enery__
#define __test__Enery__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"
USING_NS_CC;
USING_NS_CC_EXT;

enum EneryType {
    mouse= 0,//蓝鼠
    monster,//怪兽
    littleMonster,//小怪兽
    bear,//棕熊
    cock,//公鸡
    dyrad,//树怪
    scorpion,//蝎子
};

class Enery:public CCSprite {
public:
    EneryType eneryType;//敌人类型
    float blood;//血量
    CCControlSlider* slider;
    float speed;//速度
    char Direction[20];//方向
    int tag;
    bool canAction;
    float forthX;//上一步Y
    float forthY;//上一步X
    float Catchgold;//金钱数
    char name[50];
    
    float Physical_Resistance;//物理抗性
    float Spell_Resistance;//魔法抗性
    Enery(EneryType eneryType);//构造函数
    EneryType EneryCreatWithtag(int enerytag);
    void loadSpriteFrameFiles();  //预先加载纹理图集
    void startEnerymove();
    void forthAction();//向前走
    void  leftAction();//向左走
    void  rightAction();//向右走
    void  downAction();//向下走
    void  deathAction();//死亡动作
    void  deleteEnery(Enery* oneEnery);
    //void draw();
};

#endif /* defined(__test__Enery__) */
