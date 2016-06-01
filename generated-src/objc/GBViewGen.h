// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from ui.djinni

#import "GBViewConstraint.h"
#import "GBViewFrame.h"
#import "GBViewType.h"
#import <Foundation/Foundation.h>
@class GBViewEventHandler;
@protocol GBViewGen;


@protocol GBViewGen

- (nonnull NSString *)getId;

- (void)setFrame:(nonnull GBViewFrame *)frame;

- (nonnull GBViewFrame *)getFrame;

- (void)setBackgroundColor:(float)a
                         r:(float)r
                         g:(float)g
                         b:(float)b;

- (void)setVisiable:(BOOL)v;

- (nullable id<GBViewGen>)getSubView:(nonnull NSString *)id;

- (nullable id<GBViewGen>)addSubView:(nonnull NSString *)id
                                type:(GBViewType)type;

- (BOOL)removeSubView:(nonnull NSString *)id;

- (void)removeAllSubView;

- (void)addConstraint:(nonnull GBViewConstraint *)constraint;

- (void)setEventHandler:(nullable GBViewEventHandler *)handler;

@end
