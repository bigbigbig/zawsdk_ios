//
//  ZAWUserRoleInfo.h
//  ZAWSDKIOS
//
//  Created by zhangmingsheng on 2024/6/13.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZAWUserRoleInfo : NSObject
@property(nonatomic, assign)Boolean result;
@property(nonatomic, strong)NSString *message;
@property(nonatomic, strong)NSString *serverId;
@property(nonatomic, strong)NSString *uid;
@property(nonatomic, strong)NSString *serverName;
@property(nonatomic, strong)NSString *roleId;
@property(nonatomic, strong)NSString *roleName;
@property(nonatomic, strong)NSString *roleLevel;
@property(nonatomic, strong)NSString *appId;
@property(nonatomic, strong)NSString *channelId;
-(NSString *)modelToJSONString;
@end

NS_ASSUME_NONNULL_END
