#
# Be sure to run `pod lib lint zawsdk_ios.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'zawsdk_ios'
  s.version          = '0.4.3'
  s.summary          = 'zawsdk for ios'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
zawsdk ios hahahahhahaah
                       DESC

  s.homepage         = 'https://github.com/bigbigbig/zawsdk_ios.git'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'bigbigbig' => '1046724509@qq.com' }
  s.source           = { :git => 'https://github.com/bigbigbig/zawsdk_ios.git', :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  s.platform = :ios, '15.0'
  s.ios.deployment_target = '15.0'

  s.source_files = 'zawsdk_ios/Classes/**/*{h,m}'
   s.resource_bundles = {
     'bundle' => ['zawsdk_ios/Assets/*']
   }

   
#   s.requires_arc = true
#   s.compiler_flags = '-DBORINGSSL_PREFIX=GRPC -Wno-unreachable-code -Wno-shorten-64-to-32'
#   s.pod_target_xcconfig = {
#       'HEADER_SEARCH_PATHS' => '"$(inherited)" "$(PODS_TARGET_SRCROOT)"',
#       'VALID_ARCHS' => 'armv7 arm64',
#       'ONLY_ACTIVE_ARCH' => 'YES',
#       'CLANG_ENABLE_MODULES' => 'YES',
#       'GCC_PREPROCESSOR_DEFINITIONS' => '"$(inherited)" "COCOAPODS=1"',
#       'USE_HEADERMAP' => 'NO',
#       'ALWAYS_SEARCH_USER_PATHS' => 'NO',
#       'CLANG_WARN_STRICT_PROTOTYPES' => 'NO',
#       'CLANG_CXX_LANGUAGE_STANDARD' => 'gnu++0x',
#       'GCC_C_LANGUAGE_STANDARD' => 'gnu99'
#   }
#   s.swift_version = '4.0'
#   s.libraries = 'c++'
   s.static_framework = true
#   s.header_mappings_dir = '.'
   s.public_header_files = 'zawsdk_ios/Classes/**/*.h'
   s.vendored_frameworks = 'zawsdk_ios/Frameworks/ZAWSDKIOSFramework.framework'
   s.frameworks = 'UIKit', 'Foundation'
   s.dependency 'MFSIdentifier', '1.0.2'
   s.dependency 'Adjust', '5.4.0'
   s.dependency 'HBDNavigationBar', '1.9.8'
   s.dependency 'SDWebImage', '5.19.7'
   s.dependency 'Masonry', '1.1.0'
   s.dependency 'YYCategories', '1.0.4'
   s.dependency 'YYModel', '1.0.4'
   s.dependency 'SVProgressHUD', '2.3.1'
   s.dependency 'MZFormSheetPresentationController', '2.4.3'
   s.dependency 'GoogleUtilities', '8.1.0'
   s.dependency 'GoogleSignIn', '9.0.0'
   s.dependency 'FBSDKCoreKit', '18.0.0'
   s.dependency 'FBSDKLoginKit', '18.0.0'
   s.dependency 'FBSDKShareKit', '18.0.0'
   s.dependency 'FirebaseCore', '12.6.0'
   s.dependency 'FirebaseCoreExtension', '12.6.0'
   s.dependency 'FirebaseFirestoreInternal', '12.6.0'
   s.dependency 'FirebaseAnalytics', '12.6.0'
   s.dependency 'FirebaseAuth', '12.6.0'
   s.dependency 'FirebaseFirestore', '12.6.0'
end
