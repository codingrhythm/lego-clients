// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from lego.djinni

#import <Foundation/Foundation.h>

@interface LGQuestion : NSObject
- (nonnull instancetype)initWithId:(nonnull NSString *)id
                             title:(nonnull NSString *)title
                      responseType:(int32_t)responseType
               questionDescription:(nonnull NSString *)questionDescription
                             order:(int32_t)order;
+ (nonnull instancetype)questionWithId:(nonnull NSString *)id
                                 title:(nonnull NSString *)title
                          responseType:(int32_t)responseType
                   questionDescription:(nonnull NSString *)questionDescription
                                 order:(int32_t)order;

/** id of the question */
@property (nonatomic, readonly, nonnull) NSString * id;

/** title of the question */
@property (nonatomic, readonly, nonnull) NSString * title;

/** response type */
@property (nonatomic, readonly) int32_t responseType;

/** description of the question */
@property (nonatomic, readonly, nonnull) NSString * questionDescription;

/** order of the question */
@property (nonatomic, readonly) int32_t order;

@end
