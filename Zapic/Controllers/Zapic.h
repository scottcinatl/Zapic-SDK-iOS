@import UIKit;
#import "ZPlayer.h"

@interface Zapic : NSObject

/**
 The current Zapic player.
 */
@property (class, readonly) ZPlayer *player;

/**
 The handler when a player logs in to Zapic.
 */
@property (class, nonatomic, copy, nullable) void (^loginHandler)(ZPlayer *);

/**
 The handler when a player logs out of Zapic.
 */
@property (class, nonatomic, copy, nullable) void (^logoutHandler)(ZPlayer *);

/**
 Starts Zapic.
 @discussion This should be called once from the AppDelegate.
 Subsequent calls to this method will be ignored.
 */
+ (void)start;

/**
 Shows the specific Zapic UI page. Please check with https://www.zapic.com/docs
 for a complete listing of the available pages.

 @param pageName The page to display.
 */
+ (void)showPage:(NSString *)pageName;

/**
 Show the default Zapic UI page. This should be called
 from the Z button on your main menu.
 */
+ (void)showDefaultPage;

/**
 Handles an interaction event. Depending on the event parameters, Zapic may open and show
 contextual information related to the specific interaction.

 @param data Dictionary that that contains a "zapic" key.
 */
+ (void)handleInteraction:(NSDictionary *)data;

/**
 Handles an interaction event. Depending on the event parameters, Zapic may open and show
 contextual information related to the specific interaction.

 @param json JSON string that contains a "zapic" key
 */
+ (void)handleInteractionString:(NSString *)json;

/**
 Handles a gameplay event with 1-N parameters.

 @param parameters Parameters
 */
+ (void)submitEvent:(NSDictionary *)parameters;

/**
 Called from the AppDelegate's application:didFinishingLaunchingWithOptions: method
 @note This will be called automatically via the Zapic swizzle
 
 @param launchOptions The launch options.
 */
+ (void)didFinishLaunchingWithOptions:(NSDictionary *)launchOptions;

/**
 Called from the AppDelegate's application:continueUserActivity: method
 @note This will be called automatically via the Zapic swizzle.

 @param userActivity <#userActivity description#>
 */
+ (void)continueUserActivity:(NSUserActivity *)userActivity;

/**
 Called from the AppDelegate's didReceiveRemoteNotification:

 @param userInfo The user information.
 */
+ (void)didReceiveRemoteNotification:(NSDictionary *)userInfo;

/**
  Called from the AppDelegate's application:openUrl:options method
  @note This will be called automatically via the Zapic swizzle

  @param url The URL that was opened.
  @param options The user options.
  */
+ (void)openURL:(NSURL *)url options:(NSDictionary<UIApplicationOpenURLOptionsKey, id> *)options;

/**
 Called from the AppDelegate's application:didRegisterForRemoteNotificationsWithDeviceToken:
 @note This will be called automatically via the Zapic swizzle
 
 @param deviceToken The current device token
 */
+ (void)didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken;

/**
 Called from the AppDelegate's application:didFailToRegisterForRemoteNotificationsWithError:
 @note This will be called automatically via the Zapic swizzle

 @param error The registration error
 */
+ (void)didFailToRegisterForRemoteNotificationsWithError:(NSError *)error;

@end
