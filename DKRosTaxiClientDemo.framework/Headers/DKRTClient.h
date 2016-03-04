//
//  DKRTClient.h
//  DKRosTaxiClient
//
//  Created by DMITRY KULAKOV on 03.03.16.
//  Copyright © 2016 Mind Arts Team. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DKRTTariffsResponse.h"
#import "DKRTLocation2DHelper.h"
#import "DKRTDriversResponse.h"
#import "DKRTDriversLocationsResponse.h"
#import "DKRTDriverFeedbacksResponse.h"
#import "DKRTProfileResponse.h"
#import "DKRTOrderTrackResponse.h"
#import "DKRTOrderStatusResponse.h"
#import "DKRTPhoneNumber.h"
#import "DKRTPOI.h"

/*!
 URL для доступа к API по умолчанию
 */
extern NSString * const DKRT_DEFAULT_BASE_URL;

/*!
 Таймаут на выполнение сетевых операций по умолчанию
 */
extern NSTimeInterval const DKRT_DEFAULT_TIMEOUT_INTERVAL;

/*!
 Домен для ошибок, возвращаемых клиентом
 */
extern NSString * const DKRT_ERRORS_DOMAIN;

/*!
 Ключ для получения кода HTTP ответа в error.userInfo в случае ошибки DKRTClientHTTPStatusNotOKError
 */
extern NSString * const DKRT_HTTP_STATUS;

/*!
 Ошибки, возвращаемые клиентом
 */
typedef enum {
    /*!
     Если код ответа HTTP не 200. В данном случае код ответа можно найти в error.userInfo по ключу DKRT_HTTP_STATUS.
     */
    DKRTClientHTTPStatusNotOKError,
    /*!
     Если бэкенд вернул ответ, который невозможно никак интерпретировать.
     */
    DKRTClientWrongResponseFormatError
} DKRTClientError;

// ORDER Mandatory
/*!
 @discussion Дата и время подачи в миллисекундах от 01.01.1970
 Возможные значения:
 DKRTOrderDeadline10Min
 DKRTOrderDeadline15Min
 DKRTOrderDeadline20Min
 DKRTOrderDeadline25Min
 DKRTOrderDeadline30Min
 Любое другое значение представляет собой дату Например 1415491200 = 11.09.2014 00:00:00
 для Android = System.currentTimeMillis()
 @const
 */
extern NSString * const kDKRTOrderDeadline;

/*!
 Подача за 10 минут
 */
extern NSString * const DKRTOrderDeadline10Min;
/*!
 Подача за 15 минут
 */
extern NSString * const DKRTOrderDeadline15Min;
/*!
 Подача за 20 минут
 */
extern NSString * const DKRTOrderDeadline20Min;
/*!
 Подача за 25 минут
 */
extern NSString * const DKRTOrderDeadline25Min;
/*!
 Подача за 30 минут
 */
extern NSString * const DKRTOrderDeadline30Min;

/*!
 @discussion Категория
 Возможные значения:
 DKRTOrderCategoryEconomy
 DKRTOrderCategoryComfort
 DKRTOrderCategoryBusiness
 @const
 */
extern NSString * const kDKRTOrderCategory;

/*!
 @discussion Тип оплаты
 Возможные значения:
 DKRTOrderPaymentCash
 DKRTOrderPaymentcashless
 DKRTOrderPaymentPlacticCard
 @const
 */
extern NSString * const kDKRTOrderPayment;
extern NSString * const kDKRTOrderFromAddress;
extern NSString * const kDKRTOrderFromLat;
extern NSString * const kDKRTOrderFromLon;
extern NSString * const kDKRTOrderFromComment;
extern NSString * const kDKRTOrderToAddress;
// ORDER Optional
extern NSString * const kDKRTOrderToLat;
extern NSString * const kDKRTOrderToLon;
extern NSString * const kDKRTOrderToComment;
extern NSString * const kDKRTOrderSVCheck;
extern NSString * const kDKRTOrderSVUniversal;
extern NSString * const kDKRTOrderSVAnimalTransport;
extern NSString * const kDKRTOrderSVChildChair;
extern NSString * const kDKRTOrderDriver;

// Boolean Values
extern NSString * const DKRTOrderTrue;
extern NSString * const DKRTOrderFalse;

typedef enum {
    DKRTOrderFeedbackMarkDislike = 0,
    DKRTOrderFeedbackMarkLike = 1
} DKRTOrderFeedbackMark;

@interface DKRTClient : NSObject

@property (strong, nonatomic) NSString *baseURL;
@property (nonatomic) NSTimeInterval requestTimeoutInterval;
@property (strong, nonatomic) NSString *key;
@property (nonatomic, strong) dispatch_queue_t completionsQueue;

- (instancetype) init __attribute__((unavailable("init not available")));
+ (instancetype)sharedInstance;
+ (void)destruct;

#pragma mark - Запросы синхронизации данных

/*!
 * @brief Запрос списка тарифов
 * @return Тарифы
 * @link GET /tariff/json
 */
- (void)getTariffs:(void (^)(DKRTTariffsResponse *response, NSError *error))completion;

/*!
 * @brief Запрос количества водителей online
 * @return Количество водителей
 * @link GET /online
 */
- (void)getNumberOfDriversOnline:(void (^)(NSNumber *number, NSError *error))completion;

/*!
 * @brief Запрос списка аэропортов
 * @param location Координаты поиска
 * @return Аэропорты в виде массива DKRTPOI объектов
 * @link GET /airport
 */
- (void)getAirportsByLocation:(CLLocationCoordinate2D)location
             withCompletition:(void (^)(NSArray *airports, NSError *error))completion;

/*!
 * @brief Запрос списка вокзалов
 * @param location Координаты поиска
 * @return Вокзалы в виде массива DKRTPOI объектов
 * @link GET /train
 */
- (void)getRailwayStationsByLocation:(CLLocationCoordinate2D)location
                    withCompletition:(void (^)(NSArray *stations, NSError *error))completion;

/*!
 * @brief Запрос профилей водителей
 * @param location Координата ограничивающая поиск в радиусе
 * @param radius Радиус поиска
 * @return Профили водителей
 * @link GET /drivers
 */
- (void)getDriversByLocation:(CLLocationCoordinate2D)location
                    inRadius:(double)radius
            withCompletition:(void (^)(DKRTDriversResponse *response, NSError *error))completion;

/*!
 * @brief Запрос одного профиля водителя
 * @param identifier Уникальный номер водителя
 * @return Профиль водителя
 * @link GET /driver
 */
- (void)getDriverByIdentifier:(NSString *)identifier
             withCompletition:(void (^)(DKRTDriver *driver, NSError *error))completion;

/*!
 * @brief Запрос GPS водителей
 * @param location Координата ограничивающая поиск в радиусе
 * @param radius Радиус поиска
 * @return Позиции водителей
 * @link GET /drivers-gps
 */
- (void)getDriversLocationsByLocation:(CLLocationCoordinate2D)location
                             inRadius:(double)radius
                     withCompletition:(void (^)(DKRTDriversLocationsResponse *response, NSError *error))completion;

/*!
 * @brief Запрос GPS одного водителя
 * @param driverId Уникальный номер водителя
 * @return Координаты водителя
 * @link GET /gps
 */
- (void)getDriverLocationByDriverId:(NSString *)driverId
                   withCompletition:(void (^)(CLLocationCoordinate2D location, NSError *error))completion;

/*!
 * @brief Запрос отзывов водителя
 * @param identifier Уникальный номер водителя
 * @return Отзывы водителя
 * @link GET /feedback
 */
- (void)getFeedbacksByDriverIdentifier:(NSString *)identifier
                      withCompletition:(void (^)(DKRTDriverFeedbacksResponse *response, NSError *error))completion;

#pragma mark - Запросы обработки клиентов

/*!
 * @brief Запрос авторизации учетной записи. В результате выполнения запроса, на указанный телефонный номер будет отправлено СМС с кодом для подтверждения регистрации.
 * @param phone Номер телефона, например 79267003311
 * @link GET /profile/login
 */
- (void)requestSMSCodeForPhone:(NSString *)phone
              withCompletition:(void (^)(BOOL successful, NSError *error))completion;


/*!
 * @brief Запрос подтверждения авторизации учетной записи. В результате выполнения запроса, будет сгенерирован уникальный ключ клиента (profileId), его необходимо хранить тк он используется для дальнейших запросов.
 * @param phone Номер телефона, например 79267003311
 * @param code PIN код высланный по СМС на телефонный номер
 * @return Уникальный ключ клиента
 * @link GET /profile/registration
 */
- (void)signUpByPhone:(NSString *)phone andSMSCode:(NSString *)code
     withCompletition:(void (^)(NSString *identifier, NSError *error))completion;

/*!
 * @brief Запрос данных учетной записи
 * @param clientId Уникальный ключ клиента
 * @return Данные учетной записи
 * @link GET /profile/get
 */
- (void)getClientProfileByClientId:(NSString *)clientId
                  withCompletition:(void (^)(DKRTProfileResponse *response, NSError *error))completion;

/*!
 * @brief Запрос сохранения данных учетной записи
 * @param clientId Уникальный ключ клиента
 * @param name Имя клиента
 * @param email E-mail клиента
 * @link POST /profile/set
 */
- (void)setClientProfileByClientId:(NSString *)clientId name:(NSString *)name email:(NSString *)email
                  withCompletition:(void (^)(BOOL successful, NSError *error))completion;

/*!
 * @brief Запрос истории заказов
 * @param clientId Уникальный ключ клиента
 * @return Заказы в виде массива DKRTOrder объектов
 * @link GET /profile/history
 */
- (void)getOrdersHistoryByClientId:(NSString *)clientId
                  withCompletition:(void (^)(NSArray *orders, NSError *error))completion;

/*!
 * @brief Запрос GPS трека заказа
 * @param clientId Уникальный ключ клиента
 * @param orderId Уникальный ключ заказа
 * @return DKRTOrderTrackResponse
 * @link GET /profile/order-info-track
 */
- (void)getOrderTrackByClientId:(NSString *)clientId orderId:(NSString *)orderId
               withCompletition:(void (^)(DKRTOrderTrackResponse *response, NSError *error))completion;

/*!
 * @brief Запрос списка избранных водителей
 * @param clientId Уникальный ключ клиента
 * @return Заказы в виде массива DKRTFavoriteDriverItem объектов
 * @link GET /profile/favorites
 */
- (void)getFavoriteDrivesByClientId:(NSString *)clientId
                   withCompletition:(void (^)(NSArray *drivers, NSError *error))completion;

/*!
 * @brief Запрос добавления в избранных водителей
 * @param driverId Уникальный ключ водителя
 * @param clientId Уникальный ключ клиента
 * @link GET /profile/add-favorites
 */
- (void)addDriverAsFavorite:(NSString *)driverId forClientId:(NSString *)clientId
           withCompletition:(void (^)(BOOL successful, NSError *error))completion;

/*!
 * @brief Запрос удаления из избранных водителей
 * @param driverId Уникальный ключ водителя
 * @param clientId Уникальный ключ клиента
 * @link GET /profile/remove-favorites
 */
- (void)removeDriverFromFavorites:(NSString *)driverId forClientId:(NSString *)clientId
                 withCompletition:(void (^)(BOOL successful, NSError *error))completion;

#pragma mark - Запросы обработки заказов

/*!
 * @brief Добавление заказа.
 * @param clientId Уникальный ключ клиента
 * @param orderParams Параметры заказа
 * @return Уникальный ключ заказа
 * @link GET /request/order
 */
- (void)makeOrderByClientId:(NSString *)clientId andOrderParams:(NSDictionary *)orderParams
           withCompletition:(void (^)(NSString *identifier, NSError *error))completion;

/*!
 * @brief Текущий статус заказа
 * @param identifier Уникальный ключ заказа
 * @link GET /request/status
 */
- (void)getOrderStatusById:(NSString *)identifier
          withCompletition:(void (^)(DKRTOrderStatusResponse *response, NSError *error))completion;

/*!
 * @brief Отмена заказа
 * @param identifier Уникальный ключ заказа
 * @link GET /request/cancel
 */
- (void)cancelOrderById:(NSString *)identifier
       withCompletition:(void (^)(BOOL successful, NSError *error))completion;

/*!
 * @brief Текущие координаты GPS водителя
 * @warning Данный запрос необходимо запрашивать не чаще чем 7 - 10 секунд
 * @param orderId Уникальный номер заказа
 * @return Координаты водителя
 * @link GET /request/gps
 */
- (void)getDriverLocationByOrderId:(NSString *)orderId
                  withCompletition:(void (^)(CLLocationCoordinate2D location, NSError *error))completion;

/*!
 * @brief Список доступных телефонов для звонка
 * @param orderId Уникальный номер заказа
 * @return Номера телефонов в виде массива DKRTPhoneNumber объектов
 * @link GET /request/phones
 */
- (void)getPhoneNumbersByOrderId:(NSString *)orderId
                withCompletition:(void (^)(NSArray *phoneNumbers, NSError *error))completion;

/*!
 * @brief Оставить отзыв к заказу
 * @param identifier Уникальный номер заказа
 * @param comment Комментарий к заказу
 * @param mark Оценка клиента (DKRTOrderFeedbackMarkDislike, DKRTOrderFeedbackMarkLike)
 * @link GET /request/feeadback
 */
- (void)postFeedbackForOrderById:(NSString *)identifier comment:(NSString *)comment andMark:(DKRTOrderFeedbackMark)mark
                withCompletition:(void (^)(BOOL successful, NSError *error))completion;

@end
