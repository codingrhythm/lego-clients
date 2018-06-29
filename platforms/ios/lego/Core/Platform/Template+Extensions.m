//
//  Template+Extensions.m
//  lego
//
//  Created by Yuzhou Zhu on 29/6/18.
//  Copyright © 2018 Yuzhou Zhu. All rights reserved.
//

#import "Template+Extensions.h"
#import "Page+Extensions.h"

@implementation Template (Extensions)

- (LGTemplate * )viewModel {
    NSMutableArray<LGPage*> *pages = [[NSMutableArray alloc] initWithCapacity:self.pagesArray_Count];
    for (Page* page in self.pagesArray) {
        [pages addObject:page.viewModel];
    }

    return [[LGTemplate alloc] initWithId:self.id_p
                                     name:self.name
                                    pages:pages];
}

@end
