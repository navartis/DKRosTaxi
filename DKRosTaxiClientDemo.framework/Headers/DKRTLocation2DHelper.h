//
//  DKRTLocation2DHelper.h
//  DKRosTaxiClient
//
//  Created by Dmitry Kulakov on 2015.11.30.
//  Copyright © 2015 Mind Arts Team. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

@interface DKRTLocation2DHelper : NSObject

+ (NSString *)locationToLonLatStr:(CLLocationCoordinate2D)location;
+ (NSString *)locationToLonLatStr:(CLLocationCoordinate2D)location usingSeparator:(NSString *)separator;
+ (NSString *)locationDegreesToStr:(CLLocationDegrees)locationDegrees;

@end
