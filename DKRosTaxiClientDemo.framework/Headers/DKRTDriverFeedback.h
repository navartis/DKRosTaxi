//
//  DKRTDriverFeedback.h
//  DKRosTaxiClient
//
//  Created by Dmitry Kulakov on 2015.12.01.
//  Copyright © 2015 Mind Arts Team. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface DKRTDriverFeedback : NSObject

@property (strong, nonatomic) NSDate *date;
@property (strong, nonatomic) NSString *comment;

- (instancetype)initWithDictionary:(NSDictionary *)dict;
+ (NSTimeInterval)timeIntervalFromDateStringParam:(NSString *)dateString;

@end
