//
//  DKRTOrderStatusResponse.h
//  DKRosTaxiClient
//
//  Created by Dmitry Kulakov on 2015.12.04.
//  Copyright © 2015 Mind Arts Team. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DKRTResponseHelper.h"

typedef enum {
    DKRTOrderStatusCreated = 0, // заказ создан
    DKRTOrderStatusSearchingDriver = 1, // поиск водителя
    DKRTOrderStatusDriverDrivingToClient = 2, // водитель выдвигается к клиенту
    DKRTOrderStatusDriverArrivedToClient = 3, // водитель ожидает клиента по адресу
    DKRTOrderStatusOperatorCallingClient = 4, // диспетчер позвонил клиенту
    DKRTOrderStatusDriverCarriesClient = 5, // водитель везет клиента
    DKRTOrderStatusCanceled = 6, // заказ отменен
    DKRTOrderStatusFinished = 7, // заказ завершен
    DKRTOrderStatusDriverNotFoundByTimeout = 9, // водитель по заказу не найден в течении длительного времени
    DKRTOrderStatusUnknown = 999
} DKRTOrderStatus;

@interface DKRTOrderStatusResponse : NSObject

@property (nonatomic) DKRTOrderStatus status;
@property (strong, nonatomic) NSString *driverId;
@property (strong, nonatomic) NSString *db;
@property (strong, nonatomic) NSString *comment;
@property (strong, nonatomic) NSString *sum;

- (instancetype)initWithJSONData:(NSData *)data error:(NSError **)error;

@end
