//
//  ShakeLayer.m
//  Random
//
//  Created by quentin on 12-12-14.
//  Copyright 2012年 __MyCompanyName__. All rights reserved.
//

#import "ShakeLayer.h"

#define kBackTag 10

@implementation ShakeLayer

+(CCScene *)scene{
    CCScene *scene=[CCScene node];
    ShakeLayer *layer=[ShakeLayer node];
    [scene addChild:layer];
    return scene;
}

-(id)init{
    if (self=[super init]) {
        
        CGSize winSize=[[CCDirector sharedDirector] winSize];
        
        
        CCLayerColor *layerColor=[CCLayerColor layerWithColor:ccc4(25, 255, 100, 255)];
        [self addChild:layerColor];
        
        CCSprite *backSprite=[CCSprite spriteWithFile:@"back.png"];
        backSprite.position=ccp(winSize.width*0.5, winSize.width*0.5);
        backSprite.tag=kBackTag;
        [self addChild:backSprite];
        
        CCSprite *sprite=[CCSprite spriteWithFile:@"shi.png"];
        sprite.position=ccp(winSize.width*0.5,winSize.width*0.5);
        sprite.tag=1;
        sprite.anchorPoint=ccp(0.2,0.5);
        [self addChild:sprite];
        [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(shake) name:@"shake" object:nil];
        
        CCLabelTTF *shakeLabel=[CCLabelTTF labelWithString:@"Shake or touch your phone" fontName:@"Marker Felt" fontSize:20];
        shakeLabel.color=ccc3(3, 100, 200);
        shakeLabel.anchorPoint=ccp(0.5,0);
        shakeLabel.position=ccp(winSize.width/2, winSize.width);
        [self addChild:shakeLabel];
        
        float shakeW=shakeLabel.contentSize.width;
        
        CCSprite *shakeSprite=[CCSprite spriteWithFile:@"shake.png"];
        shakeSprite.position=ccp(winSize.width/2+shakeW/2, winSize.width);
        [self addChild:shakeSprite];
        
        
        CCRotateTo *rotateLeft=[CCRotateTo actionWithDuration:1 angle:-40];
        CCRotateTo *rotateRight=[CCRotateTo actionWithDuration:2 angle:40];
        CCSequence *sequence=[CCSequence actions:rotateLeft,rotateRight,nil];
        CCRepeatForever *forever=[CCRepeatForever actionWithAction:sequence];
        [shakeSprite runAction:forever];
        
        self.isTouchEnabled=YES;
    }
    return self;
}

-(void)ccTouchesBegan:(NSSet *)touches withEvent:(UIEvent *)event{
    UITouch *touch=[touches anyObject];
    CGPoint location=[touch locationInView:[touch view]];
    location=[[CCDirector sharedDirector] convertToGL:location];
    CCNode *node=[self getChildByTag:kBackTag];
    if (CGRectContainsPoint([node boundingBox], location)) {
        [self shake];
    }
}

-(void)shake{
    CCNode *node=[self getChildByTag:1];
    [node unscheduleAllSelectors];
    float angle=CCRANDOM_0_1()*360*5;
    CCRotateBy *rotate=[CCRotateBy actionWithDuration:15 angle:angle];
    CCAction *next=[CCEaseBackInOut actionWithAction:rotate];
    [node runAction:next];
}
@end
