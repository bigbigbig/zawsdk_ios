//
//  ZAWLoginModel.h
//  ZAWSDKIOS
//
//  Created by zhangmingsheng on 2024/6/13.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZAWApplePriceModel : NSObject
@property(nonatomic)NSLocale *local;
@property(nonatomic)NSDecimalNumber *price;

+ (instancetype)initWithLocal:(NSLocale *)local price:(NSDecimalNumber *)price;

@end

NS_ASSUME_NONNULL_END
