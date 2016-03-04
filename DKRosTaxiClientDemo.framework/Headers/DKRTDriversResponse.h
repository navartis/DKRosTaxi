//
//  DKRTDriversResponse.h
//  DKRosTaxiClient
//
//  Created by Dmitry Kulakov on 2015.11.30.
//  Copyright © 2015 Mind Arts Team. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DKRTDriver.h"

@interface DKRTDriversResponse : NSObject

/// Collection of DKRTDriver instaces
@property (strong, nonatomic) NSArray *drivers;
- (instancetype)initWithJSONData:(NSData *)data error:(NSError **)error;

@end
