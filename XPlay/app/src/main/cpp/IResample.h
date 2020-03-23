//
// Created by GJP on 2020/3/23.
//

#ifndef XPLAY_IRESAMPLE_H
#define XPLAY_IRESAMPLE_H


#include "IObserver.h"

class IResample : public IObserver{
public:
    virtual bool Open() = 0;
};


#endif //XPLAY_IRESAMPLE_H
