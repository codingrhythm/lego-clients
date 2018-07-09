// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from lego.djinni

#import "LGSTemplate.h"
#import <Foundation/Foundation.h>
@class LGLegoCore;
@protocol LGLegoPlatform;


/** Shared core APIs */
@interface LGLegoCore : NSObject

/** class method to create core API instance */
+ (nullable LGLegoCore *)create:(nullable id<LGLegoPlatform>)platform;

/** get data */
- (void)getData;

/** send data */
- (void)sendData:(nonnull LGSTemplate *)data;

/** upload file */
- (void)uploadFile:(nonnull NSData *)fileData;

/** download file */
- (void)downloadFile:(nonnull NSString *)fileId;

@end
