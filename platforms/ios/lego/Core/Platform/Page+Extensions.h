//
//  Page+Extensions.h
//  lego
//
//  Created by Yuzhou Zhu on 29/6/18.
//  Copyright © 2018 Yuzhou Zhu. All rights reserved.
//

#import "Lego.pbrpc.h"
#import "LGPage.h"

@interface Page (Extensions)
@property (strong, nonatomic, readonly) LGPage *viewModel;
@end
