//
//  DKRTTariffsResponse.h
//  DKRosTaxiClient
//
//  Created by Dmitry Kulakov on 2015.11.27.
//  Copyright © 2015 Mind Arts Team. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DKRTTariff.h"
#import "DKRTResponseHelper.h"

@interface DKRTTariffsResponse : NSObject

/// Collection of DKRTTariff instaces
@property (strong, nonatomic) NSArray *tariffs;
- (instancetype)initWithJSONData:(NSData *)data error:(NSError **)error;

@end
