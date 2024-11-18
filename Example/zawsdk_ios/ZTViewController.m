//
//  ZTViewController.m
//  zawsdk_ios
//
//  Created by Mingsheng Zhang on 06/18/2024.
//  Copyright (c) 2024 Mingsheng Zhang. All rights reserved.
//

#import "ZTViewController.h"
#import <ZAWSDKIOSFramework/ZAWSDK.h>

@interface ZTViewController ()

@end

@implementation ZTViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
}
- (IBAction)delete:(id)sender {
    [[ZAWSDK sharedInstance]deleteAccount];
}

- (IBAction)login:(id)sender {
    [[ZAWSDK sharedInstance]loginFromViewController:self success:^(ZAWLoginModel * _Nonnull loginModel) {
        [[NSUserDefaults standardUserDefaults]setBool:YES forKey:@"hasLogin"];
        NSLog(@"ZAWSDK login:::success:::%@", [loginModel description]);
    } failure:^(NSInteger code, NSString * _Nonnull message) {
        NSLog(@"ZAWSDK login:::failure:::%@", message);
    }];
//    Boolean hasLogin = [[NSUserDefaults standardUserDefaults]boolForKey:@"hasLogin"];
//    if(hasLogin){
//        [[ZAWSDK sharedInstance]loginFromViewController:self success:^(ZAWLoginModel * _Nonnull loginModel) {
//            [[NSUserDefaults standardUserDefaults]setBool:YES forKey:@"hasLogin"];
//            NSLog(@"ZAWSDK login:::success:::%@", [loginModel description]);
//        } failure:^(NSInteger code, NSString * _Nonnull message) {
//            NSLog(@"ZAWSDK login:::failure:::%@", message);
//        }];
//    }else{
//        [[ZAWSDK sharedInstance]quickLoginFromViewController:self success:^(ZAWLoginModel * _Nonnull loginModel) {
//            NSLog(@"ZAWSDK quickLogin:::success:::%@", [loginModel description]);
//        } failure:^(NSInteger code, NSString * _Nonnull message) {
//            NSLog(@"ZAWSDK quickLogin:::failure:::%@", message);
//        }];
//    }
}

- (IBAction)share:(id)sender {
    [[ZAWSDK sharedInstance]shareLinkToFacebook:@"https://www.baidu.com" fromViewController:self];
}

- (IBAction)bind:(id)sender {
    [[ZAWSDK sharedInstance]bindFromViewController:self success:^(ZAWLoginModel * _Nonnull loginModel) {
        NSLog(@"ZAWSDK bind:::success:::%@", [loginModel description]);
    } failure:^(NSInteger code, NSString * _Nonnull message) {
        NSLog(@"ZAWSDK bind:::failure:::%@", message);
    }];
}

- (IBAction)pay:(id)sender {
    NSString* product_id = @"pirate.th.a.0499";
    NSDate *datenow = [NSDate date];
    NSString *orderId = [NSString stringWithFormat:@"%ld", (long)[datenow timeIntervalSince1970]];
    [[ZAWSDK sharedInstance]payFromViewController:self amount:@"1.0" serverId:@"s1" subject:@"goods" subjectId:product_id isTest:0 cpOrderId:orderId extraInfo:@"extra_info" success:^(ZAWPayModel * _Nonnull payModel) {
            NSLog(@"ZAWSDK pay:::success:::%@", [payModel description]);
        } failure:^(NSInteger code, NSString * _Nonnull message) {
            NSLog(@"ZAWSDK pay:::failure:::%@", message);
        }];
}

- (IBAction)quickLogin:(id)sender {
    [[ZAWSDK sharedInstance]quickLoginFromViewController:self success:^(ZAWLoginModel * _Nonnull loginModel) {
        NSLog(@"ZAWSDK quickLogin:::success:::%@", [loginModel description]);
    } failure:^(NSInteger code, NSString * _Nonnull message) {
        NSLog(@"ZAWSDK quickLogin:::failure:::%@", message);
    }];
}

- (IBAction)logout:(id)sender {
    [[ZAWSDK sharedInstance]logoutOnCompletionHandler:^{
        NSLog(@"ZAWSDK logout:::complete:::");
    }];
}

- (IBAction)account:(id)sender {
    [[ZAWSDK sharedInstance]accountFromViewController:self success:^(ZAWLoginModel * _Nonnull loginModel) {
        NSLog(@"ZAWSDK account:::success:::%@", [loginModel description]);
    } failure:^(NSInteger code, NSString * _Nonnull message) {
        NSLog(@"ZAWSDK account:::failure:::%@", message);
    }];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
