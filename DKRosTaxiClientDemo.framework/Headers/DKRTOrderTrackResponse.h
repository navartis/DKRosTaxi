//
//  DKRTOrderTrackResponse.h
//  DKRosTaxiClient
//
//  Created by Dmitry Kulakov on 2015.12.08.
//  Copyright © 2015 Mind Arts Team. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "DKRTResponseHelper.h"
#import "DKRTOrder.h"

@interface DKRTOrderTrackResponse : NSObject

@property (strong, nonatomic) DKRTOrder *order;
/// Массив CLLocation объектов
@property (strong, nonatomic) NSArray *track;

- (instancetype)initWithJSONData:(NSData *)data error:(NSError **)error;

@end
