//
//  DKRTResponseHelper.h
//  DKRosTaxiClient
//
//  Created by Dmitry Kulakov on 2015.12.08.
//  Copyright © 2015 Mind Arts Team. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface DKRTResponseHelper : NSObject

+ (NSArray *)arrayWithJSONData:(NSData *)data error:(NSError **)error;
+ (NSDictionary *)dictWithJSONData:(NSData *)data error:(NSError **)error;
+ (id)cleanJSONObj:(id)JSONObj;

@end
