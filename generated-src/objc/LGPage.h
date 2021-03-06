// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from lego.djinni

#import "LGQuestion.h"
#import <Foundation/Foundation.h>

@interface LGPage : NSObject
- (nonnull instancetype)initWithId:(nonnull NSString *)id
                             title:(nonnull NSString *)title
                             order:(int32_t)order
                         questions:(nonnull NSArray<LGQuestion *> *)questions;
+ (nonnull instancetype)pageWithId:(nonnull NSString *)id
                             title:(nonnull NSString *)title
                             order:(int32_t)order
                         questions:(nonnull NSArray<LGQuestion *> *)questions;

/** id of the page */
@property (nonatomic, readonly, nonnull) NSString * id;

/** title of the page */
@property (nonatomic, readonly, nonnull) NSString * title;

/** order of the page */
@property (nonatomic, readonly) int32_t order;

/** questions */
@property (nonatomic, readonly, nonnull) NSArray<LGQuestion *> * questions;

@end
