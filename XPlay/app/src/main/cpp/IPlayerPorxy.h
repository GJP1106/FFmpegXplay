//
// Created by GJP on 2020/3/26.
//

#ifndef XPLAY_IPLAYERPORXY_H
#define XPLAY_IPLAYERPORXY_H

#include <mutex>
#include "IPlayer.h"

class IPlayerPorxy : public IPlayer{
public:
    static IPlayerPorxy *Get()
    {
        static IPlayerPorxy px;
        return &px;
    }
    void Init(void *vm = 0);

    virtual bool Open(const char *path);
    virtual bool Seek(double pos);
    virtual void SetPause(bool isP);
    virtual void Close();
    virtual bool Start();
    virtual void InitView(void *win);

    virtual bool IsPause();

    //获取当前的播放进度0.0 -- 1.0
    virtual double PlayPos();

protected:
    IPlayerPorxy() {}
    IPlayer *player = 0;
    std::mutex mux;
};


#endif //XPLAY_IPLAYERPORXY_H
