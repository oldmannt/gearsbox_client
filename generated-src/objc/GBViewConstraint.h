// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from ui.djinni

#import "GBConstraintType.h"
#import <Foundation/Foundation.h>

@interface GBViewConstraint : NSObject
- (nonnull instancetype)initWithType:(GBConstraintType)type
                              typeTo:(GBConstraintType)typeTo
                            viewFrom:(nonnull NSString *)viewFrom
                              viewTo:(nonnull NSString *)viewTo
                          multiplier:(float)multiplier
                              offset:(float)offset;
+ (nonnull instancetype)viewConstraintWithType:(GBConstraintType)type
                                        typeTo:(GBConstraintType)typeTo
                                      viewFrom:(nonnull NSString *)viewFrom
                                        viewTo:(nonnull NSString *)viewTo
                                    multiplier:(float)multiplier
                                        offset:(float)offset;

@property (nonatomic, readonly) GBConstraintType type;

@property (nonatomic, readonly) GBConstraintType typeTo;

@property (nonatomic, readonly, nonnull) NSString * viewFrom;

@property (nonatomic, readonly, nonnull) NSString * viewTo;

@property (nonatomic, readonly) float multiplier;

@property (nonatomic, readonly) float offset;

@end

extern NSString * __nonnull const GBViewConstraintParent;
