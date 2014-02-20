//
//  LoadingLayer.h
//  Random
//
//  Created by quentin on 12-12-14.
//  Copyright 2012年 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "cocos2d.h"

typedef enum{
    TargetSceneInvalid=0,
    TargetSceneShake,
    TargetSceneMax,
}TargetScene;

@interface LoadingLayer : CCScene {
    TargetScene targetScene;
}
+(CCScene *)scene:(TargetScene)target;
@end
