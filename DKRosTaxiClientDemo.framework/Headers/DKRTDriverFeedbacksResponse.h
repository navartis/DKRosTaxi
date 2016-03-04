//
//  DKRTDriverFeedbacksResponse.h
//  DKRosTaxiClient
//
//  Created by Dmitry Kulakov on 2015.12.01.
//  Copyright © 2015 Mind Arts Team. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DKRTDriverFeedback.h"
#import "DKRTResponseHelper.h"

@interface DKRTDriverFeedbacksResponse : NSObject

/// Collection of DKRTDriverFeedback instaces
@property (strong, nonatomic) NSArray *feedbacks;
- (instancetype)initWithJSONData:(NSData *)data error:(NSError **)error;

@end
