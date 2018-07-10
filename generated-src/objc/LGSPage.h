// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from lego.djinni

#import "LGSQuestion.h"
#import <Foundation/Foundation.h>

@interface LGSPage : NSObject
- (nonnull instancetype)initWithId:(nonnull NSString *)id
                             title:(nonnull NSString *)title
                             order:(int32_t)order
                         questions:(nonnull NSArray<LGSQuestion *> *)questions;
+ (nonnull instancetype)sPageWithId:(nonnull NSString *)id
                              title:(nonnull NSString *)title
                              order:(int32_t)order
                          questions:(nonnull NSArray<LGSQuestion *> *)questions;

/** id of the page */
@property (nonatomic, readonly, nonnull) NSString * id;

/** title of the page */
@property (nonatomic, readonly, nonnull) NSString * title;

/** order of the page */
@property (nonatomic, readonly) int32_t order;

/** questions */
@property (nonatomic, readonly, nonnull) NSArray<LGSQuestion *> * questions;

@end