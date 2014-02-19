//
//  MainLayer.h
//  ForestVsAnimal
//
//  Created by OldHorse on 13-12-18.
//
//

#ifndef __ForestVsAnimal__MainLayer__
#define __ForestVsAnimal__MainLayer__

#include <iostream>
#include "cocos2d.h"
#include "FailScene.h"
using namespace cocos2d;
class Enery;
class Bullet;
class MainLayer:public CCLayer
{
public:
    virtual bool init();
    static CCScene* scene();
    CREATE_FUNC(MainLayer);
    CCTMXTiledMap* myTiledMap;
    CCTMXLayer* meta;
    CCTMXObjectGroup* signObjects;//判断是否标记的点
    Enery* hero;
    void move();
    CCPoint point;
    CCPoint endPoint;
    int levelNum;
    //触摸事件
    virtual void onEnter();
    virtual void onExit();
    virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent);
    CCLabelTTF* scoreLabel;
    CCLabelTTF* waveLabel;
    void menuBtn();
    int waveNum;
    void removeSpr();
    void scheduleMove();
    void addEnemy();
    void parser();
    float levelScore;//每关分数
    void selectEneryBlood();//检查敌人的血量
    void selectBullettype();//子弹是否用过
    void  buttleAttack();//子弹攻击
    void removeEnery(Enery* enery);//移除敌人
    void removeBullet(Bullet* bullet);//移除子弹
    //多批小怪
    CCArray* EneryArray;//敌人关数数组
    CCArray* oneWaveArray;//一波敌人
    CCArray* WaveArray;//一关敌人波数数组
    CCArray* towerArray;//炮塔数组
    CCArray* bulletArray;//炮塔子弹数组
    bool loadEnery();//加载敌人
    int wave;//第几波
    FailScene* failLayer;
    ~MainLayer();
};
#endif /* defined(__ForestVsAnimal__MainLayer__) */
