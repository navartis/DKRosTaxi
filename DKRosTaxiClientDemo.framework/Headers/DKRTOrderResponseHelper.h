//
//  DKRTOrderResponseHelper.h
//  DKRosTaxiClient
//
//  Created by Dmitry Kulakov on 2015.12.03.
//  Copyright © 2015 Mind Arts Team. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DKRTResponseHelper.h"

@interface DKRTOrderResponseHelper : NSObject

+ (NSString *)orderIdByJSONData:(NSData *)data error:(NSError **)error;

@end
