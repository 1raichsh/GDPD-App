//
//  FeedConfig.h
//  RssFeedLib
//
//  Created by Andrey Andreev on 5/4/10.
//  Copyright 2010 EastBanc Technologies. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIColor.h>

/**
   Stores feed parameters such as title, feed's url and image url
*/
@interface MSMFeedConfig : NSObject {
}

@property (nonatomic, strong) NSString * title;
//DE109516; fix rss title issue by adding a new property.
//Header setText and download complete and parse news title has different sequence when first open and reopen same rss reader.
//use title for web set title and parsedTitle for rss parsed news title.
@property (nonatomic, strong) NSString * parsedTitle;
@property (nonatomic, strong) NSString * url;
@property (nonatomic, strong) NSString * imageUrl;
@property (nonatomic) BOOL titleOverriden;

-(id) initWithTitle:(NSString *)t url:(NSString *)u image:(NSString *)img isOverriden:(BOOL) over;

@end
