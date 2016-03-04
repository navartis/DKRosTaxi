//
//  DKRTPOIsResponseHelper.h
//  DKRosTaxiClient
//
//  Created by Dmitry Kulakov on 2015.12.09.
//  Copyright © 2015 Mind Arts Team. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DKRTResponseHelper.h"
#import "DKRTPOI.h"

@interface DKRTPOIsResponseHelper : NSObject

+ (NSArray *)pointsByJSONData:(NSData *)data error:(NSError **)error;

@end
