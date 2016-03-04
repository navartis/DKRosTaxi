//
//  DKRTDriversLocationsResponse.h
//  DKRosTaxiClient
//
//  Created by Dmitry Kulakov on 2015.11.30.
//  Copyright © 2015 Mind Arts Team. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DKRTDriverLocation.h"
#import "DKRTResponseHelper.h"

@interface DKRTDriversLocationsResponse : NSObject

/// Collection of DKRTDriverLocation instaces
@property (strong, nonatomic) NSArray *locations;
- (instancetype)initWithJSONData:(NSData *)data error:(NSError **)error;

@end
