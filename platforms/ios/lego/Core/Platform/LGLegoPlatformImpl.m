//
//  LGLegoPlatformImpl.m
//  lego
//
//  Created by Yuzhou Zhu on 29/6/18.
//  Copyright © 2018 Yuzhou Zhu. All rights reserved.
//

#import "LGLegoPlatformImpl.h"

@implementation LGLegoPlatformImpl

- (NSString *)getStoragePath {
    NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
    return [paths objectAtIndex:0];
}

- (void)grpcGetData:(LGNetworkCallback *)callback {

}

- (void)grpcSendData:(LGTemplate *)data callback:(LGNetworkCallback *)callback {

}

- (void)httpGetData:(LGNetworkCallback *)callback {

}

- (void)httpSendData:(LGTemplate *)data callback:(LGNetworkCallback *)callback {

}

- (void)httpUploadFile:(NSString *)path callback:(LGNetworkCallback *)callback {

}

- (void)httpDownloadFile:(NSString *)fileId callback:(LGNetworkCallback *)callback {

}

- (void)dataUpdated:(nonnull LGTemplate *)data {
    
}

@end
