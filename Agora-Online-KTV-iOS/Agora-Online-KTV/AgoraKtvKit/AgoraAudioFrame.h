//
//  AgoraAudioFrame.hpp
//  AgoraShareVideo
//
//  Created by 湛孝超 on 2018/3/9.
//  Copyright © 2018年 湛孝超. All rights reserved.
//
#import <AgoraRtcKit/AgoraRtcEngineKit.h>

@interface AgoraAudioFrame:NSObject
typedef struct AVideoFrame {
    
    uint8_t *data[8];    ///< pointers to the image data planes
    int linesize[8];   ///< number of bytes per line
} AVideoFrame;

@property (nonatomic, assign) NSInteger eqBindValue1;
@property (nonatomic, assign) NSInteger eqBindValue2;
@property (nonatomic, assign) NSInteger eqBindValue3;
@property (nonatomic, assign) BOOL isAudience;
@property (nonatomic, assign) NSInteger sampleRate;
//调节伴奏音量大小 值的范围0 ~ 1
@property (nonatomic, assign) float songNum;
//调节人声大小
@property (nonatomic, assign) float voiceNum;

+ (instancetype)shareInstance;
- (void)registerEngineKit:(AgoraRtcEngineKit *)rtcEngine;
- (void)pushAudioSource:(void *)data byteLength:(long)bytesLength;
- (void)pushVideoSource:(void *)yuv width:(int)width height:(int)height;
- (BOOL)isHeadsetPluggedIn;
- (void)destroyAudioBuf;
- (void)isOpenAudioEffect;
- (void)destroy;
@end
