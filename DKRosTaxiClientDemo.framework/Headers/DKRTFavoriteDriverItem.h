//
//  DKRTFavoriteDriverItem.h
//  DKRosTaxiClient
//
//  Created by Dmitry Kulakov on 2015.12.14.
//  Copyright © 2015 Mind Arts Team. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DKRTDriver.h"

@interface DKRTFavoriteDriverItem : NSObject

@property (nonatomic) NSInteger key;
/// Массив DKRTDriver объектов
@property (strong, nonatomic) NSArray *items;

- (instancetype)initWithDictionary:(NSDictionary *)dict;

@end
