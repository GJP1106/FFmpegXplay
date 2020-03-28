//
// Created by GJP on 2020/3/26.
//

#include "IPlayerPorxy.h"
#include "FFPlayerBuilder.h"

void IPlayerPorxy::Close() {
    mux.lock();
    if(player) {
        player->Close();
    }
    mux.unlock();
}

void IPlayerPorxy::Init(void *vm)
{
    mux.lock();
    if(vm)
    {
        FFPlayerBuilder::InitHard(vm);
    }
    if(!player) {
        player = FFPlayerBuilder::Get()->BuilderPlayer();
    }
    mux.unlock();
}

//获取当前的播放进度0.0 -- 1.0
double IPlayerPorxy::PlayPos()
{
    double pos = 0.0;
    mux.lock();
    if(player) {
        pos = player->PlayPos();
    }
    mux.unlock();
    return pos;
}

bool IPlayerPorxy::Seek(double pos)
{
    bool re = false;
    mux.lock();
    if(player) {
        re = player->Seek(pos);
    }
    mux.unlock();
    return re;
}

bool IPlayerPorxy::Open(const char *path)
{
    bool re = false;
    mux.lock();
    if(player) {
        player->isHardDecode = isHardDecode;
        re = player->Open(path);
    }
    mux.unlock();
    return re;
}
bool IPlayerPorxy::Start()
{
    bool re;
    mux.lock();
    if(player) {
        re = player->Start();
    }
    mux.unlock();
    return re;
}
void IPlayerPorxy::InitView(void *win)
{
    mux.lock();
    if(player) {
        player->InitView(win);
    }
    mux.unlock();
}