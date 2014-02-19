//
//  Bullet.cpp
//  test
//
//  Created by user on 13-12-23.
//
//

#include "Bullet.h"
#include "TowerTools.h"
Bullet:: Bullet(TowerTools*_tools,CCPoint p,CCLayer *layer)
{
    char towername[30];
    sprintf(towername, "%sBullet.png",_tools->towerName);
    this->initWithFile(towername);
    this->setPosition(ccp(p.x, p.y-5));
    this->attack = _tools->Attack;
    this->isAttack = false;
    this->Moveed = false;
    layer->addChild(this,1);
}

void Bullet:: isMoved(Bullet*bullet)
{
    bullet->Moveed = true;
}

Bullet::~Bullet()
{
   
    
}
