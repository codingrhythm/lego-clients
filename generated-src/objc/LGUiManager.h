// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from lego.djinni

#import <Foundation/Foundation.h>
@class LGUiManager;
@protocol LGUiObserver;
@protocol LGUiPlatformSupport;


@interface LGUiManager : NSObject

+ (nullable LGUiManager *)create:(nullable id<LGUiObserver>)observer
                        platform:(nullable id<LGUiPlatformSupport>)platform;

- (void)start;

- (void)stop;

- (void)updateTitle:(nonnull NSString *)newTitle;

- (void)updateFirstName:(nonnull NSString *)firstName;

- (void)updateLastName:(nonnull NSString *)lastName;

- (nonnull NSString *)getTimeString;

@end
