//
//  HelloWorldLayer.m
//  Example
//
//  Created by Ngo Duc Hiep on 5/4/11.
//  Copyright __MyCompanyName__ 2011. All rights reserved.
//

// Import the interfaces
#import "HelloWorldScene.h"
#import "TouchTrailLayer.h"

// HelloWorld implementation
@implementation HelloWorld

+(id) scene
{
	// 'scene' is an autorelease object.
	CCScene *scene = [CCScene node];
	
	// 'layer' is an autorelease object.
	HelloWorld *layer = [HelloWorld node];
	
	// add layer as a child to scene
	[scene addChild: layer];
	
	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
-(id) init
{
	// always call "super" init
	// Apple recommends to re-assign "self" with the "super" return value
	if( (self=[super init] )) {
		// create and initialize a Label

		// ask director the the window size
		CGSize size = [[CCDirector sharedDirector] winSize];
	
        CCSprite *bg = [CCSprite spriteWithFile:@"Default.png"];
        bg.position = ccp( size.width /2 , size.height/2 );
        bg.rotation = 90;
        [self addChild:bg];
        
        TouchTrailLayer *layer = [TouchTrailLayer node];
		[self addChild:layer];
	}
		
	return self;
}

// on "dealloc" you need to release all your retained objects
- (void) dealloc
{
	// in case you have something to dealloc, do it in this method
	// in this particular example nothing needs to be released.
	// cocos2d will automatically release all the children (Label)
	
	// don't forget to call "super dealloc"
	[super dealloc];
}
@end
