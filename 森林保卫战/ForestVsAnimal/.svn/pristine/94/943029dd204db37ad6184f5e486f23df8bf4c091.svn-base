//
//  LevelParser.cpp
//  ForestVsAnimal
//
//  Created by OldHorse on 13-12-17.
//
//

#include "LevelParser.h"
#include "Level.h"
#include "tinystr.h"
#include "tinyxml.h"
using namespace std;
Levels* LevelParser::loadData()
{
    Levels* levels = new Levels();
    char temp[50];
    //加载xml文件
    sprintf(temp, "Level.xml");
    string filePath = CCFileUtils::sharedFileUtils()->fullPathForFilename(temp);
    //解析xml文件
    TiXmlDocument* myDocument = new TiXmlDocument(filePath.c_str());
    myDocument->LoadFile();//把xml文件内容加载到内存
    TiXmlElement* element = myDocument->RootElement()->FirstChildElement();//第一层
    while (element) {
        TiXmlElement* number = element->FirstChildElement();
        TiXmlElement* unlocked = number->NextSiblingElement();
        TiXmlElement* numberX  = unlocked->NextSiblingElement();
        TiXmlElement* numberY = numberX->NextSiblingElement();
        TiXmlElement* score = numberY->NextSiblingElement();
        bool tep;
        if (strcmp((char*)unlocked->FirstChild()->Value(), "1")) {
            tep = false;
        }
        else
        {
            tep = true;
        }
        Level* level = new Level(atoi(number->FirstChild()->Value()),tep,atoi(numberX->FirstChild()->Value()),atoi(numberY->FirstChild()->Value()),atoi(score->FirstChild()->Value()));
        levels->_levels->addObject(level);
        element = element->NextSiblingElement();
    }
    return levels;
    
}