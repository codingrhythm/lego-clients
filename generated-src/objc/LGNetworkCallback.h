// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from lego.djinni

#import "LGTemplate.h"
#import <Foundation/Foundation.h>


/** Callbacks */
@interface LGNetworkCallback : NSObject

/** http handlers */
- (void)onHttpDownloadFileSuccess:(nonnull NSString *)path;

- (void)onHttpUploadFileSuccess;

- (void)onHttpGetDataSuccess:(nonnull NSString *)path;

- (void)onHttpSendDataSuccess;

/** grpc handlers */
- (void)onGrpcGetDataSuccess:(nonnull LGTemplate *)data;

- (void)onGrpcSendDataSuccess;

@end
