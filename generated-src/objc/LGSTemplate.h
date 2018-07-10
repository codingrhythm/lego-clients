// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from lego.djinni

#import "LGSPage.h"
#import <Foundation/Foundation.h>

@interface LGSTemplate : NSObject
- (nonnull instancetype)initWithId:(nonnull NSString *)id
                              name:(nonnull NSString *)name
                             pages:(nonnull NSArray<LGSPage *> *)pages;
+ (nonnull instancetype)sTemplateWithId:(nonnull NSString *)id
                                   name:(nonnull NSString *)name
                                  pages:(nonnull NSArray<LGSPage *> *)pages;

/** id of the template */
@property (nonatomic, readonly, nonnull) NSString * id;

/** name of the template */
@property (nonatomic, readonly, nonnull) NSString * name;

/** pages */
@property (nonatomic, readonly, nonnull) NSArray<LGSPage *> * pages;

@end