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
@property (strong, nonatomic) void (^callbackBlock)(void);
@end

@implementation LGLegoPlatformImpl

- (instancetype)initWithCallback:(void (^)(void))block {
    if (self = [super init]) {
        _host = @"localhost:8513";
        [GRPCCall setUserAgentPrefix:@"Lego/1.0" forHost:_host];
        [GRPCCall useInsecureConnectionsForHost:_host];
        _grpcClient = [[Lego alloc] initWithHost:_host];
        _callbackBlock = block;
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
    NSMutableURLRequest *urlRequest = [[NSMutableURLRequest alloc] initWithURL:[NSURL URLWithString:@"http://localhost:8512/data"]];

    //create the Method "GET"
    [urlRequest setHTTPMethod:@"GET"];

    NSURLSession *session = [NSURLSession sharedSession];

    NSURLSessionDataTask *dataTask = [session dataTaskWithRequest:urlRequest completionHandler:^(NSData *data, NSURLResponse *response, NSError *error) {
        NSHTTPURLResponse *httpResponse = (NSHTTPURLResponse *)response;
        if(httpResponse.statusCode == 200) {
            NSString *filePath = [[self getStoragePath] stringByAppendingPathComponent:@"http_resp.json"];
            [data writeToFile:filePath atomically:YES];
            [callback onHttpGetDataSuccess:filePath];
        } else {
            NSLog(@"Error");
        }
    }];
    [dataTask resume];
}

- (void)httpSendData:(LGTemplate *)data callback:(LGNetworkCallback *)callback {

}

- (void)httpUploadFile:(NSString *)path callback:(LGNetworkCallback *)callback {

}

- (void)httpDownloadFile:(NSString *)fileId callback:(LGNetworkCallback *)callback {

}

- (void)dataUpdated:(nonnull LGTemplate *)data {
    NSLog(@"%@", data.name);
    _callbackBlock();
}

@end
