//
//  DKRTFavoriteDriversResponseHelper.h
//  DKRosTaxiClient
//
//  Created by Dmitry Kulakov on 2015.12.14.
//  Copyright © 2015 Mind Arts Team. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DKRTResponseHelper.h"
#import "DKRTFavoriteDriverItem.h"

@interface DKRTFavoriteDriversResponseHelper : NSObject

/*!
 * @brief Создание массива избранных водителей
 * @param data JSON data
 * @return Избранные водители в виде массива DKRTFavoriteDriverItem объектов
 */
+ (NSArray *)favoriteDriversItemsByJSONData:(NSData *)data error:(NSError **)error;

@end
