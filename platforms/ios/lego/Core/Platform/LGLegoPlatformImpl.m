//
//  LGLegoPlatformImpl.m
//  lego
//
//  Created by Yuzhou Zhu on 29/6/18.
//  Copyright © 2018 Yuzhou Zhu. All rights reserved.
//

#import "LGLegoPlatformImpl.h"
#import <GRPCClient/GRPCCall+ChannelArg.h>
#import <GRPCClient/GRPCCall+Tests.h>
#import <ProtoRPC/ProtoService.h>
#import "Lego.pbrpc.h"
#import "LGNetworkCallback.h"
#import "Template+Extensions.h"


@interface LGLegoPlatformImpl ()
@property (strong, nonatomic) Lego *grpcClient;
@property (strong, nonnull, nonatomic) NSString * host;
@end

@implementation LGLegoPlatformImpl

- (instancetype)init {
    self = [super init];
    if (self) {
        _host = @"localhost:8513";
        [GRPCCall setUserAgentPrefix:@"Lego/1.0" forHost:_host];
        [GRPCCall useInsecureConnectionsForHost:_host];
        _grpcClient = [[Lego alloc] initWithHost:_host];
    }
    return self;
}


- (NSString *)getStoragePath {
    NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
    return [paths objectAtIndex:0];
}

- (void)grpcGetData:(LGNetworkCallback *)callback {
    GetRequest *request = [GetRequest message];
    request.flag = @"flag";
    GRPCProtoCall * call = [_grpcClient RPCToGetDataWithRequest:request handler:^(Template * _Nullable response, NSError * _Nullable error) {
        [callback onGrpcGetDataSuccess:response.viewModel];
    }];

    [call start];
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
