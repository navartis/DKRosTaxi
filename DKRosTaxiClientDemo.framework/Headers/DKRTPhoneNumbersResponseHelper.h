//
//  DKRTPhoneNumbersResponseHelper.h
//  DKRosTaxiClient
//
//  Created by Dmitry Kulakov on 2015.12.11.
//  Copyright © 2015 Mind Arts Team. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DKRTResponseHelper.h"
#import "DKRTPhoneNumber.h"

@interface DKRTPhoneNumbersResponseHelper : NSObject

+ (NSArray *)phoneNumbersByJSONData:(NSData *)data error:(NSError **)error;

@end
