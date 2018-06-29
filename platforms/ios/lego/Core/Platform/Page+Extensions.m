//
//  Page+Extensions.m
//  lego
//
//  Created by Yuzhou Zhu on 29/6/18.
//  Copyright © 2018 Yuzhou Zhu. All rights reserved.
//

#import "Page+Extensions.h"
#import "Question+Extensions.h"

@implementation Page (Extensions)
- (LGPage *)viewModel {
    NSMutableArray<LGQuestion*> *questions = [[NSMutableArray alloc] initWithCapacity:self.questionsArray_Count];
    for (Question *question in self.questionsArray) {
        [questions addObject:question.viewModel];
    }
    return [[LGPage alloc] initWithId:self.id_p
                                title:self.title
                                order:self.order
                            questions:questions];
}
@end
