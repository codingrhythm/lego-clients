//
//  AppDelegate.h
//  lego
//
//  Created by Yuzhou Zhu on 29/6/18.
//  Copyright © 2018 Yuzhou Zhu. All rights reserved.
//

#import <UIKit/UIKit.h>
#import  "LGAppManager.h"
#import "LGAppObserverImpl.h"

@interface AppDelegate : UIResponder <UIApplicationDelegate>

@property (strong, nonatomic) UIWindow *window;
@property (strong, nonatomic) LGAppManager *appManager;
@property (strong, nonatomic) LGAppObserverImpl *appObserver;

@end

