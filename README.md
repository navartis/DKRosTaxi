# DKRosTaxi #

Демонстрационная версия клиента для сервиса Яндекс.Таксометр (Рос.Такси) http://rostaxi.itrf.ru

Эта версия не имеет ограничений ни по функциям ни по возможностям, но при выполнении некоторых методов она отображает уведомление о том, что она демонстрационная.

Для получения полноценной версии пожалуйста свяжитесь с нами по адресу [support@mind-arts.com](mailto:support@mind-arts.com)

# Совместимость #

iOS 8.0+ с ARC

# Документация #

./Documentation/index.html

# Установка #

Добавьте в Xcode проект DKRosTaxiClientDemo.framework

# Конфигурирование #

```
#!objective-c

#import <DKRosTaxiClientDemo/DKRosTaxiClientDemo.h>

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
// Override point for customization after application launch.

    [[DKRTClient sharedInstance] setKey:API_KEY_VALUE];

    return YES;
}
```

# Несколько примеров #

### Запрос списка тарифов ###

```
#!objective-c

[[DKRTClient sharedInstance] getTariffs:^(DKRTTariffsResponse *response, NSError *error) {

}];
```

### Запрос количества водителей online ###

```
#!objective-c

[[DKRTClient sharedInstance] getNumberOfDriversOnline:^(NSNumber *number, NSError *error) {

}];
```

### Запрос СМС кода для регистрации пользователя ###

```
#!objective-c

[[DKRTClient sharedInstance] requestSMSCodeForPhone:@"89123456789" withCompletition:^(BOOL successful, NSError *error) {

}];
```
