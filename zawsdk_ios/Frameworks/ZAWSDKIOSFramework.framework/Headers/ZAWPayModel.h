//
//  ZAWPayModel.h
//  ZAWSDKIOS
//
//  Created by zhangmingsheng on 2024/6/13.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZAWPayModel : NSObject
@property(nonatomic, strong)NSString *orderId;
@property(nonatomic, strong)NSString *cpOrderId;
@property(nonatomic, strong)NSString *thirdOrderId;
@property(nonatomic, strong)NSString *purchaseToken;
@property(nonatomic, assign)NSUInteger payMethod;

- (instancetype)initWithPayMethod:(NSUInteger)payMethod
                         orderId:(NSString *)orderId
                       cpOrderId:(NSString *)cpOrderId
                    thirdOrderId:(NSString *)thirdOrderId
                   purchaseToken:(NSString *)purchaseToken;

-(NSString *)modelToJSONString;

@end

NS_ASSUME_NONNULL_END
