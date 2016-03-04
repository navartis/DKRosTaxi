//
//  DKRTTariff.h
//  DKRosTaxiClient
//
//  Created by Dmitry Kulakov on 2015.11.26.
//  Copyright © 2015 Mind Arts Team. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface DKRTTariff : NSObject

@property (strong, nonatomic) NSString *name;
@property (strong, nonatomic) NSString *category;
@property (strong, nonatomic) NSString *shortName;
@property (strong, nonatomic) NSString *desc;
@property (strong, nonatomic) NSString *workType;
@property (nonatomic) NSInteger workStart;
@property (nonatomic) NSInteger workEnd;
/// Collection of NSString instances
@property (strong, nonatomic) NSArray *days;
@property (strong, nonatomic) NSNumber *minimumAmount;
@property (strong, nonatomic) NSNumber *limitTime;
@property (strong, nonatomic) NSNumber *limitDistance;
@property (strong, nonatomic) NSNumber *waitingFree;
@property (strong, nonatomic) NSNumber *waitingPay;
@property (strong, nonatomic) NSNumber *compensation;
@property (strong, nonatomic) NSNumber *waitingPayInWay;
@property (strong, nonatomic) NSNumber *limitTimeAirport;
@property (strong, nonatomic) NSNumber *waitingAirport;
@property (strong, nonatomic) NSNumber *waitingToAirport;
/// Collection of NSDictionary instances
@property (strong, nonatomic) NSDictionary *counters;
@property (strong, nonatomic) NSDictionary *zones;
@property (strong, nonatomic) id services;

- (instancetype)initWithDictionary:(NSDictionary *)dict;


@end
