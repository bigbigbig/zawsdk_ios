//
//  ZAWLoginModel.h
//  ZAWSDKIOS
//
//  Created by zhangmingsheng on 2024/6/13.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZAWLoginModel : NSObject
@property(nonatomic, strong)NSString * uid;
@property(nonatomic, strong)NSString * token;

-(instancetype)initWithUid:(NSString *)uid token:(NSString *)token;
-(NSString *)modelToJSONString;
@end

NS_ASSUME_NONNULL_END
