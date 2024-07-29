# zawsdk_ios
[![Latest release](https://img.shields.io/github/v/release/bigbigbig/zawsdk_ios)](https://github.com/bigbigbig/zawsdk_ios/releases/latest)


## Example

To run the example project, clone the repo, and run `pod install` from the Example directory first.

## Requirements

## Installation

zawsdk_ios is available through [CocoaPods](https://cocoapods.org). To install
it, simply add the following line to your Podfile:

```ruby
pod 'zawsdk_ios'
```
#### 你必须引入索引库
```ruby
source 'https://cdn.cocoapods.org/'
source 'https://github.com/bigbigbig/mySpecs.git'
```
#### 你必须使用 use_framework!
```ruby
use_frameworks!
```
#### demo
```ruby
platform :ios, '12.0'

source 'https://cdn.cocoapods.org/'
source 'https://github.com/bigbigbig/mySpecs.git'

use_frameworks!
target 'ZAWSDKIOSTestDemo' do
# latest_release 替换为Readme顶部的版本号，不用带字母v
  pod 'zawsdk_ios', '~> latest_release'
  
  post_install do |installer|
    installer.pods_project.targets.each do |target|
      target.build_configurations.each do |config|
        config.build_settings['IPHONEOS_DEPLOYMENT_TARGET'] = '12.0'
      end
    end
  end
end
```
## 使用
#### 引入头文件
```objective-c
#import <ZAWSDKIOSFramework/ZAWSDK.h>
```
#### AppDelegate
```objective-c
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
    [[ZAWSDK sharedInstance]initWithChannel:@"8XXXX" appId:@"XX" appKey:@"XXXXXXXXXX" appleAppId:@"XXXXXXXX" policy_url:@"https://www.baidu.com" agreement_url:@"https://www.baidu.com" af_token:@"XXXXXXXXXX" success:^{
        
    }];
    return YES;
}

- (BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<UIApplicationOpenURLOptionsKey,id> *)options{
    return [[ZAWSDK sharedInstance]application:app openURL:url options:options];
}
```
#### 登录
```objective-c
- (IBAction)login:(id)sender {
    [[ZAWSDK sharedInstance]loginFromViewController:self success:^(ZAWLoginModel * _Nonnull loginModel) {
        NSLog(@"ZAWSDK login:::success:::%@", [loginModel description]);
    } failure:^(NSInteger code, NSString * _Nonnull message) {
        NSLog(@"ZAWSDK login:::failure:::%@", message);
    }];
}
```
#### 快速登录
```objective-c
- (IBAction)quickLogin:(id)sender {
    [[ZAWSDK sharedInstance]quickLoginFromViewController:self success:^(ZAWLoginModel * _Nonnull loginModel) {
        NSLog(@"ZAWSDK quickLogin:::success:::%@", [loginModel description]);
    } failure:^(NSInteger code, NSString * _Nonnull message) {
        NSLog(@"ZAWSDK quickLogin:::failure:::%@", message);
    }];
}
```
#### 绑定
```objective-c
- (IBAction)bind:(id)sender {
    [[ZAWSDK sharedInstance]bindFromViewController:self success:^(ZAWLoginModel * _Nonnull loginModel) {
        NSLog(@"ZAWSDK bind:::success:::%@", [loginModel description]);
    } failure:^(NSInteger code, NSString * _Nonnull message) {
        NSLog(@"ZAWSDK bind:::failure:::%@", message);
    }];
}
```
#### 上报角色信息
```objective-c
- (IBAction)uploadUserInfo:(id)sender {
    [[ZAWSDK sharedInstance]updateRoleInfoWithUid:@"" serverId:@"" serverName:@"" roleId:@"" roleName:@"" roleLevel:@"" success:^(ZAWUserRoleInfo * _Nonnull loginModel) {
        
    } failure:^(NSInteger code, NSString * _Nonnull message) {
        
    }];
}
```
#### 支付
```objective-c
- (IBAction)pay:(id)sender {
    NSString* product_id = @"xxxx.xxxx.xxxx.xxxx";
    NSDate *datenow = [NSDate date];
    NSString *orderId = [NSString stringWithFormat:@"%ld", (long)[datenow timeIntervalSince1970]];
    [[ZAWSDK sharedInstance]payFromViewController:self amount:@"1.0" serverId:@"s1" subject:@"goods" subjectId:product_id isTest:0 cpOrderId:orderId extraInfo:@"extra_info" success:^(ZAWPayModel * _Nonnull payModel) {
            NSLog(@"ZAWSDK pay:::success:::%@", [payModel description]);
        } failure:^(NSInteger code, NSString * _Nonnull message) {
            NSLog(@"ZAWSDK pay:::failure:::%@", message);
        }];
}
```
#### 登出
```objective-c
- (IBAction)logout:(id)sender {
    [[ZAWSDK sharedInstance]logoutOnCompletionHandler:^{
        NSLog(@"ZAWSDK logout:::complete:::");
    }];
}
```
## 配置项目
#### Facebook 配置
右键点击 Info.plist，然后选择 Open As（打开方式）▸ Source Code（源代码）。<br>
将下列 XML 代码片段复制并粘贴到文件正文中 (<dict>...</dict>)。
```xml
<key>CFBundleURLTypes</key>
<array>
  <dict>
  <key>CFBundleURLSchemes</key>
  <array>
    <string>fbAPP-ID</string>
  </array>
  </dict>
</array>
<key>FacebookAppID</key>
<string>APP-ID</string>
<key>FacebookClientToken</key>
<string>CLIENT-TOKEN</string>
<key>FacebookDisplayName</key>
<string>APP-NAME</string>
<key>FacebookAdvertiserIDCollectionEnabled</key>
<true/>
```
在 [CFBundleURLSchemes] 键内的 <array><string> 中，将 APP-ID 替换为您的应用编号。<br>
在 FacebookAppID 键内的 <string> 中，将 APP-ID 替换为您的应用编号。<br>
在 FacebookClientToken 键内的 <string> 中，将 CLIENT-TOKEN 替换为您在应用面板设置 > 高级 > 客户端口令中找到的值。<br>
在 FacebookDisplayName 键内的 <string> 中，将 APP-NAME 替换为您的应用名称。<br>
如要使用任何 Facebook 对话框（如登录、分享、应用邀请等），实现将应用切换至 Facebook 应用的功能，则应用程序的 Info.plist 还需包含以下代码：
```xml
<key>LSApplicationQueriesSchemes</key>
<array>
  <string>fbapi</string>
  <string>fb-messenger-share-api</string>
</array>
```
您可以在 Info.plist 中添加 FacebookAutoLogAppEventsEnabled 作为一个键，以直接将应用事件自动收集功能设为“true”或“false”。<br>
您需为项目添加 Keychain Sharing 功能，才能使登录功能在 Mac Catalyst 应用程序中正常运作。<br>
配置应用目标时，选择 Signing & Capabilities（签名和功能）选项卡中的 + Capability（添加功能）<br>
找到并选择 Keychain Sharing 功能。<br>
确保已将 Keychain Sharing 功能列为应用目标。<br>
#### Google 配置
1、点击下载 GoogleService-Info.plist，获取 Firebase Apple 平台配置文件 (GoogleService-Info.plist)<br>
2、将配置文件移至 Xcode 项目的根目录中<br>
3、打开 GoogleService-Info.plist 配置文件，然后查找 REVERSED_CLIENT_ID 键，复制该键的值<br>
4、打开项目配置：在左侧的树状视图中点击项目名称 > 在Targets中选择您的应用 > 选择info标签页 > 下拉并展开URL Types部分<br>
5、点击 + 按钮 > 在新增栏的 url schemes 中填入上一步获取的值
#### Apple 配置
打开项目配置：在左侧的树状视图中点击项目名称 > 在Targets中选择您的应用 > 选择Signing & Capabilities 标签页 > 点击下方 “+ Capability” 按钮<br>
搜索 iCloud 功能，并勾选，在 Services 中勾选 Key-value storage<br>
搜索 In-App Purchase 功能，并勾选<br>
搜索 Sign in with Apple 功能，并勾选<br>
#### Appsflyer 配置
打开项目配置：在左侧的树状视图中点击项目名称 > 在Targets中选择您的应用 > 选择info标签页<br>
添加 NSAdvertisingAttributionReportEndpoint 键，设置值为 https://appsflyer-skadnetwork.com/.
#### 项目其它配置
1、打开项目配置：在左侧的树状视图中点击项目名称 > 在Targets中选择您的应用 > 选择Build Settings标签页<br>
在 Build Options 选项中 将 User Script Sandboxing 设置为 No<br>
2、打开项目配置：在左侧的树状视图中点击项目名称 > 在Targets中选择您的应用 > 选择info标签页<br>
添加用户追踪声明键值
```
<key>NSUserTrackingUsageDescription</key>
<string>This identifier will be used to deliver personalized ads to you.</string>
```
添加网络访问声明键值
```
<key>NSAppTransportSecurity</key>
<dict>
    <key>NSAllowsArbitraryLoads</key>
    <true/>
</dict>
```
## Author

Mingsheng Zhang, 1046724509@qq.com

## License

zawsdk_ios is available under the MIT license. See the LICENSE file for more info.
