// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from lego.djinni

#import "LGTemplate.h"


@implementation LGTemplate

- (nonnull instancetype)initWithId:(nonnull NSString *)id
                              name:(nonnull NSString *)name
                             pages:(nonnull NSArray<LGPage *> *)pages
{
    if (self = [super init]) {
        _id = [id copy];
        _name = [name copy];
        _pages = [pages copy];
    }
    return self;
}

+ (nonnull instancetype)templateWithId:(nonnull NSString *)id
                                  name:(nonnull NSString *)name
                                 pages:(nonnull NSArray<LGPage *> *)pages
{
    return [[self alloc] initWithId:id
                               name:name
                              pages:pages];
}

- (NSString *)description
{
    return [NSString stringWithFormat:@"<%@ %p id:%@ name:%@ pages:%@>", self.class, (void *)self, self.id, self.name, self.pages];
}

@end