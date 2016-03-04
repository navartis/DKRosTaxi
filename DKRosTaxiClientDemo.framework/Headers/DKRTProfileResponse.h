//
//  DKRTProfileResponse.h
//  DKRosTaxiClient
//
//  Created by Dmitry Kulakov on 2015.12.07.
//  Copyright © 2015 Mind Arts Team. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DKRTResponseHelper.h"

@interface DKRTProfileResponse : NSObject

@property (strong, nonatomic) NSString *phone;
@property (strong, nonatomic) NSString *name;
@property (strong, nonatomic) NSString *email;

- (instancetype)initWithJSONData:(NSData *)data error:(NSError **)error;

@end
