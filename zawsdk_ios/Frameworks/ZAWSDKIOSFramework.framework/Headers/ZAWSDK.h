//
//  ZAWSDK.h
//  ZAWSDKIOS
//
//  Created by zhangmingsheng on 2024/6/12.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "ZAWLoginModel.h"
#import "ZAWUserRoleInfo.h"
#import "ZAWPayModel.h"
#import "ZAWUserPayQuery.h"

/*
 #import <ZAWSDKIOSFramework/ZAWLoginModel.h>
 #import <ZAWSDKIOSFramework/ZAWUserRoleInfo.h>
 #import <ZAWSDKIOSFramework/ZAWPayModel.h>
 #import <ZAWSDKIOSFramework/ZAWUserPayQuery.h>*/

#ifdef __cplusplus
#define ZAWSDK_EXTERN        extern "C" __attribute__((visibility ("default")))
#else
#define ZAWSDK_EXTERN        extern __attribute__((visibility ("default")))
#endif

NS_ASSUME_NONNULL_BEGIN

@protocol ZAWSDKDelegate <NSObject>

- (void)sdkDidLoad;
- (void)userDidLogin:(ZAWLoginModel *)loginModel;
- (void)userDidBind:(ZAWLoginModel *)loginModel;
- (void)userDidLogout;
- (void)userDidUpdateRoleInfo:(ZAWUserRoleInfo *)roleInfo;
- (void)userPayResult:(ZAWPayModel *)payModel;

@end

typedef NS_ENUM(NSUInteger, ZAWLoginType) {
    ZAWLoginTypeFastLogin = 0,
    ZAWLoginTypeFacebook = 1,
    ZAWLoginTypeGoogle,
    ZAWLoginTypeApple,
    ZAWLoginTypeGuest,
    ZAWLoginTypeAccount = 6,
    ZAWLoginTypeVK = 7,
};

typedef NS_ENUM(NSUInteger, ZAWLoginWay) {
    ZAWLoginWayLogin = 0,
    ZAWLoginWayBind
};

@class ZAWUserLoginMessage;

@interface ZAWSDK : NSObject

@property(nonatomic, weak)id<ZAWSDKDelegate> delegate;

+ (instancetype)sharedInstance;

// 初始化SDK
- (void)initWithChannel:(NSString *)channel
                  appId:(NSString *)appId
                 appKey:(NSString *)appKey
             appleAppId:(NSString *)appleAppId
             policy_url:(NSString *)policy_url
          agreement_url:(NSString *)agreement_url
               ad_token:(NSString *)ad_token
                success:(nullable void (^)(void))completionHandler;

- (BOOL)application:(UIApplication*)application openURL:(NSURL *)url options:(nonnull NSDictionary<UIApplicationOpenURLOptionsKey,id> *)options;

// 登录
- (void)loginGuestSuccess:(void (^)(ZAWLoginModel *))success
                  failure:(void (^)(NSInteger, NSString *))failure;

- (void)quickLoginFromViewController:(UIViewController *)viewController
                             success:(nullable void (^)(ZAWLoginModel *loginModel))success
                             failure:(nullable void (^)(NSInteger code, NSString *message))failure;

- (void)loginFromViewController:(UIViewController *)viewController
                             success:(void (^)(ZAWLoginModel *))success
                             failure:(void (^)(NSInteger, NSString *))failure;

- (void)accountFromViewController:(UIViewController *)viewController
                        switchTap:(void (^)(void))switchTap
                          success:(void (^)(ZAWLoginModel *))success
                          failure:(void (^)(NSInteger, NSString *))failure;

- (void)logoutOnCompletionHandler:(nullable void (^)(void))completionHandler;

// 绑定
- (void)bindFromViewController:(UIViewController *)viewController
                       success:(nullable void (^)(ZAWLoginModel *loginModel))success
                       failure:(nullable void (^)(NSInteger code, NSString *message))failure;

// 上报用户角色信息
- (void)updateRoleInfoWithServerId:(NSString *)serverId
                   serverName:(NSString *)serverName
                       roleId:(NSString *)roleId
                     roleName:(NSString *)roleName
                    roleLevel:(NSString *)roleLevel
                      success:(nullable void (^)(ZAWUserRoleInfo *loginModel))success
                      failure:(nullable void (^)(NSInteger code, NSString *message))failure;

// 支付
- (void)payFromViewController:(UIViewController *)viewController
                       amount:(NSString *)amount
                     serverId:(NSString *)serverId
                      subject:(NSString *)subject
                    subjectId:(NSString *)subjectId
                       isTest:(NSInteger)isTest
                    cpOrderId:(NSString *)cpOrderId
                    extraInfo:(NSString *)extra_info
                      success:(nullable void (^)(ZAWPayModel *payModel))success
                      failure:(nullable void (^)(NSInteger code, NSString *message, NSString *cpOrderId))failure;

// 支付结果查询
- (void)queryPayWithOrderId:(NSString *)orderId
              transactionId:(NSString *_Nonnull)transactionId
                     billNo:(NSString *)billNo
                    success:(nullable void (^)(ZAWUserPayQuery *payModel))success
                    failure:(nullable void (^)(NSInteger code, NSString *message))failure;

//删除账号
- (void)deleteAccount;

// 原生上报
- (void)adLogEventWithEventToken:(NSString *)eventToken;

- (void)firebaseLogEventWithName:(NSString *)eventName
                          values:(NSDictionary *)eventValues;


//分享
- (void)shareLinkToFacebook:(NSString *)link
                      quote:(NSString *)quote
         fromViewController:(UIViewController *)viewController;

- (void)saveLoginInfo:(ZAWUserLoginMessage *)message;

- (NSString *)getUid;
- (NSString *)getUserLoginToken;
- (NSString *)getUserLoginTime;
- (NSString *)getChannel;
- (NSString *)getAppId;
- (NSString *)getAppKey;
- (NSString *)getPolicyUrl;
- (NSString *)getAgreementUrl;
+ (NSInteger)getLastLoginType;
+ (NSInteger)getLastBindType;

@end

// SDK初始化结果通知
ZAWSDK_EXTERN NSString* const ZAWSDKDidLoadEvent;
// 登录结果通知
ZAWSDK_EXTERN NSString* const ZAWSDKLoginResultEvent;
// 绑定结果通知
ZAWSDK_EXTERN NSString* const ZAWSDKBindResultEvent;
// 登出结果通知
ZAWSDK_EXTERN NSString* const ZAWSDKLogoutEvent;
// 上报角色信息结果通知
ZAWSDK_EXTERN NSString* const ZAWSDKRoleInfoResultEvent;
// 订单结果通知
ZAWSDK_EXTERN NSString* const ZAWSDKPayResultEvent;

NS_ASSUME_NONNULL_END
