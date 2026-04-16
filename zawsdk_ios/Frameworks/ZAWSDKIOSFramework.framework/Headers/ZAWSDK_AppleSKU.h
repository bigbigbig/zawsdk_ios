//
//  ZAWSDK_AppleSKU.h
//  ZAWSDKIOS
//
//  Created by zhangmingsheng on 2026/3/31.
//

#import <Foundation/Foundation.h>
#import "ZAWApplePriceModel.h"

NS_ASSUME_NONNULL_BEGIN
@interface ZAWSDK_AppleSKU : NSObject
+ (instancetype)sharedInstance;
- (void)fetchProductInfo:(NSArray *)ids
                 success:(nonnull void (^)(NSDictionary<NSString *, ZAWApplePriceModel *>* dic))success
                 failure:(nonnull void (^)(NSInteger code, NSString *message))failure;
@end

NS_ASSUME_NONNULL_END
