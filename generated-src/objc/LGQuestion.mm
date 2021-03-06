// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from lego.djinni

#import "LGQuestion.h"


@implementation LGQuestion

- (nonnull instancetype)initWithId:(nonnull NSString *)id
                             title:(nonnull NSString *)title
                      responseType:(int32_t)responseType
               questionDescription:(nonnull NSString *)questionDescription
                             order:(int32_t)order
{
    if (self = [super init]) {
        _id = [id copy];
        _title = [title copy];
        _responseType = responseType;
        _questionDescription = [questionDescription copy];
        _order = order;
    }
    return self;
}

+ (nonnull instancetype)questionWithId:(nonnull NSString *)id
                                 title:(nonnull NSString *)title
                          responseType:(int32_t)responseType
                   questionDescription:(nonnull NSString *)questionDescription
                                 order:(int32_t)order
{
    return [[self alloc] initWithId:id
                              title:title
                       responseType:responseType
                questionDescription:questionDescription
                              order:order];
}

- (NSString *)description
{
    return [NSString stringWithFormat:@"<%@ %p id:%@ title:%@ responseType:%@ questionDescription:%@ order:%@>", self.class, (void *)self, self.id, self.title, @(self.responseType), self.questionDescription, @(self.order)];
}

@end
