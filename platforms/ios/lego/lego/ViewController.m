//
//  ViewController.m
//  lego
//
//  Created by Yuzhou Zhu on 29/6/18.
//  Copyright © 2018 Yuzhou Zhu. All rights reserved.
//

#import "ViewController.h"
#import "LGLegoCore.h"
#import "LGLegoPlatformImpl.h"

@interface ViewController ()

@end

const int NUMBER_OF_REQUESTS = 1;

@implementation ViewController {
    LGLegoCore *_coreAPI;
    int _numOfRequests;
    NSDate *startTime;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    LGLegoPlatformImpl *platform = [[LGLegoPlatformImpl alloc] initWithCallback:^{
        _numOfRequests ++;
        if (_numOfRequests == NUMBER_OF_REQUESTS) {
            NSLog(@"done: %0.5f", -[startTime timeIntervalSinceNow]);
        }
    }];
    _coreAPI = [LGLegoCore create:platform];
}

- (IBAction)actionButtonTapped:(id)sender {
    _numOfRequests = 0;
    startTime = [NSDate new];
    for (int i = 0; i < NUMBER_OF_REQUESTS; i ++) {
        [self getDataFromDjinni];
        //[self getData];
    }
}

- (void)getDataFromDjinni {
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_BACKGROUND, 0), ^{
        [_coreAPI getData:true];
    });
}

- (NSString *)getStoragePath {
    NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
    return [paths objectAtIndex:0];
}

- (void)getData {
    NSMutableURLRequest *urlRequest = [[NSMutableURLRequest alloc] initWithURL:[NSURL URLWithString:@"http://localhost:8512/data"]];

    //create the Method "GET"
    [urlRequest setHTTPMethod:@"GET"];

    NSURLSession *session = [NSURLSession sharedSession];

    NSURLSessionDataTask *dataTask = [session dataTaskWithRequest:urlRequest completionHandler:^(NSData *data, NSURLResponse *response, NSError *error) {
        NSHTTPURLResponse *httpResponse = (NSHTTPURLResponse *)response;
        if(httpResponse.statusCode == 200) {
            NSError *parseError = nil;
            NSDictionary *responseDictionary = [NSJSONSerialization JSONObjectWithData:data options:0 error:&parseError];
            NSString *templateID = responseDictionary[@"id"];
            dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_BACKGROUND, 0), ^{
                NSString *filePath = [[self getStoragePath] stringByAppendingPathComponent:[NSString stringWithFormat:@"%@.json", templateID]];
                [data writeToFile:filePath atomically:YES];
                [self readDataFromDisk: filePath];
            });
        } else {
            NSLog(@"Error");
        }
    }];
    [dataTask resume];
}

- (void)readDataFromDisk: (NSString *)filePath {

    NSData *data = [[NSFileManager defaultManager] contentsAtPath:filePath];
    NSError *parseError = nil;
    NSDictionary *responseDictionary = [NSJSONSerialization JSONObjectWithData:data options:0 error:&parseError];
    NSMutableArray<LGPage*> *pages = [[NSMutableArray alloc] init];
    NSArray *_pages = (NSArray *)responseDictionary[@"pages"];

    for (NSDictionary *page in _pages) {
        NSMutableArray<LGQuestion*> *questions = [[NSMutableArray alloc] init];
        NSArray *_questions = (NSArray *)page[@"questions"];

        for (NSDictionary *question in _questions) {
            [questions addObject:[[LGQuestion alloc] initWithId:question[@"id"]
                                                          title:question[@"title"]
                                                   responseType:[(NSNumber *)question[@"response_type"] intValue]
                                            questionDescription:question[@"question_description"]
                                                          order:[(NSNumber *)question[@"order"] intValue]]];
        }

        [pages addObject:[[LGPage alloc] initWithId:page[@"id"]
                                              title:page[@"title"]
                                              order:[(NSNumber *)page[@"order"] intValue]
                                          questions:questions]];
    }

    LGTemplate *template = [[LGTemplate alloc] initWithId:responseDictionary[@"id"]
                                                     name:responseDictionary[@"name"]
                                                    pages:pages];
    NSLog(@"%@", template.id);
    _numOfRequests ++;
    if (_numOfRequests == NUMBER_OF_REQUESTS) {
        NSLog(@"done: %0.5f", -[startTime timeIntervalSinceNow]);
    }
}

@end
