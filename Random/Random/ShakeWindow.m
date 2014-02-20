//
//  ShakeWindow.m
//  Random
//
//  Created by quentin on 12-12-14.
//
//

#import "ShakeWindow.h"

@implementation ShakeWindow

-(void)motionBegan:(UIEventSubtype)motion withEvent:(UIEvent *)event{
    
}

-(void)motionCancelled:(UIEventSubtype)motion withEvent:(UIEvent *)event{
    
}

-(void)motionEnded:(UIEventSubtype)motion withEvent:(UIEvent *)event{
    if (motion==UIEventSubtypeMotionShake) {
        [[NSNotificationCenter defaultCenter] postNotificationName:@"shake" object:self];
    }
}

@end
