// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from ui.djinni

#import "GBViewFrame.h"


@implementation GBViewFrame

- (nonnull instancetype)initWithX:(int32_t)x
                                y:(int32_t)y
                                w:(int32_t)w
                                h:(int32_t)h
{
    if (self = [super init]) {
        _x = x;
        _y = y;
        _w = w;
        _h = h;
    }
    return self;
}

+ (nonnull instancetype)viewFrameWithX:(int32_t)x
                                     y:(int32_t)y
                                     w:(int32_t)w
                                     h:(int32_t)h
{
    return [[self alloc] initWithX:x
                                 y:y
                                 w:w
                                 h:h];
}

- (NSString *)description
{
    return [NSString stringWithFormat:@"<%@ %p x:%@ y:%@ w:%@ h:%@>", self.class, (void *)self, @(self.x), @(self.y), @(self.w), @(self.h)];
}

@end
