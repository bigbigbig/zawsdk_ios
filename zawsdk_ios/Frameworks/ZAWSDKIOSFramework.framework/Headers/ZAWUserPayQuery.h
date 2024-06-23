//
//  ZAWUserPayQuery.h
//  ZAWSDKIOS
//
//  Created by zhangmingsheng on 2024/6/13.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZAWUserPayQuery : NSObject
@property(nonatomic, assign, readonly)Boolean result;
@property(nonatomic, strong, readonly)NSString *message;
@property(nonatomic, strong, readonly)NSString *orderId;
@property(nonatomic, assign, readonly)NSUInteger status;// 1-未支付，2-支付成功，3-支付失败
@end

NS_ASSUME_NONNULL_END
