//
//  DKRTOrderPoint.h
//  DKRosTaxiClient
//
//  Created by Dmitry Kulakov on 2015.12.07.
//  Copyright © 2015 Mind Arts Team. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

@interface DKRTOrderPoint : NSObject

@property (strong, nonatomic) NSString *address;
@property (strong, nonatomic) id house;
@property (strong, nonatomic) NSString *comment;
@property (nonatomic) CLLocationCoordinate2D location;

- (instancetype)initWithDictionary:(NSDictionary *)dict;

@end
