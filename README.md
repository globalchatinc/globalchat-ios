# Globalchat SDK
### Open Source Messaging framework for iOS


Globalchat SDK is a fully featured open source instant messaging framework for iOS. Globalchat SDK is fully featured, scalable and flexible and follows the following key principles:

- **Open Source.** The Globalchat SDK is open source and free for commerical apps
- **Full data control.** You have full and exclusive access to the user's chat data
- **Quick integration.** Globalchat SDK is fully featured out of the box

<!--A demo of the project is available on the App Store.  

-->
## Features

- Private and group messages
- Public chat rooms
- Username / password, Facebook, Twitter, Anonymous and custom login
- Text, Image and Location messages
- User profiles
- User search

## Help spread the word
Globalchat SDK is free and open source. If you like the project help us spread the word by:

+ Giving us a Github star ⭐


## Get involved!

We're very excited about the project and we're looking for other people to get involved. Over time we would like to make the best messaging framework for mobile. Helping us could involve any of the following:

+ Providing feedback and feature requests
+ Reporting bugs
+ Fixing bugs
+ Writing documentation
+ Improving the user interface
+ Help us update the library to use Swift
+ Helping to write adapters for other services such as Layer, Pusher, Pubnub etc... 


If you're interested please review the [Contributing


## Apps that use Globalchat SDK

Here are the apps we know about that are using Globalchat SDK. If you've relased an app that uses the framework let us know and we'll add it to the list:


## Setup Service and consulting

##### Setup Service

We provide extensive documentation on Github but if you’re a non-technical user or want to save yourself some work you can take advantage of our

##### Consulting services

We are specialists in real-time application development including: Firebase, Firestore, XMPP and WebRTC for iOS and Android. If you need help integrating the Globalchat SDK with your app or another app development project email us at  

## Running the demo project
This repository contains a fully functional version of the Chat SDK which is configured using our Firebase account and social media logins. This is great way to test the features of the Chat SDK before you start itegrating it with your app. 

1. Clone Globalchat SDK  
2. Run `pod install` in the **Xcode** directory  
3. Open the `Globalchat SDK Firebase.xcworkspace` file in Xcode  
4. Compile and run

## Swift Version
The Globalchat SDK is fully compatible with Swift projects and contains a Swift demo project. 

1. Clone Globalchat SDK  
2. Run `pod install` in the **XcodeSwift** directory  
3. Open the `ChatSDKSwift.xcworkspace` file in Xcode  
4. Compile and run 

## Adding the Globalchat SDK to your project
###### Quick start guide - it takes about 10 minutes!

### Adding the Globalchat SDK to your project

1. Add the Globalchat SDK development pods to your Podfile

  ```
  use_frameworks!
  pod "ChatSDK"
  pod "ChatSDK/FirebaseAdapter"
  pod "ChatSDK/FirebaseFileStorage"
  pod "ChatSDK/FirebasePush"
  
  // Optional - for social login (see setup guide below)
  
  pod "ChatSDK/FirebaseSocialLogin"
  ```
  
2. Run `pod update` to get the latest version of the code.

3. Open the **App Delegate** add the following code to initialise the chat

  **Objective C**

  _AppDelegate.m -> application: didFinishLaunchingWithOptions:_
  
  ```
  #import <ChatSDK/UI.h>
  ```

  Add the following code to the start of your didFinishLaunchingWithOptions function:

  ```
  BConfiguration * config = [BConfiguration configuration];
  config.rootPath = @"test";
  // Configure other options here...
  
  [BChatSDK initialize:config app:application options:launchOptions];

  // Set the root view controller
  [self.window setRootViewController:[BInterfaceManager sharedManager].a.appTabBarViewController];
  ```
  
  Then add the following methods:
  
  ```
  - (BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation {
      return [BChatSDK application:application openURL:url sourceApplication:sourceApplication annotation:annotation];
  }
	
  -(BOOL) application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<UIApplicationOpenURLOptionsKey,id> *)options {
      return [BChatSDK application: app openURL: url options: options];
  }
	
  -(void) application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken {
      [BChatSDK application:application didRegisterForRemoteNotificationsWithDeviceToken:deviceToken];
  }
	
  -(void) application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo {
      [BChatSDK application:application didReceiveRemoteNotification:userInfo];
  }
  ```
  
  **Swift**
  
  _AppDelegate.swift_
  
  ```
  import ChatSDK
  ```
  
  Add the following code to the start of your didFinishLaunchingWithOptions function:

  ```
  let config = BConfiguration.init();
  config.rootPath! = "test"
  // Configure other options here...
  
  config.allowUsersToCreatePublicChats = true
  BChatSDK.initialize(config, app: application, options: launchOptions)
        
  self.window = UIWindow.init(frame: UIScreen.main.bounds)
  self.window?.rootViewController = BInterfaceManager.shared().a.appTabBarViewController();
  self.window?.makeKeyAndVisible();
  ```
  
  Then add the following methods:
  
  ```
    func application(_ application: UIApplication, didRegisterForRemoteNotificationsWithDeviceToken deviceToken: Data) {
        BChatSDK.application(application, didRegisterForRemoteNotificationsWithDeviceToken: deviceToken)
    }
    
    func application(_ application: UIApplication, didReceiveRemoteNotification userInfo: [AnyHashable : Any], fetchCompletionHandler completionHandler: @escaping (UIBackgroundFetchResult) -> Void) {
        BChatSDK.application(application, didReceiveRemoteNotification: userInfo)
    }
    
    func application(_ application: UIApplication, didReceiveRemoteNotification userInfo: [AnyHashable: Any]) {
        BChatSDK.application(application, didReceiveRemoteNotification: userInfo)
    }
    
    func application(_ application: UIApplication, open url: URL, sourceApplication: String?, annotation: Any) -> Bool {
        return BChatSDK.application(application, open: url, sourceApplication: sourceApplication, annotation: annotation)
    }
    
    func application(_ app: UIApplication, open url: URL, options: [UIApplicationOpenURLOptionsKey : Any] = [:]) -> Bool {
        return BChatSDK.application(app, open: url, options: options)
    }
  ```
  
  ##### The Root Path

  >The root path variable allows you to run multiple Chat SDK instances on one Firebase account. Each different root path will represent a completely separate set of Firebase data. This can be useful for testing because you could have separate **test** and **prod** root paths.
      
4. The Chat SDK is now added to your project


