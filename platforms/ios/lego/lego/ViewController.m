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
@property (nonatomic, strong) NSString *templateID;
@end

const int NUMBER_OF_REQUESTS = 10;

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

- (IBAction)getDataFromServerButtonTapped:(id)sender {
    _numOfRequests = 0;
    [self getDataFromDjinni];
}

- (IBAction)getDataOverTheBridgeButtonTapped:(id)sender {
    if (_templateID == nil) {
        return;
    }

    NSDate *start = [NSDate date];
    LGSTemplate *template = [_coreAPI sendLargeDataOverBridge:_templateID];
    NSLog(@"done: %0.5f", -[start timeIntervalSinceNow]);
}

- (IBAction)generateDataNativelyButtonTapped:(id)sender {
    NSDate *start = [NSDate date];
    LGSTemplate *template = [self generateLargeData];
    NSLog(@"done: %0.5f, template: %@", -[start timeIntervalSinceNow], template.name);
}

- (IBAction)generateDataDjinniButtonTapped:(id)sender {
    NSDate *start = [NSDate date];
    LGSTemplate *template = [_coreAPI generateLargeData];
    NSLog(@"done: %0.5f, template: %@", -[start timeIntervalSinceNow], template.name);
}


- (void)getDataFromDjinni {
    NSDate *start = [NSDate date];
    _templateID = [_coreAPI getData];
    NSLog(@"done: %0.5f with template id: %@", -[start timeIntervalSinceNow], _templateID);
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
    NSMutableArray<LGSPage*> *pages = [[NSMutableArray alloc] init];
    NSArray *_pages = (NSArray *)responseDictionary[@"pages"];

    for (NSDictionary *page in _pages) {
        NSMutableArray<LGSQuestion*> *questions = [[NSMutableArray alloc] init];
        NSArray *_questions = (NSArray *)page[@"questions"];

        for (NSDictionary *question in _questions) {
            [questions addObject:[[LGSQuestion alloc] initWithId:question[@"id"]
                                                          title:question[@"title"]
                                                   responseType:[(NSNumber *)question[@"response_type"] intValue]
                                            questionDescription:question[@"question_description"]
                                                          order:[(NSNumber *)question[@"order"] intValue]]];
        }

        [pages addObject:[[LGSPage alloc] initWithId:page[@"id"]
                                              title:page[@"title"]
                                              order:[(NSNumber *)page[@"order"] intValue]
                                          questions:questions]];
    }

    LGSTemplate *template = [[LGSTemplate alloc] initWithId:responseDictionary[@"id"]
                                                     name:responseDictionary[@"name"]
                                                    pages:pages];
    NSLog(@"%@", template.id);
    _numOfRequests ++;
    if (_numOfRequests == NUMBER_OF_REQUESTS) {
        NSLog(@"done: %0.5f", -[startTime timeIntervalSinceNow]);
    }
}

- (LGSTemplate *)generateLargeData {
    NSUInteger numberOfPages = 50;
    NSUInteger questionsPerPage = 1000;
    NSMutableArray<LGSPage*> *pages = [[NSMutableArray alloc] initWithCapacity:numberOfPages];

    for (NSUInteger page = 1; page <= numberOfPages; page++) {
        NSMutableArray<LGSQuestion*> *questions = [[NSMutableArray alloc] initWithCapacity:questionsPerPage];

        for (NSUInteger question = 1; question <= questionsPerPage; question++) {
            [questions addObject:[[LGSQuestion alloc] initWithId:[NSString stringWithFormat:@"%lu", (unsigned long)question]
                                                           title:[NSString stringWithFormat:@"This is title for question %lu", (unsigned long)question]
                                                    responseType:question
                                             questionDescription:[NSString stringWithFormat:@"This is description for question %lu", (unsigned long)question]
                                                           order:question]];
        }

        [pages addObject:[[LGSPage alloc] initWithId:[NSString stringWithFormat:@"%lu", (unsigned long)page]
                                               title:[NSString stringWithFormat:@"This is title for page %lu", (unsigned long)page]
                                               order:page
                                           questions:questions]];
    }

    return [[LGSTemplate alloc] initWithId:@"template id"
                                      name:@"template name"
                                     pages:pages];
}

@end
