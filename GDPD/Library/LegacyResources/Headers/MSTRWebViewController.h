//
//  MSTRWebViewController.h
//  MSTRMobileSDK
//
//  Created by Amirali Charania on 12/7/10.
//  Copyright 2010 MicroStrategy. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MSIGeneric.h"
#import "MSTRNavigationBarController.h"
#import <WebKit/WebKit.h>

@class MSTRWebViewController;
@class MSIURLSessionManager;

@protocol WebViewControllerDelegate

- (void)dismissedWebViewController:(MSTRWebViewController*)webViewController;

@end

typedef void (^ViewControllerCompletionHandler)(void);

@interface MSTRWebViewController : UIViewController<MSTRNavigationBarButtonItemsFactory> {
	WKWebView* webView;
	NSURL* url;

	UIActivityIndicatorView* loadingIndicator;
	id<WebViewControllerDelegate> __weak delegate;
	
    ThemeType themeType;
    MSTRNavigationBarController* mstrNavigationBarController;
    @private
    UIBarButtonItem* backBarButtonItem;
	UIBarButtonItem* forwardBarButtonItem;
	UIBarButtonItem* closeBarButtonItem;
	UIBarButtonItem* dividerBarButtonItem;
    UIBarButtonItem* loadingBarButtonItem;
    NSURLRequest *originalRequest;
//    MSIURLSessionManager *viewSessionManager;
}

- (id)initWithURL:(NSURL*)url;
@property (nonatomic, strong) UIBarButtonItem* backBarButtonItem;
@property (nonatomic, strong) UIBarButtonItem* forwardBarButtonItem;
@property (nonatomic, strong) UIBarButtonItem* closeBarButtonItem;
@property (nonatomic, strong) UIBarButtonItem* dividerBarButtonItem;
@property (nonatomic, weak) id<WebViewControllerDelegate> delegate;
@property (nonatomic) ThemeType themeType;
@property (nonatomic, strong) NSMutableDictionary *credentialDict;
@property (nonatomic, strong) NSString *currentURL;
@property (nonatomic, strong) ViewControllerCompletionHandler completionHandler;
@end
