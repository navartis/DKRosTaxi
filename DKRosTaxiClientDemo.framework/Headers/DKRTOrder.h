//
//  DKRTOrder.h
//  DKRosTaxiClient
//
//  Created by Dmitry Kulakov on 2015.12.07.
//  Copyright © 2015 Mind Arts Team. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DKRTOrderPoint.h"

/*!
 Эконом
 */
extern NSString * const DKRTOrderCategoryEconomy;
/*!
 Комфорт
 */
extern NSString * const DKRTOrderCategoryComfort;
/*!
 Бизнес
 */
extern NSString * const DKRTOrderCategoryBusiness;

/*!
 Наличными
 */
extern NSString * const DKRTOrderPaymentCash;
/*!
 Безналичными
 */
extern NSString * const DKRTOrderPaymentcashless;
/*!
 Банковской картой
 */
extern NSString * const DKRTOrderPaymentPlacticCard;

@interface DKRTOrder : NSObject

@property (strong, nonatomic) DKRTOrderPoint *from;
@property (strong, nonatomic) DKRTOrderPoint *to;
@property (strong, nonatomic) NSDate *deadline;
@property (nonatomic) NSTimeInterval deadlineMS;
@property (strong, nonatomic) id driver;
@property (strong, nonatomic) NSString *category;
@property (strong, nonatomic) NSString *payment;
@property (nonatomic) NSInteger svChildChair;
@property (nonatomic) BOOL svAnimalTransport;
@property (nonatomic) BOOL svCheck;
@property (nonatomic) BOOL svUniversal;
@property (strong, nonatomic) NSString *identifier;
@property (strong, nonatomic) id tariff;
@property (strong, nonatomic) id company;
@property (strong, nonatomic) id companyResponsible;
@property (strong, nonatomic) id companyPassenger;
@property (strong, nonatomic) NSString *APIKey;
@property (strong, nonatomic) NSString *comment;
@property (strong, nonatomic) id discount;
@property (strong, nonatomic) NSNumber *cost;

- (instancetype)initWithDictionary:(NSDictionary *)dict;

@end
