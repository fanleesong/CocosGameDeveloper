//
//  MainLayer.cpp
//  ForestVsAnimal
//
//  Created by OldHorse on 13-12-18.
//
//

#include "MainLayer.h"
#include "SimpleAudioEngine.h"
#include "addTower.h"
#include "TowerTools.h"
#include "Enery.h"
#include "Bullet.h"
#include "tinyxml.h"
#include "tinystr.h"
#include "Level.h"
#include "Levels.h"
#include "LevelParser.h"
using namespace std;
using namespace cocos2d;
using namespace CocosDenshion;

CCScene* MainLayer::scene()
{
    CCScene* scene = CCScene::create();
    MainLayer* layer = MainLayer::create();
    scene->addChild(layer);
    return scene;
}
bool MainLayer::init()
{
    if (!CCLayer::init()) {
        return false;
    }
    
    wave = 0;
    levelScore= 0;
    EneryArray = CCArray::createWithContentsOfFile("enemyPlist .plist");
    CC_SAFE_RETAIN(EneryArray);
    WaveArray = CCArray::create();
    CC_SAFE_RETAIN(WaveArray);
    oneWaveArray = CCArray::create();
    CC_SAFE_RETAIN(oneWaveArray);
    towerArray = CCArray::create();
    CC_SAFE_RETAIN(towerArray);
    bulletArray= CCArray::create();
    CC_SAFE_RETAIN(bulletArray);
    
    
    levelNum = CCUserDefault::sharedUserDefault()->getIntegerForKey("LevelNum");
    towerArray = CCArray::create();
    towerArray->retain();
    
    char maptemp[20];
    sprintf(maptemp, "map%i.tmx",levelNum);
    myTiledMap = CCTMXTiledMap::create(maptemp);
    
    this->addChild(myTiledMap);
    meta = myTiledMap->layerNamed("Meta");
    meta ->setVisible(false);
    
    signObjects = myTiledMap->objectGroupNamed("Sign");

    CCTMXObjectGroup* objects = myTiledMap->objectGroupNamed("Enemy");
    CCDictionary* heroPoint = objects->objectNamed("enemy1");
    CCDictionary* end = objects->objectNamed("enemy2");
    point.x = heroPoint->valueForKey("x")->floatValue()-20;
    point.y = heroPoint->valueForKey("y")->floatValue();
    endPoint.x = end->valueForKey("x")->floatValue();
    endPoint.y = end->valueForKey("y")->floatValue();
    
    CCMenuItemImage* item = CCMenuItemImage::create("bgbtn.png", "bgbtn.png");
    item->setTarget(this, menu_selector(MainLayer::menuBtn));
    CCMenu* menu = CCMenu::create(item,NULL);
    menu->setPosition(ccp(20, 295));
    this->addChild(menu,1);
    CCSprite* score = CCSprite::create("bg4.png");
    score->setScale(0.2);
    score->setPosition(ccp(445, 305));
    this->addChild(score);
    CCSprite* level = CCSprite::create("bg22.png");
    level->setScale(0.07);
    level->setPosition(ccp(445, 260));
    this->addChild(level);
    scoreLabel = CCLabelTTF::create("", "",12 );
    scoreLabel->setPosition(ccp(445, 305));
    this->addChild(scoreLabel,2);
    //分数
    levelScore = CCUserDefault::sharedUserDefault()->getIntegerForKey("Score");
    if (levelScore == 0) {
        levelScore = 100;
    }
    char scoretemp[50];
    sprintf(scoretemp, "%d",(int)levelScore);
    scoreLabel->setString(scoretemp);
    //关数
    char leveltemp[20];
    sprintf(leveltemp, "%i  /  24 ",levelNum);
    CCLabelTTF* levelLabel = CCLabelTTF::create(leveltemp, "", 8);
    levelLabel->setPosition(ccp(448, 280));
    this->addChild(levelLabel);
        
    
    loadEnery();
    
    //波数
    waveNum = WaveArray->count();
    char wavetemp[20];
    sprintf(wavetemp, "%i",waveNum);
    waveLabel = CCLabelTTF::create(wavetemp, "", 12);
    waveLabel->setPosition(ccp(455, 250));
    this->addChild(waveLabel);

    this->schedule(schedule_selector(MainLayer::move),0.3);
    this->schedule(schedule_selector(MainLayer::buttleAttack),0.1);
    this->schedule(schedule_selector(MainLayer::selectBullettype), 0.1);
    this->schedule(schedule_selector(MainLayer::selectEneryBlood), 0.1);
    return true;
}
void MainLayer::move()
{
    for (int i=0; i<oneWaveArray->count(); i++)
    {
        Enery* enery = (Enery*)oneWaveArray->objectAtIndex(i);
        CCPoint heroPo = enery->getPosition();
        if (enery->canAction)
        {
            float x;
            float y;
            for (int i = 0; i<int(signObjects->getObjects()->count()); i++)
            {
                CCDictionary* signVal =(CCDictionary*) signObjects->getObjects()->objectAtIndex(i);
                if (signVal->valueForKey("tag")->intValue() == (enery->tag+1))
                {
                    x = signVal->valueForKey("x")->floatValue();
                    y = signVal->valueForKey("y")->floatValue();
                }
                
            }
            int nextM = x/myTiledMap->getTileSize().width;
            int nextN = y/myTiledMap->getTileSize().height;
            
            int m = heroPo.x/myTiledMap->getTileSize().width;
            int n = heroPo.y/myTiledMap->getTileSize().height;
            if (m<nextM)
            {
                enery->rightAction();
                sprintf(enery->Direction, "right");
                
            }
            else if (n<nextN)
            {
                enery->forthAction();
                sprintf(enery->Direction, "forth");
                
            }
            else if (n>nextN)
            {
                enery->downAction();
                sprintf(enery->Direction, "down");
            }else if (m>nextM)
            {
                enery->leftAction();
                sprintf(enery->Direction, "left");
            }else
            {
                
            }
            if (ccpDistance(heroPo, endPoint)<15)
            {
                this->unschedule(schedule_selector(MainLayer::move));
                this->unschedule(schedule_selector(MainLayer::buttleAttack));
                this->unschedule(schedule_selector(MainLayer::selectBullettype));
                this->unschedule(schedule_selector(MainLayer::selectEneryBlood));
                enery->stopAllActions();
                //this->stopAllActions();
           /////////////////////////////////////////////////
                Levels* levels = LevelParser::loadData();
                for (int i = 0; i<(levels->_levels)->count(); i++) {
                    Level* level = (Level*)((levels->_levels)->objectAtIndex(i));
                    int num = level->_number;
                    if (num >= 2) {
                        if (num == levelNum - 1) {
                            CCUserDefault::sharedUserDefault()->setIntegerForKey("Score", level->_score);
                        }
                    }
                    else
                    {
                       CCUserDefault::sharedUserDefault()->setIntegerForKey("Score", 0); 
                    }
                    
                    
                }
                /////////////////////////////////////////
                CCUserDefault::sharedUserDefault()->setBoolForKey("WIN",false);
                failLayer = FailScene::create();
                failLayer->setPosition(ccp(10, 480));
                this->addChild(failLayer,3);
                CCMoveTo* move = CCMoveTo::create(1.0, ccp(10, 20));
                failLayer->runAction(move);
            }
            else
            {
                if (ccpDistance(heroPo, ccp(x, y))<17)
                {
                    enery->tag++;
                }
                
                if (strcmp(enery->Direction, "left")==0)
                {
                    enery->leftAction();
                    
                }else if (strcmp(enery->Direction, "right")==0)
                {
                    enery->rightAction();
                    
                }else if (strcmp(enery->Direction, "down")==0)
                {
                    enery->downAction();
                    
                }else if (strcmp(enery->Direction, "forth")==0)
                {
                    enery->forthAction();
                    
                }else
                {
                    
                }
            }
            
        }
    }
}
#pragma mark - Touch
void MainLayer::onEnter()
{
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 3, false);
    CCLayer::onEnter();
}
void MainLayer::onExit()
{
    CCLayer::onExit();
}
bool MainLayer::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
    return true;

}
void MainLayer::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{
    
}
void MainLayer::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{
    CCPoint p = pTouch->getLocation();
    int x = p.x /myTiledMap->getTileSize().width;
    int y = ((myTiledMap->getMapSize().height * myTiledMap->getTileSize().height) - p.y)/myTiledMap->getTileSize().height;
    CCPoint tileCoord = ccp(x,y);
    int pp = meta->tileGIDAt(tileCoord);
    CCLOG("-------%i",pp);
    if (pp) {
        CCDictionary* dic = myTiledMap->propertiesForGID(pp);
        if (dic)
        {
            CCString* collidate = (CCString*)dic->valueForKey("Collidable");
            if (collidate && collidate->compare("True") == 0) {
                char towerty[30];
                sprintf(towerty, "%s",CCUserDefault::sharedUserDefault()->getStringForKey("towerType").c_str())
                ;
                if (strlen(towerty) !=0 )
                {
                    bool istower = false;
                    if (towerArray->count()>0)
                    {
                        for (int i = 0; i<towerArray->count(); i++) {
                            TowerTools* tools = (TowerTools*)towerArray->objectAtIndex(i);
                            if (ccpDistance(pTouch->getLocation(), tools->getPosition())<40)
                            {
                                istower = true;
                            }
                            
                        }
                        
                        if (!istower) {
                            TowerTools* oneTower;
                            oneTower = new TowerTools(oneTower->TowerCreatWithtag(towerty));
                            if (levelScore>= oneTower->NeedGold) {
                                int towerTag = CCUserDefault::sharedUserDefault()-> getIntegerForKey("towerTag");
                                CCUserDefault::sharedUserDefault()->setFloatForKey(oneTower->towerName, oneTower->Frequency);
                                oneTower->setPosition(ccp(pTouch->getLocation().x, pTouch->getLocation().y));
                                oneTower->setScale(0.65);
                                oneTower->setTag(towerTag);
                                CCLOG("********%i",oneTower->NeedGold);
                                levelScore-=oneTower->NeedGold;
                                char temp1[20];
                                sprintf(temp1, "%.f",levelScore);
                                scoreLabel->setString(temp1);
                                this->addChild(oneTower,1);
                                towerArray->addObject(oneTower);
                            }
                             CCUserDefault::sharedUserDefault()->setStringForKey("towerType", "");
                            oneTower->release();
                        }
                    }else if(towerArray->count()==0)
                    {
                        TowerTools* oneTower;
                        oneTower = new TowerTools(oneTower->TowerCreatWithtag(towerty));
                        if (levelScore>=oneTower->NeedGold)
                        {
                            int towerTag = CCUserDefault::sharedUserDefault()-> getIntegerForKey("towerTag");
                            oneTower->setPosition(ccp(pTouch->getLocation().x, pTouch->getLocation().y));
                            oneTower->setTag(towerTag);
                            oneTower->setScale(0.65);
                            CCLOG("********%i",oneTower->NeedGold);
                            levelScore-=oneTower->NeedGold;
                            char temp2[20];
                            sprintf(temp2, "%.f",levelScore);
                            scoreLabel->setString(temp2);
                            this->addChild(oneTower,1);
                            towerArray->addObject(oneTower);
                        }
                        CCUserDefault::sharedUserDefault()->setStringForKey("towerType", "");
                        oneTower->release();
                        
                    }
                    
                    
                }
                

            }
        }
    }
}
void MainLayer::ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent)
{
}

void MainLayer::menuBtn()
{
    addTower* layer = addTower::create();
    layer->setPosition(ccp(80, 275));
    this->addChild(layer,1);
}
#pragma mark - Enemy
bool MainLayer:: loadEnery()
{
    int level = CCUserDefault::sharedUserDefault()->getIntegerForKey("LevelNum")-1;
    WaveArray = (CCArray*)EneryArray->objectAtIndex(1);
    if (wave>=WaveArray->count()) {
        CCUserDefault::sharedUserDefault()->setBoolForKey("WIN", true);
        failLayer = FailScene::create();
        failLayer->setPosition(ccp(10, 480));
        this->addChild(failLayer,3);
        CCMoveTo* move = CCMoveTo::create(1.0, ccp(10, 20));
        failLayer->runAction(move);
        this->parser();
    }else
    {
        CCArray* arrayEnery = (CCArray*)WaveArray->objectAtIndex(wave);
        for (int i= 0; i<arrayEnery->count(); i++) {
            CCDictionary *pDic=(CCDictionary*)arrayEnery->objectAtIndex(i);
            int enerytag = pDic->valueForKey("tag")->intValue();
            float eneryTime = pDic->valueForKey("showTime")->floatValue();
            Enery* oneEnery;
            oneEnery = new Enery(oneEnery->EneryCreatWithtag(enerytag));
            oneEnery->setPosition(ccp(point.x-50, point.y));
            addChild(oneEnery,1);
            oneWaveArray->addObject(oneEnery);
            oneEnery->scheduleOnce(schedule_selector(Enery::startEnerymove), eneryTime);
            
        }
        wave++;
        return true;
    }
    
}

void MainLayer:: buttleAttack()
{
    
    if (towerArray&&towerArray->count()>0)
    {
        for (int i = 0; i<towerArray->count(); i++)
        {
            TowerTools* tools = (TowerTools*)towerArray->objectAtIndex(i);
            for (int j= 0; j<oneWaveArray->count(); j++)
            {
                Enery* enery = (Enery*)oneWaveArray->objectAtIndex(j);
                if (ccpDistance(tools->getPosition(), enery->getPosition())<tools->AttackRange && enery->getPosition().x>20)
                {
                    tools->tempFre--;
                    
                    if (tools->tempFre==0)
                    {
                        
                        Bullet* onebullet = new Bullet(tools, tools->getPosition(), this);
                        float distance = ccpDistance(tools->getPosition(), enery->getPosition());
                        CCMoveTo* bulletMove = CCMoveTo::create(sqrtf(distance)/40, enery->getPosition());
                        onebullet->runAction(bulletMove);
                        CCCallFuncND* fuuND = CCCallFuncND::create(this, callfuncND_selector(Bullet::isMoved), onebullet);
                        CCSequence* seq  = CCSequence::create(CCDelayTime::create(sqrtf(distance)/40),fuuND,NULL);
                        onebullet->runAction(seq);
                        bulletArray->addObject(onebullet);
                        tools->tempFre =tools->Frequency;
                        break;
                        
                    }
                }
            }
            
        }
    }
    
}

void MainLayer::selectEneryBlood()
{
    if (oneWaveArray&&oneWaveArray->count()>0)
    {
        for (int i = 0; i< oneWaveArray->count(); i++)
        {
            Enery* enery = (Enery*)oneWaveArray->objectAtIndex(i);
            if (enery->blood<=0)
            {
                levelScore+= enery->Catchgold;
                char score[50];
                sprintf(score, "%.f",levelScore);
                scoreLabel->setString(score);
                CCUserDefault::sharedUserDefault()->setIntegerForKey("Score", levelScore);
                CCCallFuncND* funD = CCCallFuncND::create(this, callfuncND_selector(MainLayer::removeEnery), enery);
                enery->runAction(funD);
            }
        }
        
    }
    
}

//移除敌人
void MainLayer:: removeEnery(Enery* enery)
{
    
    
    enery->removeFromParent();
    oneWaveArray->removeObject(enery);
    if (oneWaveArray->count() ==0) {
        waveNum--;
        char wave1temp[20];
        sprintf(wave1temp, "%i",waveNum);
        waveLabel->setString(wave1temp);
        oneWaveArray->removeAllObjects();
        loadEnery();
    }
    
}

//子弹移除
void MainLayer:: removeBullet(Bullet* bullet)
{
    bullet->removeFromParent();
    
    bulletArray->removeObject(bullet);
    
}

//子弹是否用过
void MainLayer:: selectBullettype()
{
    if (bulletArray&&bulletArray->count()>0)
    {
        for (int i = 0; i<bulletArray->count(); i++)
        {
            Bullet* bullet = (Bullet*)bulletArray->objectAtIndex(i);
            
            if (!bullet->Moveed&&!bullet->isAttack)
            {
                if (oneWaveArray&&oneWaveArray->count()>0)
                {
                    for (int j= 0; j<oneWaveArray->count(); j++)
                    {
                        Enery* enery = (Enery*)oneWaveArray->objectAtIndex(j);
                        if (ccpDistance(bullet->getPosition(), enery->getPosition())<20)
                        {
                            enery->blood-=bullet->attack;
                            (enery->slider)->setValue(enery->blood);
                            bullet->isAttack = true;
                            
                        }
                        
                    }
                }
                
            }else
            {
                
                CCCallFuncND* fun = CCCallFuncND::create(this, callfuncND_selector(MainLayer::removeBullet), bullet);
                bullet->runAction(fun);
            }
            
        }
    }
}

void MainLayer::parser()
{
    string filePath = CCFileUtils::sharedFileUtils()->fullPathForFilename("Level.xml");
    TiXmlDocument* myDocument = new TiXmlDocument(filePath.c_str());
    myDocument->LoadFile();
    TiXmlElement* element = myDocument->RootElement()->FirstChildElement();//第一层
    while (element) {
        TiXmlElement* number = element->FirstChildElement();
        TiXmlElement* unlocked = number->NextSiblingElement();
        TiXmlElement* numberX = unlocked->NextSiblingElement();
        TiXmlElement* numberY = numberX->NextSiblingElement();
        TiXmlElement* score = numberY->NextSiblingElement();
        char leveltmp[20];
        sprintf(leveltmp, "%i",levelNum);
        if (strcmp((char*)number->FirstChild()->Value(), leveltmp) == 0) {
            TiXmlNode* oldScore = score->FirstChild();
            int scorenum = CCUserDefault::sharedUserDefault()->getIntegerForKey("Score");
            char scoreTemp[20];
            sprintf(scoreTemp, "%i",scorenum);
            TiXmlText newScore(scoreTemp);
            score->ReplaceChild(oldScore, newScore);
            myDocument->SaveFile();
        }
        char nextLevel[20];
        sprintf(nextLevel, "%i",levelNum+1);
        if (strcmp((char*)number->FirstChild()->Value(), nextLevel) == 0) {
            TiXmlNode* oldVal = unlocked->FirstChild();
            char temp[3];
            sprintf(temp, "%i",1);
            TiXmlText newVal(temp);
            unlocked->ReplaceChild(oldVal, newVal);
            myDocument->SaveFile();
        }
        element = element->NextSiblingElement();
    }
    
}
MainLayer::~MainLayer()
{
    CC_SAFE_RELEASE(EneryArray);
    CC_SAFE_RELEASE(WaveArray);
    CC_SAFE_RELEASE(oneWaveArray);
    CC_SAFE_RELEASE(towerArray);
    CC_SAFE_RELEASE(bulletArray);
}