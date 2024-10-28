//
//  main.m
//  zawsdk_ios
//
//  Created by Mingsheng Zhang on 06/18/2024.
//  Copyright (c) 2024 Mingsheng Zhang. All rights reserved.
//

@import UIKit;
#import "ZTAppDelegate.h"

int main(int argc, char * argv[])
{
    @autoreleasepool {
        // 获取当前语言环境
        NSLocale *currentLocale = [NSLocale currentLocale];
        
        // 获取语言代码
        NSString *languageCode = [currentLocale objectForKey:NSLocaleLanguageCode];
        
        // 打印语言代码
        NSLog(@"当前语言的langcode是: %@", languageCode);
        return UIApplicationMain(argc, argv, nil, NSStringFromClass([ZTAppDelegate class]));
    }
}
