//
// Created by GJP on 2020/3/24.
//

#include "IPlayer.h"
#include "IDecode.h"
#include "IDemux.h"
#include "IAudioPlay.h"
#include "IVideoView.h"
#include "IResample.h"
#include "XLog.h"

IPlayer::IPlayer()
{

}

IPlayer *IPlayer::Get(unsigned char index)
{
    static IPlayer p[256];
    return &p[index];
}

bool IPlayer::Open(const char *path)
{
    //解封装
    if(!demux || !demux->Open(path)) {
        XLOGE("demux->Open %s failed!",path);
        return false;
    }
    //解码，解码可能不需要，如果是解封之后就是原始数据
    if(!vdecode || !vdecode->Open(demux->GetVPara(), isHardDecode)) {
        XLOGE("vdecode->Open %s failed",path);
        //return false;
    }
    if(!adecode || !adecode->Open(demux->GetApara())) {
        XLOGE("adecode->Open %s failed",path);
        //return false;
    }
    //重采样 有可能不需要，解码后或者解封后可能是直接能播放的数据
    if(outPara.sample_rate <= 0) {
        outPara = demux->GetApara();
    }
    if(!resample || !resample->Open(demux->GetApara(), outPara)) {
        XLOGE("resample->Open %s failed", path);
    }

    return true;
}
bool IPlayer::Start()
{
    if(!demux || !demux->Start()) {
        XLOGE("demux->Start failed");
    }
    if(adecode) {
        adecode->Start();
    }
    if(audioPlay)
        audioPlay->StartPlay(outPara);
    if(vdecode) {
        vdecode->Start();
        XLOGE("vdecode->Start failed");
    }

    //vdecode->Start();
    //adecode->Start();
    return true;
}

void IPlayer::InitView(void *win) {
    if(videoView) {
        videoView->SetRender(win);
    }
}


