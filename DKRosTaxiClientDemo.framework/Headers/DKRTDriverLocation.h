//
//  #import <DKRosTaxiClient/>
//  DKRosTaxiClient
//
//  Created by Dmitry Kulakov on 2015.11.30.
//  Copyright © 2015 Mind Arts Team. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

@interface DKRTDriverLocation : NSObject

@property (strong, nonatomic) NSString *identifier;
@property (nonatomic) CLLocationCoordinate2D location;
@property (nonatomic) double distance;

- (instancetype)initWithDictionary:(NSDictionary *)dict;

@end
