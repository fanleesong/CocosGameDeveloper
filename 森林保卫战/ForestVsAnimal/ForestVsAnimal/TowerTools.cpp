//
//  TowerTools.cpp
//  test
//
//  Created by user on 13-12-19.
//
//

#include "TowerTools.h"
#include "Bullet.h"
using namespace std;
//构造函数
 TowerTools::TowerTools(TowerType towerType)
{
    switch (towerType) {
        case 0:
            this->initWithFile("turret1.png");
            Attack = 50;
            towerLevel = 1;
            AttackRange =  100;
            updataLevelGold = 50;
            Frequency = 9;
            tempFre = Frequency;
            NeedGold = 100;
            sprintf(towerName, "turret");
            this->isAttack = false;
            break;
        case 1:
            this->initWithFile("larrow1.png");
            Attack = 50;
             towerLevel = 1;
            Frequency = 15;
            AttackRange =  150;
            tempFre = Frequency;
            updataLevelGold = 50;
            NeedGold = 55;
            sprintf(towerName, "larrow");
            this->isAttack = false;
            break;
        case 2:
            this->initWithFile("deceleration1.png");
            Attack = 100;
            Frequency = 9;
            towerLevel = 1;
            tempFre = Frequency;
            updataLevelGold = 50;
            AttackRange =  160;
            NeedGold = 200;
            sprintf(towerName, "deceleration");
            this->isAttack = false;
            break;
        case 3:
            this->initWithFile("magic1.png");
            Attack = 50;
            Frequency = 5;
            tempFre = Frequency;
            towerLevel = 1;
            updataLevelGold = 100;
            AttackRange =  150;
            NeedGold = 150;
            sprintf(towerName, "magic");
            this->isAttack = false;
            break;
            
        default:
            break;
    }
}

void TowerTools:: updataLevel(TowerTools* oneTower)
{
    int leveltower = oneTower->towerLevel;
    leveltower +=1;
    char toolsname[30];
    sprintf(toolsname, "%s%d.png",oneTower->towerName,leveltower);
    if (leveltower==2) {
        this->removeAllChildren();
        this->initWithFile(toolsname);
        this->towerLevel = leveltower;
        this->Attack +=10;
        this->AttackRange +=5;
        this->Frequency -=6;
    }else if (leveltower==3)
    {
        this->removeAllChildren();
        this->initWithFile(toolsname);
        this->towerLevel = leveltower;
        this->Frequency -=6;
        this->AttackRange +=5;
        this->Attack +=10;
    }else
    {
        
    }
}


TowerType TowerTools:: TowerCreatWithtag(char* type)
{
   
    if (strcmp(type, "TurretTower")==0) {
        return TurretTower;
    }else if (strcmp(type, "LarrowTower")==0)
    {
        return LarrowTower;
    }else if (strcmp(type,"DecelerationTower" )==0)
    {
        return DecelerationTower;
    }else
        
    {
        return MagicTower;
    }
        
}
