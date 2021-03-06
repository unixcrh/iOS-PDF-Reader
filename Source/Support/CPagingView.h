//
//  CMyScrollView.h
//  PDFReader
//
//  Created by Jonathan Wight on 02/19/11.
//  Copyright 2011 toxicsoftware.com. All rights reserved.
//

#import <Foundation/Foundation.h>

// TODO become a UIView with a UIScrollView inside.

@protocol CPagingViewDelegate;
@protocol CPagingViewDataSource;

@interface CPagingView : UIView

@property (readwrite, nonatomic, weak) id <CPagingViewDelegate> delegate;
@property (readwrite, nonatomic, weak) id <CPagingViewDataSource> dataSource;

@property (readonly, nonatomic, assign) NSUInteger currentPageIndex;

@property (readonly, nonatomic, strong) UIView *previousView;
@property (readonly, nonatomic, strong) UIView *currentView;
@property (readonly, nonatomic, strong) UIView *nextView;

- (void)scrollToPageAtIndex:(NSUInteger)inIndex animated:(BOOL)inAnimated;

- (void)scrollToPreviousPageAnimated:(BOOL)inAnimated;
- (void)scrollToNextPageAnimated:(BOOL)inAnimated;

@end

#pragma mark -

@protocol CPagingViewDelegate <NSObject>
@end

@protocol CPagingViewDataSource <NSObject>
- (NSUInteger)numberOfPagesInPagingView:(CPagingView *)inPagingView;
- (UIView *)pagingView:(CPagingView *)inPagingView viewForPageAtIndex:(NSUInteger)inIndex;
@end
