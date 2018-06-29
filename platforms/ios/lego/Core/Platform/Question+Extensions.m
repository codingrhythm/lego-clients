//
//  Question+Extensions.m
//  lego
//
//  Created by Yuzhou Zhu on 29/6/18.
//  Copyright © 2018 Yuzhou Zhu. All rights reserved.
//

#import "Question+Extensions.h"

@implementation Question (Extensions)
- (LGQuestion * )viewModel {
    return [[LGQuestion alloc] initWithId:self.id_p
                                    title:self.title
                             responseType:self.responseType
                      questionDescription:self.description_p
                                    order:self.order];
}

@end
