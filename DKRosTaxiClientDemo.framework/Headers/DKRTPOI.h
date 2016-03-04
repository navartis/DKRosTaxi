//
//  DKRTPOI.h
//  DKRosTaxiClient
//
//  Created by Dmitry Kulakov on 2015.12.09.
//  Copyright © 2015 Mind Arts Team. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

@interface DKRTPOI : NSObject

@property (strong, nonatomic) NSString *address;
@property (nonatomic) CLLocationCoordinate2D location;

- (instancetype)initWithDictionary:(NSDictionary *)dict;

@end
