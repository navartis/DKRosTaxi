//
//  DKRTOrdersHistoryResponseHelper.h
//  DKRosTaxiClient
//
//  Created by Dmitry Kulakov on 2015.12.08.
//  Copyright © 2015 Mind Arts Team. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DKRTResponseHelper.h"
#import "DKRTOrder.h"

@interface DKRTOrdersHistoryResponseHelper : NSObject

+ (NSArray *)ordersByJSONData:(NSData *)data error:(NSError **)error;

@end
