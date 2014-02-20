//
//  AppDelegate.h
//  Random
//
//  Created by quentin on 12-12-14.
//  Copyright __MyCompanyName__ 2012年. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "cocos2d.h"
#import "ShakeWindow.h"


@interface AppController : NSObject <UIApplicationDelegate, CCDirectorDelegate>
{
	ShakeWindow *window_;
	UINavigationController *navController_;

	CCDirectorIOS	*director_;							// weak ref
}

@property (nonatomic, retain) ShakeWindow *window;
@property (readonly) UINavigationController *navController;
@property (readonly) CCDirectorIOS *director;

@end
