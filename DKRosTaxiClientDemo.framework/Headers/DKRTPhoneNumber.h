//
//  DKRTPhoneNumber.h
//  DKRosTaxiClient
//
//  Created by Dmitry Kulakov on 2015.12.11.
//  Copyright © 2015 Mind Arts Team. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface DKRTPhoneNumber : NSObject

@property (strong, nonatomic) NSString *number;
@property (strong, nonatomic) NSNumber *type;

- (instancetype)initWithDictionary:(NSDictionary *)dict;

@end
