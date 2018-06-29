//
//  ViewController.m
//  lego
//
//  Created by Yuzhou Zhu on 29/6/18.
//  Copyright © 2018 Yuzhou Zhu. All rights reserved.
//

#import "ViewController.h"
#import "LGLegoCore.h"
#import "LGLegoPlatformImpl.h"

@interface ViewController ()

@end

@implementation ViewController {
    LGLegoCore *_coreAPI;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    LGLegoPlatformImpl *platform = [[LGLegoPlatformImpl alloc] init];
    _coreAPI = [LGLegoCore create:platform];
}

- (IBAction)actionButtonTapped:(id)sender {
    for (int i = 0; i < 10; i ++) {
        [_coreAPI getData:true];
    }
}

@end
