//
//  DKRTDriver.h
//  DKRosTaxiClient
//
//  Created by Dmitry Kulakov on 2015.11.30.
//  Copyright © 2015 Mind Arts Team. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "DKRTResponseHelper.h"

@interface DKRTDriver : NSObject

@property (nonatomic) NSInteger like;
@property (strong, nonatomic) NSString *name;
@property (strong, nonatomic) NSString *company;
@property (strong, nonatomic) NSString *car;
@property (strong, nonatomic) NSString *color;
@property (nonatomic) NSInteger year;
@property (strong, nonatomic) NSString *identifier;
@property (nonatomic) CLLocationCoordinate2D location;
@property (nonatomic) NSInteger distance;
@property (nonatomic) BOOL photos;
@property (nonatomic) NSInteger status;
@property (strong, nonatomic) NSString *carnumber;

- (instancetype)initWithDictionary:(NSDictionary *)dict;
- (instancetype)initWithJSONData:(NSData *)data error:(NSError **)error;

@end
