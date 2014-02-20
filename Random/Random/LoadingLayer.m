//
//  LoadingLayer.m
//  Random
//
//  Created by quentin on 12-12-14.
//  Copyright 2012年 __MyCompanyName__. All rights reserved.
//

#import "LoadingLayer.h"
#import "ShakeLayer.h"

@implementation LoadingLayer

+(CCScene *)scene:(TargetScene)target{
    return [[[self alloc] initWithTargetScene:target] autorelease];
}

-(id)initWithTargetScene:(TargetScene)target{
    if (self=[super init]) {
        targetScene=target;
        
        CGSize winSize=[[CCDirector sharedDirector] winSize];
        
        CCLabelTTF *loading=[CCLabelTTF labelWithString:@"Loading" fontName:@"Marker Felt" fontSize:50];
        loading.position=ccp(winSize.width/2,winSize.height/2);
        [self addChild:loading];
        
        [self scheduleUpdate];
    }
    return self;
}


-(void)update:(ccTime)delta{
    [self unscheduleAllSelectors];
    switch (targetScene) {
        case TargetSceneShake:
            [[CCDirector sharedDirector] replaceScene:[CCTransitionFade transitionWithDuration:4 scene:[ShakeLayer scene]]];
            break;
        default:
            break;
    }
}

@end
